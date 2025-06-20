COMPILER = clang
SOURCES = $(wildcard src/*.c)
LIBRARIES = -L../bin -lengine
FLAGS = -Wall -Wextra -Isrc -I../engine/src -DPLATFORM_WINDOWS
VERSION = -std=c23
OUTPUT = testbed

release:
	@echo -------------------- compiling $(OUTPUT).exe in RELEASE mode --------------------
	$(COMPILER) $(VERSION) $(SOURCES) $(LIBRARIES) $(FLAGS) -O3 -o ../bin/$(OUTPUT).exe

debug:
	@echo -------------------- compiling $(OUTPUT).exe in DEBUG mode --------------------
	$(COMPILER) $(VERSION) $(SOURCES) $(LIBRARIES) $(FLAGS) -g -O0 -DDEBUG -o ../bin/$(OUTPUT).exe

run:
	@echo -------------------- running $(OUTPUT).exe --------------------
	../bin/$(OUTPUT).exe
