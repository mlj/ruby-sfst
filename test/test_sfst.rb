require 'sfst'
require 'test/unit'

TEST_DIRECTORY = File.expand_path(File.dirname(__FILE__))
TEST_SCRIPT_FILE = File.join(TEST_DIRECTORY, 'test_sfst.fst')
TEST_COMPILED_FILE = File.join(TEST_DIRECTORY, 'test_sfst.a')
TEST_COMPILED_COMPACT_FILE = File.join(TEST_DIRECTORY, 'test_sfst_compact.a')
TEST_COMPILED_REGULAR_FILE = File.join(TEST_DIRECTORY, 'test_sfst_regular.a')

class SFSTTestCase < Test::Unit::TestCase
  def test_sfst_compile_regular
    SFST::compile(TEST_SCRIPT_FILE, TEST_COMPILED_FILE)
    SFST::compile(TEST_SCRIPT_FILE, TEST_COMPILED_FILE, :compact => false)
  end

  def test_sfst_compile_compact
    SFST::compile(TEST_SCRIPT_FILE, TEST_COMPILED_FILE, :compact => true)
  end
end

class RegularTransducerTestCase < Test::Unit::TestCase
  def setup
    SFST::compile(TEST_SCRIPT_FILE, TEST_COMPILED_REGULAR_FILE, :compact => false)
  end

  def test_analyze_acceptance
    fst = SFST::RegularTransducer.new(TEST_COMPILED_REGULAR_FILE)
    assert_equal true, fst.accepted_analysis?('foo')
    assert_equal false, fst.accepted_analysis?('fox')
  end

  def test_analyze
    fst = SFST::RegularTransducer.new(TEST_COMPILED_REGULAR_FILE)
    assert_equal ['bar', 'baz'], fst.analyse('foo').sort

    fst = SFST::RegularTransducer.new(TEST_COMPILED_REGULAR_FILE)
    assert_equal [], fst.analyse('fox').sort
  end

  def test_analyze_symbol_sequence
    fst = SFST::RegularTransducer.new(TEST_COMPILED_REGULAR_FILE)
    assert_equal [['b', 'a', 'r'], ['b', 'a', 'z']], fst.analyse('foo', :symbol_sequence => true).sort

    fst = SFST::RegularTransducer.new(TEST_COMPILED_REGULAR_FILE)
    assert_equal [], fst.analyse('fox', :symbol_sequence => true).sort
  end

  def test_generate_acceptance
    fst = SFST::RegularTransducer.new(TEST_COMPILED_REGULAR_FILE)
    assert_equal true, fst.accepted_generating?('bar')
    assert_equal true, fst.accepted_generating?('baz')
    assert_equal false, fst.accepted_generating?('bax')
  end

  def test_generate
    fst = SFST::RegularTransducer.new(TEST_COMPILED_REGULAR_FILE)
    assert_equal ['foo'], fst.generate('bar').sort

    fst = SFST::RegularTransducer.new(TEST_COMPILED_REGULAR_FILE)
    assert_equal ['foo'], fst.generate('baz').sort

    fst = SFST::RegularTransducer.new(TEST_COMPILED_REGULAR_FILE)
    assert_equal [], fst.generate('bax').sort
  end

  def test_generate_language_default
    fst = SFST::RegularTransducer.new(TEST_COMPILED_REGULAR_FILE)
    a = []
    fst.generate_language do |u|
      a << u.collect { |pair| pair.join(':') }.join
    end
    assert_equal ['b:fa:or:o', 'b:fa:oz:o'], a.sort
  end

  def test_generate_language_both
    fst = SFST::RegularTransducer.new(TEST_COMPILED_REGULAR_FILE)
    a = []
    fst.generate_language(:levels => :both) do |u|
      a << u.collect { |pair| pair.join(':') }.join
    end
    assert_equal ['b:fa:or:o', 'b:fa:oz:o'], a.sort
  end

  def test_generate_language_upper
    fst = SFST::RegularTransducer.new(TEST_COMPILED_REGULAR_FILE)
    a = []
    fst.generate_language(:levels => :upper) do |u|
      a << u.join
    end
    assert_equal ['foo'], a.sort
  end

  def test_generate_language_lower
    fst = SFST::RegularTransducer.new(TEST_COMPILED_REGULAR_FILE)
    a = []
    fst.generate_language(:levels => :lower) do |u|
      a << u.join
    end
    assert_equal ['bar', 'baz'], a.sort
  end
end

class CompactTransducerTestCase < Test::Unit::TestCase
  def setup
    SFST::compile(TEST_SCRIPT_FILE, TEST_COMPILED_COMPACT_FILE, :compact => true)
  end

  def test_analyze_acceptance
    fst = SFST::CompactTransducer.new(TEST_COMPILED_COMPACT_FILE)
    assert_equal true, fst.accepted_analysis?('foo')
    assert_equal false, fst.accepted_analysis?('fox')
  end

  def test_analyze
    fst = SFST::CompactTransducer.new(TEST_COMPILED_COMPACT_FILE)
    assert_equal ['bar', 'baz'], fst.analyse('foo').sort
    assert_equal [], fst.analyse('fox').sort
  end
end
