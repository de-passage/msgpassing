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
LINK = "-lsfml-graphics -lsfml-window -lsfml-system"
LINK_PATH = "" # For additional path 
INCLUDE_PATH = ""

####################################################
# 
# 		Constants
#
###################################################

require "pathname"
require "find"

EXEC_PATH = (Pathname.new(BINARY_DIRECTORY) + EXEC).to_s

CPP_FILE_REGEX = /\.c((pp|xx)?|c)$/
HPP_FILE_REGEX = /\.(h(((pp|xx)?|h)|inl))$/
SRC = Dir.glob(Pathname.new(SOURCE_DIRECTORY) + "**/*").reject { |f| f.to_s !~ CPP_FILE_REGEX }
SRC_STRUCT = Dir.glob(Pathname.new(SOURCE_DIRECTORY) + "**/").map { |e| e.to_s }
OBJ_STRUCT = SRC_STRUCT.map { |e| e.sub(SOURCE_DIRECTORY, BUILD_DIRECTORY) }.reject { |e| e == BUILD_DIRECTORY }
OBJ = SRC.map { |e| e.sub(CPP_FILE_REGEX, ".o").sub(SOURCE_DIRECTORY, BUILD_DIRECTORY) }

####################################################
# 
# 		Tasks
#
###################################################

directory BINARY_DIRECTORY

task :build => OBJ + [BINARY_DIRECTORY] do
	sh "#{COMPILER} #{FLAGS} -o #{EXEC_PATH} #{OBJ.join(" ")} #{LINK}"
end

OBJ_STRUCT.each { |d| directory d }

task :rebuild => [:clean, :build]

namespace :rebuild do 
	task :run => [:clean, :build, :run]
end

namespace :build do
	task :run => [:build, :run]
end

task :run => EXEC_PATH do
	sh EXEC_PATH
end

file EXEC_PATH

def resolve_obj_source_file obj
	o = Regexp.quote(obj.sub(".o", "").sub(BUILD_DIRECTORY, SOURCE_DIRECTORY))
	raise "Conflicting source file names for #{obj}" if SRC.count { |e| e =~ /#{o}/ } > 1 
	SRC.find { |e| e =~ /#{o}#{CPP_FILE_REGEX}/ } 
end

rule ".o" => [OBJ_STRUCT, proc { |obj| resolve_obj_source_file(obj) }].flatten do |t|
	sh "#{COMPILER} #{FLAGS} -I#{HEADER_DIRECTORY} #{if(INCLUDE_PATH != "") then "-I" + INCLUDE_PATH end} -c #{t.prerequisites[-1]} -o #{t.name}"
end

rule ".cpp"

task :clean do 
	rm_f OBJ
	rm_f EXEC_PATH
end

task :hello do 
	p EXEC_PATH
end
