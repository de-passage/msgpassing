require "rakeIDE"
require "rakeIDE/g++"

IDE.compiler = Tools::Compiler::GXX

IDE.compiler.path = "/usr/local/include"
IDE.compiler.options = [ "--std=c++1y", "-Wall", "-Wall", "-Wextra", "-pthread" ]

IDE.default_target = :lib
IDE.available_targets = [:release, :debug]

IDE.for_target(:release) do
	IDE.linker = Tools::Linker::GXX
	IDE.linker.path = "/usr/local/lib"
	IDE.linker.libraries.concat ["sfml-graphics", "sfml-window", "sfml-system", "msgparsing"]
	IDE.linker.options << "-pthread"
end

IDE.for_target(:lib) do
	IDE.binary_name = "libmsgparsing.a"
	IDE.linker = Tools::ArchiveManager::Ar
	IDE.target_prefix = false
	IDE.binary_directory= "lib"
end

rule(/^example_.+/) do |t|
	source = t.name.match(/^example_(.+)/)[1]
	source = File.join("example", *(source.split('_')))
	Rake::Task[:target].invoke 'release'
	Rake::Task[:source].invoke source
end

