
/*******************************************************************/
/*                                                                 */
/*  FILE     hopcroft.C                                            */
/*  MODULE   hopcroft                                              */
/*  PROGRAM  SFST                                                  */
/*  AUTHOR   Helmut Schmid, IMS, University of Stuttgart           */
/*                                                                 */
/*******************************************************************/

#include "fst.h"

// #define TEST1

// HFST
namespace SFST
{

  /*****************  class Transition  ******************************/

  class Transition {
    
    // the representation of a transition used here
    
  public:
    size_t source;
    Label label;
    size_t target;
    
  Transition( size_t s, Label l, size_t t ) : source(s), label(l), target(t) {};
    
    bool operator==( const Transition &t ) const { 
      return t.source == source && t.label == label && t.target == target;
    }
    
    bool operator<( const Transition &t ) const { 
      if (target < t.target) return true;
      if (target > t.target) return false;
      if (label < t.label)   return true;
      if (label > t.label)   return false;
      if (source < t.source) return true;
      return false;
    }
  };


  /*****************  class TransitionTable  *************************/

  // TransitionTable quickly retrieves the transitions to a given state

  class TransitionTable {
    
    // transducer representation used here

  public:
    NodeNumbering nodenumbering;  // maps node pointers to IDs and vice versa
    vector<Transition> transition;
    vector<size_t> startpos;      // position of the first transition
                                  // with a given target state
    
    TransitionTable( Transducer &t ) : nodenumbering(t)
    {
      t.build_transtab( transition, nodenumbering );
      std::sort( transition.begin(), transition.end() );
      size_t previous_state = 0;

      // build the startpos array

      startpos.push_back(0);
      for( size_t i=0; i<transition.size(); i++ )
	if (transition[i].target != previous_state)
	  while (startpos.size() <= transition[i].target)
	    startpos.push_back(i);
      startpos.push_back( transition.size() );
    }
    
  };

  /*************  class PosRange  **********************************/

  class PosRange {

    // position of the first and last+1 element of a state set

  public:
    size_t from,to;
    PosRange( size_t f, size_t t ) : from(f), to(t) {};
    size_t size() { return to - from; }
  };


  /*************  class Stack  *************************************/

  class Stack {

    // stores the IDs of the state sets on the to-do list

  private:
    vector<size_t> setID;  // list of stored IDs needed for LIFO retrieval
    set<size_t> store;  // data structure needed for quick lookup of an item

  public:
    void push( size_t id ) {
      if (store.find(id) == store.end()) {
	setID.push_back( id );
	store.insert(id);
      }
    }

    bool is_empty() { return setID.size() == 0; }

    size_t pop(void) {
      size_t result = setID.back();
      setID.pop_back();
      store.erase(result);
      return result;
    }

    bool contains( size_t id ) {
      return store.find(id) != store.end();
    }
  };


  /*************  class Minimiser  *********************************/

  // table which maps labels to sets of source states
  typedef map<Label,set<size_t> > Label2SState;

  class Minimiser {

    // main class of the minimisation algorithm

    Transducer &transducer;   // reference to the original transducer

    TransitionTable transtab; // internal transducer representation

    vector<size_t> partition; // state partition table
    // states from the same set occur next to each other in the table

    vector<PosRange> posrange; // start+end positions of sets in "partition"
    vector<size_t> state2set;  // maps states to state sets
    Stack stack;               // stack of split states (to-do list)

    void print_partition( FILE *file ) {
      for( size_t i=0; i<posrange.size(); i++ ) {
	fprintf(file,"set[%lu] =", (unsigned long)i);
	for( size_t k=posrange[i].from; k<posrange[i].to; k++ )
	  fprintf(file," %lu", (unsigned long)partition[k]);
	fputc('\n', file);
      }
    }

  public:
    Minimiser( Transducer &t ); // initialises the minimiser
    Transducer &result();       // does the minimisation and returns the result
    void compute_source_states( Label2SState&, PosRange ); // computes for each
    // label l the set of source states with an "l" transition to a state
    // in the current split state set
    void split( size_t B, vector<size_t> &T1, size_t C ); // splits a state set 
    // by the state set given in "T1". 
  };
 

  /*******************************************************************/
  /*                                                                 */
  /*  Minimiser::Minimiser                                           */
  /*                                                                 */
  /*******************************************************************/

  Minimiser::Minimiser( Transducer &t )
    : transducer(t), transtab(t)
  {

    // compute the set of final (B1) and non-final (B2) states

    vector<size_t> B1, B2;
    for( size_t i=0; i<transtab.nodenumbering.number_of_nodes(); i++ )
      if (transtab.nodenumbering.get_node(i)->is_final()) 
	B1.push_back(i);
      else
	B2.push_back(i);

    // build the initial partition of states

    state2set.resize( transtab.nodenumbering.number_of_nodes() );
    size_t n=0;
    if (B1.size() > 0) {
      for( size_t i=0; i<B1.size(); i++ ) {
	partition.push_back(B1[i]);
	state2set[B1[i]] = n;
      }
      posrange.push_back( PosRange(0, partition.size() ) );
      n++;
    }

    size_t pos = partition.size();
    if (B2.size() > 0) {
      for( size_t i=0; i<B2.size(); i++ ) {
	partition.push_back(B2[i]);
	state2set[B2[i]] = n;
      }
      posrange.push_back( PosRange(pos, partition.size() ) );
    }
  }


