require 'rubygems'
require 'rake'
 
begin
  require 'echoe'
 
  Echoe.new('ruby-sfst', '0.2.0') do |p|
    p.summary = "A wrapper for the Stuttgart Finite State Transducer Tools (SFST)."
    p.author = 'Marius L. Jøhndal'
    p.email = "mariuslj (at) ifi [dot] uio (dot) no"
    p.url = "http://github.com/mlj/ruby-sfst"
    p.ignore_pattern = ["*.gemspec"]
    p.rdoc_pattern = ["README.rdoc", "lib/*.rb"]
    p.rubyforge_name = "sfst"
  end
 
rescue LoadError => boom
  puts "You are missing a dependency required for meta-operations on this gem."
  puts "#{boom.to_s.capitalize}."
end
 
Dir["#{File.dirname(__FILE__)}/tasks/*.rake"].sort.each { |ext| load ext }
