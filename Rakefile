# coding: utf-8
require 'bundler'
Bundler::GemHelper.install_tasks

namespace :doc do
  require 'yard'
  YARD::Rake::YardocTask.new do |task|
  task.files   = ['README.md', 'lib/**/*.rb']
  task.options = [
    '--output-dir', 'doc/yard',
    '--markup', 'markdown',
    ]
  end
end
