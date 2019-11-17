# coding: utf-8
lib = File.expand_path('../lib', __FILE__)
$LOAD_PATH.unshift(lib) unless $LOAD_PATH.include?(lib)
require 'sfst/version'

Gem::Specification.new do |spec|
  spec.name          = "ruby-sfst"
  spec.version       = SFST::VERSION
  spec.authors       = ["Marius L. Jøhndal"]
  spec.email         = ["mariuslj@ifi.uio.no"]
  spec.license       = 'GPL2'

  spec.summary       = %q{Stuttgart Finite State Transducer Tools interface}
  spec.description   = %q{A wrapper for the Stuttgart Finite State Transducer Tools (SFST).}
  spec.homepage      = "http://github.com/mlj/ruby-sfst"

  spec.files         = `git ls-files -z`.split("\x0").reject { |f| f.match(%r{^spec/}) } - %w(.gitignore .rspec .travis.yml)
  spec.require_paths = ["lib"]
  spec.extensions    = ["ext/sfst/extconf.rb"]

  spec.required_ruby_version = '>= 1.9'

  spec.add_development_dependency 'bundler'
  spec.add_development_dependency 'rake', '~> 12.3'
  spec.add_development_dependency 'rake-compiler', '~> 1.0'
  spec.add_development_dependency 'rspec', '~> 3.7'
  spec.add_development_dependency 'pry', '~> 0.11'
  spec.add_development_dependency 'simplecov', '~> 0.15'
  spec.add_development_dependency 'yard', '~> 0.9'
end
