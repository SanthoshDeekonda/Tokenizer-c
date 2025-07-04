CC = gcc
SRC_FILE = src/*.c
C_FLAGS = -I.
MAIN  = main.c
OUT = tokenizer


build:
	$(CC) $(MAIN) $(SRC_FILE) $(C_FLAGS) -o $(OUT)

clean:
	rm -f $(OUT)
	clear
