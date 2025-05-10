project = CubicEngine
compiler = gcc
headers = include/*
sources = $(shell find src -name *.c)
libraries = -lX11 -lGLX -lGLEW
flags = -fPIC -shared -Wall -Wextra

build:
	sudo mkdir -p /usr/include/$(project)
	sudo rm -rf /usr/include/$(project)/*
	sudo cp -r $(headers) /usr/include/$(project)/
	sudo $(compiler) $(sources) $(libraries) $(flags) -o /usr/lib/lib$(project).so
