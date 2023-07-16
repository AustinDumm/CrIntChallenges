JC = javac
JFLAGS = -d ./out/
SRC_DIR := src/lox
OUT_DIR := out/lox
SRC := $(wildcard $(SRC_DIR)/*.java)
CLASSES := $(patsubst $(SRC_DIR)/%.java, $(OUT_DIR)/%.class, $(SRC))

.PHONY: all clean

all : out/lox/

out/lox/ : $(SRC)
	$(JC) $(JFLAGS) $(SRC)

clean :
	$(RM) *.class
	rm -rf out/*

