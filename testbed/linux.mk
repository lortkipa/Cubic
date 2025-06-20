COMPILER = clang
SOURCES = $(wildcard src/*.c)
LIBRARIES = -L../bin -lengine
FLAGS = -Wall -Wextra -Isrc -I../engine/src -Wl,-rpath,$(realpath ../bin) -DPLATFORM_LINUX
VERSION = -std=c23
OUTPUT = testbed

release:
	@echo -------------------- compiling $(OUTPUT) in RELEASE mode --------------------
	$(COMPILER) $(VERSION) $(SOURCES) $(LIBRARIES) $(FLAGS) -O3 -o ../bin/$(OUTPUT)

debug:
	@echo -------------------- compiling $(OUTPUT) in DEBUG mode --------------------
	$(COMPILER) $(VERSION) $(SOURCES) $(LIBRARIES) $(FLAGS) -g -O0 -DDEBUG -o ../bin/$(OUTPUT)

run:
	@echo -------------------- running $(OUTPUT) --------------------
	../bin/$(OUTPUT)
