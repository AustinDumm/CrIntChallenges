CC = clang
CFLAGS = -g -Wall -Wextra

SRC_DIR := src
OBJ_DIR := obj

SRC := $(wildcard $(SRC_DIR)/*.c)
HEADERS := $(wildcard $(SRC_DIR)/*.h)
OBJS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

.PHONY: all clean remake

all : clox

clox : $(OBJS) $(HEADERS)
	$(CC) -o clox $(OBJS) $(CFLAGS)

clean : 
	rm $(OBJ_DIR)/*
	rm clox

remake : clean all

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) -c -o $@ $< $(CFLAGS)



