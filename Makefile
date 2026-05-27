GCC = gcc

CFLAGS = -Wall -Wextra -Wpedantic -Iinclude -fPIC
SAN = -fsanitize=address,undefined -g

SRC = src/caesar.c src/predicate.c src/shift.c src/vigener.c
ALL_SRC = $(wildcard src/*.c)
TESTS = $(wildcard tests/*.c)

OUT_NAME = app.out
OUT_FILE = outputs

LIB = build/libcipher.so

.PHONY: build test test_py sanitize static docs clean app run

app:
	$(GCC) $(ALL_SRC) $(CFLAGS) -o $(OUT_FILE)/$(OUT_NAME)

run:
	./$(OUT_FILE)/$(OUT_NAME)

build:
	mkdir -p build
	$(GCC) $(CFLAGS) -shared $(SRC) -o $(LIB)

test: build
	$(GCC) $(CFLAGS) $(TESTS) -Lbuild -lcipher -o outputs/test.out
	LD_LIBRARY_PATH=build ./outputs/test.out

test_py: build
	LD_LIBRARY_PATH=build python3 tests/test_py.py

docs:
	doxygen docs/Doxyfile

clean:
	rm -rf build outputs/*.out