  /*******************************************************************/
  /*                                                                 */
  /*  Minimiser::compute_source_states                               */
  /*                                                                 */
  /*  compute the backward transitions from states in the split set  */
  /*                                                                 */
  /*******************************************************************/

  void Minimiser::compute_source_states( Label2SState &l2ss, PosRange r )

  {
    // This function computes for each label l the set of source states
    // with a transition to one of the states in the split set which is 
    // labelled with l

    // for all states in B
    for( size_t i=r.from; i<r.to; i++ ) {
      size_t s = partition[i];

      // for all transition into state B
      for( size_t k=transtab.startpos[s]; k<transtab.startpos[s+1]; k++ ) {
	Transition &t = transtab.transition[k];
	// most expensive code line follows here !!!
	l2ss[t.label].insert(t.source);
      }
    }
  }


  /*******************************************************************/
  /*                                                                 */
  /*  Minimiser::split                                               */
  /*                                                                 */
  /*******************************************************************/

  void Minimiser::split( size_t B, vector<size_t> &T1, size_t C )

  {
    // splits a state set by intersection with the state set "T1"

    // get the position range of the states in the "partition" table
    PosRange r = posrange[B];
    if (r.size() == 1)
      return;

    vector<size_t> B1_set, B2_set;

#ifdef TEST
    fprintf(stderr,"\nsplit %lu with", B);
    for( size_t i=0; i<T1.size(); i++ )
      fprintf(stderr," %lu", T1[i]);
    fputc('\n', stderr);
#endif

    // compute the intersection and the difference of the two sets
    size_t k=0;
    size_t i=r.from;
    while (i < r.to) {
      if (k == T1.size() || partition[i] < T1[k])
	// state is not in the intersection
	B2_set.push_back(partition[i++]);
      else if (partition[i] == T1[k]) {
	// state is in the intersection
	B1_set.push_back(partition[i++]);
	k++;
      }
      else
	k++;
    }
#ifdef TEST
    fprintf(stderr,"B1 = ");
    for( size_t i=0; i<B1_set.size(); i++ )
      fprintf(stderr," %lu", B1_set[i]);
    fputc('\n', stderr);
    fprintf(stderr,"B2 = ");
    for( size_t i=0; i<B2_set.size(); i++ )
      fprintf(stderr," %lu", B2_set[i]);
    fputc('\n', stderr);
#endif

    if (B2_set.size() == 0)
      return;

    // split the set in "partition"
    
    // copy the first subset to partition
    k = r.from;
    for( size_t i=0; i<B1_set.size(); i++ )
      partition[k++] = B1_set[i];
    // update the end position of the reduced state set
    posrange[B].to = k;
    
    // copy the second subset to partition
    size_t new_B = posrange.size();
    posrange.push_back( PosRange(k, k+B2_set.size()) );
    for( size_t i=0; i<B2_set.size(); i++ ) {
      state2set[B2_set[i]] = new_B;
      partition[k++] = B2_set[i];
    }
    
    // add the new set to the set of split states
    if (B == C) {
      stack.push( B );
      stack.push( new_B );
    }
    else if (stack.contains(B))
      stack.push( new_B );
    else if (B1_set.size() > B2_set.size())
      stack.push( new_B );
    else
      stack.push( B );
    
#ifdef TEST
    fprintf(stderr,"\nnew partition:\n");
    print_partition( stderr );
#endif
    return;
  }



  /*******************************************************************/
  /*                                                                 */
  /*  Minimiser::result                                              */
  /*                                                                 */
  /*******************************************************************/

  Transducer &Minimiser::result()

