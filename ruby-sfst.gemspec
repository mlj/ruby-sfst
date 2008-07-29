Gem::Specification.new do |s|
  s.name = %q{ruby-sfst}
  s.version = "0.0.1"

  s.required_rubygems_version = Gem::Requirement.new("= 1.2") if s.respond_to? :required_rubygems_version=
  s.authors = ["Marius L. J\303\270hndal"]
  s.date = %q{2008-07-29}
  s.description = %q{A wrapper for the Stuttgart Finite State Transducer Tools (SFST).}
  s.email = %q{mariuslj (at) ifi [dot] uio (dot) no}
  s.extensions = ["ext/sfst_machine/extconf.rb"]
  s.extra_rdoc_files = ["README.rdoc", "lib/sfst.rb"]
  s.files = ["README.rdoc", "Rakefile", "Manifest", "test/test_sfst.rb", "test/test_sfst.fst", "CHANGELOG", "ext/sfst_machine/fst-compiler.h", "ext/sfst_machine/utf8.C", "ext/sfst_machine/operators.C", "ext/sfst_machine/utf8-scanner.ll", "ext/sfst_machine/determinise.C", "ext/sfst_machine/interface.C", "ext/sfst_machine/compact.h", "ext/sfst_machine/basic.h", "ext/sfst_machine/fst.h", "ext/sfst_machine/make-compact.h", "ext/sfst_machine/fst-compiler.yy", "ext/sfst_machine/mem.h", "ext/sfst_machine/compact.C", "ext/sfst_machine/basic.C", "ext/sfst_machine/interface.h", "ext/sfst_machine/sfst_machine.cc", "ext/sfst_machine/extconf.rb", "ext/sfst_machine/alphabet.C", "ext/sfst_machine/fst.C", "ext/sfst_machine/alphabet.h", "ext/sfst_machine/make-compact.C", "ext/sfst_machine/fst-compiler.C", "ext/sfst_machine/utf8.h", "ext/sfst_machine/utf8-scanner.C", "lib/sfst.rb", "ruby-sfst.gemspec"]
  s.has_rdoc = true
  s.homepage = %q{http://github.com/mlj/ruby-sfst}
  s.rdoc_options = ["--line-numbers", "--inline-source", "--title", "Ruby-sfst", "--main", "README.rdoc"]
  s.require_paths = ["lib", "ext"]
  s.rubyforge_project = %q{ruby-sfst}
  s.rubygems_version = %q{1.2.0}
  s.summary = %q{A wrapper for the Stuttgart Finite State Transducer Tools (SFST).}
  s.test_files = ["test/test_sfst.rb"]

  if s.respond_to? :specification_version then
    current_version = Gem::Specification::CURRENT_SPECIFICATION_VERSION
    s.specification_version = 2

    if current_version >= 3 then
      s.add_development_dependency(%q<echoe>, [">= 0"])
    else
      s.add_dependency(%q<echoe>, [">= 0"])
    end
  else
    s.add_dependency(%q<echoe>, [">= 0"])
  end
end
