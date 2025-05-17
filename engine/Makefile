project = CubicEngine
compiler = clang
headers = include/*
sources = $(shell find src -name *.c)
libraries = 
flags = -Wall -Wextra

linux:
	sudo mkdir -p /usr/include/$(project)
	sudo rm -rf /usr/include/$(project)/*
	sudo cp -r $(headers) /usr/include/$(project)/
	sudo $(compiler) $(sources) $(flags) -fPIC -shared -o /usr/lib/lib$(project).so
