SRC = Dir.entries("src").reject { |f| File.directory? f or f !~ /\.c(pp|xx)$/ }
OBJ = SRC.map { |s| "build/" + s.sub(".cpp", ".o") }
EXEC = "app"
COMPILER = "g++"
FLAGS = "--std=c++14 -pthread -Wall -Wextra -pedantic"
LINK = "-lsfml-graphics -lsfml-window -lsfml-system"
INCLUDE = ""

directory "build/"
directory "bin/"

task :build => OBJ + ["bin/"] do
	sh "#{COMPILER} #{FLAGS} -o bin/#{EXEC} #{OBJ.join(" ")} #{LINK} "
end

task :rebuild => [:clean, :build]

task :run => "bin/#{EXEC}" do
	sh "bin/#{EXEC}"
end

task "bin/#{EXEC}" => :build

rule %r{build/.+\.o} => ["build/", proc { |task_name| task_name.sub(%r{build/(.+)\.o}, 'src/\\1.cpp')}] do |t|
	sh "#{COMPILER} #{FLAGS} #{INCLUDE} -c #{t.prerequisites[1]} -o #{t.name}"
end

task :clean do 
	rm_f OBJ
	rm_f "bin/#{EXEC}"
end