  {
    if (transtab.nodenumbering.number_of_nodes() == 1)
      return transducer.copy();  // no need for a minimisation

    // initialise the stack of split sets
    if (posrange.size() == 2) {
      // there are both, final and non-final states
      // put the larger one first on the stack
      if (posrange[0].to-posrange[0].from > posrange[1].to-posrange[1].from) {
	stack.push( 0 );
	stack.push( 1 );
      }
      else {
	stack.push( 1 );
	stack.push( 0 );
      }
    }
    else 
      stack.push( 0 );


#ifdef TEST
    fprintf(stderr,"\nPartition:\n");
    print_partition( stderr );
#endif

    // repeat until the stack is empty
    while (!stack.is_empty()) {
      size_t C = stack.pop();  // next state set on which the others are split

      // compute for each label l the set of source states with a transition 
      // to one of the states in the split set which is labelled with l
      Label2SState l2ss;
      compute_source_states( l2ss, posrange[C] );

      // loop over the labels
      for( Label2SState::iterator it=l2ss.begin(); it!= l2ss.end(); it++ ) {
	set<size_t> &X = it->second;
	
	// copy the set of source states to a sorted vector
	vector<size_t> T1;
	T1.reserve(X.size());
	for( set<size_t>::iterator it=X.begin(); it!=X.end(); it++ )
	  T1.push_back(*it);
	
	// find the relevant source state sets
	map<size_t,size_t> source_set_counts;
	for( size_t i=0; i<T1.size(); i++ ) {
	  size_t ss = state2set[T1[i]];
	  map<size_t,size_t>::iterator it = source_set_counts.find( ss );
	  if (it == source_set_counts.end())
	    source_set_counts[ ss ] = 1;
	  else
	    it->second++;
	}

	// loop over the source state sets
	for( map<size_t,size_t>::iterator it=source_set_counts.begin(); 
	     it!=source_set_counts.end(); it++ )
	  {
	    size_t B = it->first;
	    // do not try to split sets with just 1 element
	    //if (posrange[B].to - posrange[B].from < it->second)
	    if (posrange[B].to - posrange[B].from > it->second)
	      split( B, T1, C );
	  }
      }
    }
    
#ifdef TEST
    fprintf(stderr,"\nPartition:\n");
    print_partition( stderr );
#endif

    return *new Transducer( transducer, state2set, transtab.nodenumbering, 
			    posrange.size() );
  }



  /*******************************************************************/
  /*                                                                 */
  /*  Transducer::build_TT                                           */
  /*                                                                 */
  /*******************************************************************/

  void Transducer::build_TT( Node *node, vector<Transition> &transtab,
			     NodeNumbering &nn )
  {
    if (!node->was_visited( vmark )) {
      size_t sourceID = nn[node];
      for( ArcsIter p(node->arcs()); p; p++ ) {
	Arc *arc=p;
	build_TT( arc->target_node(), transtab, nn );
	size_t targetID = nn[arc->target_node()];
	transtab.push_back( Transition( sourceID, arc->label(), targetID ) );
      }
    }
  }


  /*******************************************************************/
  /*                                                                 */
  /*  Transducer::build_transtab                                     */
  /*                                                                 */
  /*******************************************************************/

  void Transducer::build_transtab( vector<Transition> &tt, NodeNumbering &nn )

  {
    incr_vmark();
    build_TT( root_node(), tt, nn );
  }


  /*******************************************************************/
  /*                                                                 */
  /*  Transducer::Transducer                                         */
  /*                                                                 */
  /*  builds the result transducer after minimisation                */
  /*                                                                 */
  /*******************************************************************/

  Transducer::Transducer( Transducer &t, vector<size_t> &state2set, 
			  NodeNumbering &nn, size_t num_of_new_nodes )
  {
    vmark = 0;
    deterministic = minimised = true;
    alphabet.copy(t.alphabet);

    // Choose a representative for each state set
    vector<Node*> representative( num_of_new_nodes );
    for( size_t i=0; i<state2set.size(); i++ )
      representative[state2set[i]] = nn.get_node(i);

    // Create the new nodes
    vector<Node*> node(num_of_new_nodes, NULL);
    // define the root node
    node[state2set[0]] = root_node();
    for( size_t i=0; i<node.size(); i++ )
      if (node[i] == NULL)
	node[i] = new_node();

    // Add the transitions
    for( size_t i=0; i<node.size(); i++ ) {
      Node *old_node = representative[i];
      Node *new_node = node[i];
      new_node->set_final( old_node->is_final() );

      for( ArcsIter p(old_node->arcs()); p; p++ ) {
	Arc *arc=p;
	// Compute the target node: Map the node to its index, 
	// the index to its set, and the set to the new node
	Node *target = node[state2set[nn[arc->target_node()]]];
	// Insert the transition
	new_node->add_arc( arc->label(), target, this );
#ifdef TEST
	fprintf(stderr,"arc: %lu -%s-> %lu\n", i, 
		alphabet.write_label(arc->label()), 
		state2set[nn[arc->target_node()]]);
#endif
      }
    }
  }


  /*******************************************************************/
  /*                                                                 */
  /*  Transducer::minimise                                           */
  /*                                                                 */
  /*******************************************************************/

  Transducer &Transducer::hopcroft_minimise( bool verbose )

  {
    if (minimised)
      return copy();

    Transducer *a1 = &reverse();
    Transducer *a2 = &a1->reverse();
    delete a1;
    a1 = &a2->determinise();
    delete a2;

    Transducer *result = &Minimiser( *a1 ).result();
    delete a1;

    result->minimised = true;
    result->minimise_alphabet();

    return *result;
  }
}
