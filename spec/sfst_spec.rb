require 'spec_helper'

TEST_DIRECTORY = File.expand_path(File.dirname(__FILE__))
TEST_COMPILED_COMPACT_FILE = File.join(TEST_DIRECTORY, 'test_sfst_compact.a')
TEST_COMPILED_REGULAR_FILE = File.join(TEST_DIRECTORY, 'test_sfst_regular.a')

describe SFST do
  it 'has a version number' do
    expect(SFST::VERSION).not_to be nil
  end
end

describe SFST::RegularTransducer do
  before(:each) do
    @fst = SFST::RegularTransducer.new(TEST_COMPILED_REGULAR_FILE)
  end

  it 'accepts/rejects analysis strings' do
    expect(@fst.accepted_analysis?('foo')).to be true
    expect(@fst.accepted_analysis?('fox')).to be false
  end

  it 'analyses strings' do
    expect(@fst.analyse('foo').sort).to eq %w(bar baz)
    expect(@fst.analyse('fox').sort).to eq %w()
  end

  it 'analyses strings and returns symbol sequences' do
    expect(@fst.analyse('foo', symbol_sequence: true).sort).to eq [%w(b a r), %w(b a z)]
    expect(@fst.analyse('fox').sort).to eq %w()
  end

  it 'accepts/rejects generating strings' do
    expect(@fst.accepted_generating?('bar')).to be true
    expect(@fst.accepted_generating?('baz')).to be true
    expect(@fst.accepted_generating?('bax')).to be false
  end

  it 'generates strings' do
    expect(@fst.generate('bar').sort).to eq %w(foo)
    expect(@fst.generate('baz').sort).to eq %w(foo)
    expect(@fst.generate('bax').sort).to eq %w()
  end

  it 'generates both sides by default' do
    a = []
    @fst.generate_language do |u|
      a << u.map { |p| p.join(':') }.join
    end

    expect(a.sort).to eq %w(b:fa:or:o b:fa:oz:o)
  end

  it 'generates both sides' do
    a = []
    @fst.generate_language(levels: :both) do |u|
      a << u.map { |p| p.join(':') }.join
    end

    expect(a.sort).to eq %w(b:fa:or:o b:fa:oz:o)
  end

  it 'generates the upper side' do
    a = []
    @fst.generate_language(levels: :upper) do |u|
      a << u.join
    end

    expect(a.sort).to eq %w(foo)
  end

  it 'generates the lower side' do
    a = []
    @fst.generate_language(levels: :lower) do |u|
      a << u.join
    end

    expect(a.sort).to eq %w(bar baz)
  end

  it 'can repeatedly analyse stings' do
    32768.times do
      expect(@fst.analyse('foo').sort).to eq %w(bar baz)
    end
  end
end

describe SFST::CompactTransducer do
  before(:each) do
    @fst = SFST::CompactTransducer.new(TEST_COMPILED_COMPACT_FILE)
  end

  it 'accepts/rejects analysis strings' do
    expect(@fst.accepted_analysis?('foo')).to be true
    expect(@fst.accepted_analysis?('fox')).to be false
  end

  it 'analyses strings' do
    expect(@fst.analyse('foo').sort).to eq %w(bar baz)
    expect(@fst.analyse('fox').sort).to eq %w()
  end

  it 'can repeatedly analyse stings' do
    32768.times do
      expect(@fst.analyse('foo').sort).to eq %w(bar baz)
    end
  end
end