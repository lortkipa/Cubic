COMPILER = clang
SOURCES = $(wildcard src/*.c)
LIBRARIES =
FLAGS = -Wall -Wextra -Isrc -I../engine/src -DPLATFORM_WINDOWS
OUTPUT = testbed

release:
	@echo -------------------- compiling $(OUTPUT).exe in RELEASE mode --------------------
	$(COMPILER) $(SOURCES) $(LIBRARIES) $(FLAGS) -O3 -o $(OUTPUT).exe

debug:
	@echo -------------------- compiling $(OUTPUT).exe in DEBUG mode --------------------
	$(COMPILER) $(SOURCES) $(LIBRARIES) $(FLAGS) -O0 -DDEBUG -o $(OUTPUT).exe

run:
	@echo -------------------- running $(OUTPUT).exe --------------------
	$(OUTPUT).exe
