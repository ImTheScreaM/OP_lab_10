GCC = gcc
CFLAGS = -Iinclude
SRC=$(wildcard src/*.c)

OUT_NAME = app.out
OUT_FILE = outputs

.PHONY: app clean run

app:
	$(GCC) $(SRC) $(CFLAGS) -o ${OUT_FILE}/$(OUT_NAME)

clean:
	rm -rf ${OUT_FILE}/$(OUT_NAME)

run:
	./${OUT_FILE}/${OUT_NAME}