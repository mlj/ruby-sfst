# coding: utf-8
lib = File.expand_path('../lib', __FILE__)
$LOAD_PATH.unshift(lib) unless $LOAD_PATH.include?(lib)
require 'sfst/version'

Gem::Specification.new do |s|
  s.authors = ["Marius L. Jøhndal"]
  s.description = %q{A wrapper for the Stuttgart Finite State Transducer Tools (SFST).}
  s.summary = %q{Stuttgart Finite State Transducer Tools interface}
  s.email = ['mariuslj (at) ifi [dot] uio (dot) no']
  s.files = %w(CHANGELOG.md README.md Rakefile ruby-sfst.gemspec)
  s.files += Dir.glob("ext/**/*.C")
  s.files += Dir.glob("ext/**/*.h")
  s.files += Dir.glob("ext/**/*.rb")
  s.files += Dir.glob("ext/**/*.cc")
  s.files += Dir.glob("lib/**/*.rb")
  s.files += Dir.glob("test/*.fst")
  s.files += Dir.glob("test/*.rb")
  s.homepage = "http://github.com/mlj/ruby-sfst"
  s.licenses = ['GPL2']
  s.name = "ruby-sfst"
  s.require_paths = ["lib"]
  s.required_rubygems_version = '>= 1.3.5'
  s.extensions = ["ext/sfst_machine/extconf.rb"]
  s.test_files += Dir.glob("test/*.rb")
  s.version = SFST::VERSION

  s.add_development_dependency 'bundler', '~> 1.0'
  s.add_development_dependency 'test-unit', '~> 3.0'
end
