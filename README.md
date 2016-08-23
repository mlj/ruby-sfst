# ruby-sfst

`ruby-sfst` is a wrapper for the Stuttgart Finite State Transducer Tools
(SFST).

The wrapper is based on SFST 1.4.7c. See
http://www.cis.uni-muenchen.de/~schmid/tools/SFST/ for details on how to obtain
SFST and how to write SFST transducers.

## Installation

```sh
gem install ruby-sfst
```

## Usage

If you have the following compiled as `test.a`

    ALPHABET = [a-z]
    $test$ = ({bar}:{foo} | {baz}:{foo})
    $test$

it can be used like this:

```ruby
fst = SFST::RegularTransducer.new("test.a")
fst.analyse('foo')
# => ['bar', 'baz']
fst.accepted_analysis?('foo')
# => true
fst.generate('bar')
# => ['foo']
fst.accepted_generating?('bar')
# => true
fst.generate_language { |f| p f }
# [["b", "f"], ["a", "o"], ["z", "o"]]
# [["b", "f"], ["a", "o"], ["r", "o"]]
```

You can also compile an SFST file. This requires the SFST tools to be installed
and available on the current search path.

```ruby
SFST::compile("test.fst", "test.a", :compact => true)
```

Currently, `ruby-sfst` only supports simple compilation, analysis and
generation using regular and compact transducers. It also only supports UTF-8.

## Development

The project is hosted on github on http://github.com/mlj/ruby-sfst.

## License

As `ruby-sfst` includes parts of the SFST code, the wrapper inherits the GPL2
license of the SFST project.
