require "bundler/gem_tasks"
require "rspec/core/rake_task"

RSpec::Core::RakeTask.new(:spec)

require "rake/extensiontask"

task :build => :compile

Rake::ExtensionTask.new("sfst") do |ext|
  ext.lib_dir = "lib/sfst"
end

task :default => [:clobber, :compile, :spec]
