project = test
compiler = gcc
sources = $(shell find src -name *.c)
libraries = -lCubicEngine
flags = -Wall -Wextra

build:
	$(compiler) $(sources) $(libraries) $(flags) -o $(project)

run:
	./$(project)
