lib = File.expand_path('lib', __dir__)
$LOAD_PATH.unshift(lib) unless $LOAD_PATH.include?(lib)
require 'sfst/version'

Gem::Specification.new do |spec|
  spec.name          = 'ruby-sfst'
  spec.version       = SFST::VERSION
  spec.authors       = ['Marius L. Jøhndal']
  spec.email         = ['mariuslj@ifi.uio.no']
  spec.license       = 'GPL2'

  spec.summary       = 'Stuttgart Finite State Transducer Tools interface'
  spec.description   = 'A wrapper for the Stuttgart Finite State Transducer Tools (SFST).'
  spec.homepage      = 'http://github.com/mlj/ruby-sfst'

  spec.files         =
    `git ls-files -z`.split("\x0").reject { |f| f.match(%r{^spec/}) } - %w[.gitignore .rspec .travis.yml]
  spec.require_paths = ['lib']
  spec.extensions    = ['ext/sfst/extconf.rb']

  spec.required_ruby_version = '>= 2.4'

  spec.add_development_dependency 'bundler', '~> 2.1.4'
  spec.add_development_dependency 'pry', '~> 0.13.1'
  spec.add_development_dependency 'rake', '~> 13.0.1'
  spec.add_development_dependency 'rake-compiler', '~> 1.1.0'
  spec.add_development_dependency 'rspec', '~> 3.9.0'
  spec.add_development_dependency 'rubocop', '~> 0.84.0'
  spec.add_development_dependency 'simplecov', '~> 0.18.5'
  spec.add_development_dependency 'yard', '~> 0.9.25'
end
