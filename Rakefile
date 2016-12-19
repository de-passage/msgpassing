####################################################
# 
# 		Configuration
#
###################################################

# Application name
EXEC = "app"

# Project structure
HEADER_DIRECTORY = "include"
SOURCE_DIRECTORY = "src"
BINARY_DIRECTORY = "bin/"
BUILD_DIRECTORY = "build"

# Compiler configuration (gcc only right now)
COMPILER = "g++"
FLAGS = "--std=c++14 -pthread -Wall -Wextra -pedantic"
COMPILATION_OPTIONS = ""
LINKER_OPTIONS = ""
LINK = "-lsfml-graphics -lsfml-window -lsfml-system"
LINK_PATH = "" # For additional path 
INCLUDE_PATH = ""

# Object file extension (why not)
OBJ_EXTENSION = ".o"

####################################################
# 
# 		Constants
#
###################################################

require "pathname"

EXEC_PATH = (Pathname.new(BINARY_DIRECTORY) + EXEC).to_s

CPP_FILE_REGEX = /\.c((pp|xx)?|c)$/
HPP_FILE_REGEX = /\.(h(((pp|xx)?|h)|inl))$/
HEADER_PATH = Pathname.new(HEADER_DIRECTORY)
SOURCE_PATH = Pathname.new(SOURCE_DIRECTORY)
SRC = Dir.glob(SOURCE_PATH + "**/*").reject { |f| f.to_s !~ CPP_FILE_REGEX }
SRC_STRUCT = Dir.glob(SOURCE_PATH + "**/").map { |e| e.to_s }
OBJ_STRUCT = SRC_STRUCT.map { |e| e.sub(SOURCE_DIRECTORY, BUILD_DIRECTORY) }.reject { |e| e == BUILD_DIRECTORY }
OBJ = SRC.map { |e| e.sub(CPP_FILE_REGEX, OBJ_EXTENSION).sub(SOURCE_DIRECTORY, BUILD_DIRECTORY) }
HPP = Pathname.glob(HEADER_PATH + "**/*").map{|d|d.relative_path_from(HEADER_PATH).to_s}.reject { |f| f.to_s !~ HPP_FILE_REGEX }

####################################################
# 
# 		Utils
#
###################################################

def resolve_obj_source_file obj
	o = Regexp.quote(obj.sub(OBJ_EXTENSION, "").sub(BUILD_DIRECTORY, SOURCE_DIRECTORY))
	raise "Conflicting source file names for #{obj}" if SRC.count { |e| e =~ /#{o}/ } > 1 
	SRC.find { |e| e =~ /#{o}#{CPP_FILE_REGEX}/ } 
end

# Returns a list of files included in the file
def all_hpp_files cpp
	ret = []
	File.open(cpp) do |f|
		f.each do |l|
			if m = l.match(/#include\s+(?:"|<)(.+)(?:"|>).*/)
				ret << m[1]
			end
		end
	end
	reg = /#{HPP.map { |hpp| Regexp.quote(hpp) }.join("|")}/
	ret.select { |f| f =~ reg }.map { |f| (HEADER_PATH + f).to_s }
end

def all_obj_dependencies obj
	cpp = resolve_obj_source_file(obj)
	# Build a list of hpp files 
	hpp = all_hpp_files(cpp)
	# Go one level deeper excluding those done already
	# deep1 = hpp.each do |h| all_hpp_files(h) - hpp end
	# repeat until nothing comes out
	[OBJ_STRUCT] + hpp + [cpp]#
end

####################################################
# 
# 		Tasks
#
###################################################

desc "Compile the files and build the executable"
task :build => OBJ + [BINARY_DIRECTORY] do
	sh "#{COMPILER} #{FLAGS} #{LINKER_OPTIONS} -o #{EXEC_PATH} #{OBJ.join(" ")} #{LINK}"
end

directory BINARY_DIRECTORY

OBJ_STRUCT.each { |d| directory d }

desc "Rebuild the executable from scratches"
task :rebuild => [:clean, :build]

namespace :rebuild do 
	desc "Rebuild the executable then run it"
	task :run => [:clean, :build, :run]
end

namespace :build do
	desc "Build the executable then run it"
	task :run => [:build, :run]
end

desc "Run the executable"
task :run => EXEC_PATH do
	sh EXEC_PATH
end

file EXEC_PATH

rule OBJ_EXTENSION => proc { |obj| all_obj_dependencies(obj) } do |t|
	sh "#{COMPILER} #{FLAGS} -I#{HEADER_DIRECTORY} #{COMPILATION_OPTIONS} -c #{t.prerequisites[-1]} -o #{t.name}"
end

rule CPP_FILE_REGEX => proc { |cpp| all_hpp_files(cpp) }

rule HPP_FILE_REGEX => proc { |hpp| all_hpp_files(hpp) }

desc "Remove all object files"
task :clean do 
	rm_f OBJ
end

desc "Clean all object files and remove the executable"
task :purge => :clean do
	rm_f EXEC_PATH
end

desc "Print the compilation status"
task :status do |t|
end

task :hello do |t|
	puts all_hpp_files()
end
