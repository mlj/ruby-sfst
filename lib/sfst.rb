#!/usr/bin/env ruby
#
# sfst.rb - SFST interface
#
# Written by Marius L. Jøhndal, 2008.
#
require 'sfst_machine'

module SFST
  # Compiles an SFST transducer +source+ and saves it as +machine+.
  #
  # ==== Options
  # compact:: Compile a compact transducer.
  def self.compile(source, machine, options = {})
    unless options[:compact]
      _compile_regular(source, machine)
    else
      _compile_compact(source, machine)
    end
  end

  # A regular, i.e. not a compact, transducer.
  class RegularTransducer
    def initialize(file)
      @fst = RegularTransducerMachine.new(file)
    end

    # Analyses a string +string+. Returns an array of analysed
    # strings if the string is accepted, or an empty array if not.
    #
    # ==== Options
    # * +symbol_sequence+ - Return each analysis as a sequence of symbols.
    #   Multicharacter symbols will be strings on the form +<symbol>+.
    def analyze(string, options = {})
      x = []
      @fst._analyze(string) do |a| 
        if options[:symbol_sequence]
          x << a.map { |s| s.match(/^<(.*)>$/) ? $1.to_sym : s }
        else
          x << a.join
        end
      end
      x
    end

    # Checks if the string +string+ is accepted for analysis.
    def accepted_analysis?(string)
      @fst._analyze(string)
    end

    # Generates a string +string+. Returns an array of generated
    # strings if the string is accepted or an empty array if not.
    def generate(string)
      x = []
      @fst._generate(string) { |a| x << a.join }
      x
    end

    # Checks if the string +string+ is accepted for generating.
    def accepted_generating?(string)
      @fst._generate(string)
    end

    # Generates upper or lower level or both. This only works with
    # non-compact transducers.
    #
    # ==== Options
    # * +levels+ - if <tt>:upper</tt>, generates only upper level. If <tt>:lower</tt> generates 
    #   only lower level. If <tt>:both</tt>, generates both. Default is <tt>:both</tt>.
    # * +epsilons+ - if +true+, produces epsilons. Default is +false+.
    def generate_language(options = {}, &block)
      @fst._generate_language(options[:levels] || :both, options[:epsilons] ? :all : :noepsilons, &block)
    end

    alias :analyse :analyze
  end

  # A compact transducer.
  class CompactTransducer < CompactTransducerMachine
    def initialize(file)
      @fst = CompactTransducerMachine.new(file)
    end

    # Checks if the string +string+ is accepted for analysis.
    def accepted_analysis?(string)
      @fst._analyze(string)
    end

    # Analyses a string +string+. Returns an array of analysed
    # strings if the string is accepted or an empty array if not.
    def analyze(form)
      x = []
      @fst._analyze(form) { |a| x << a }
      x
    end

    alias :analyse :analyze
  end
end
