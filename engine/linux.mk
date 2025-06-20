COMPILER = clang
SOURCES = $(wildcard src/core/*.c)
LIBRARIES =
FLAGS = -Wall -Wextra -fPIC -shared -Isrc -I../engine/src -DPLATFORM_LINUX
VERSION = -std=c23
OUTPUT = engine

release:
	@echo -------------------- compiling $(OUTPUT) in RELEASE mode --------------------
	$(COMPILER) $(VERSION) $(SOURCES) $(LIBRARIES) $(FLAGS) -O3 -o ../bin/lib$(OUTPUT).so

debug:
	@echo -------------------- compiling $(OUTPUT) in DEBUG mode --------------------
	$(COMPILER) $(VERSION) $(SOURCES) $(LIBRARIES) $(FLAGS) -g -O0 -DDEBUG -o ../bin/lib$(OUTPUT).so
