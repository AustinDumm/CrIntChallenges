JC = javac
JFLAGS = -d ./out/
SRC_DIR := src/lox
OUT_DIR := out/lox
SRC := $(wildcard $(SRC_DIR)/*.java)
CLASSES := $(patsubst $(SRC_DIR)/%.java, $(OUT_DIR)/%.class, $(SRC))

TOOL_DIR := src/tool
TOOL_OUT := out/tool
TOOL_SRC := $(wildcard $(TOOL_DIR)/*.java)
TOOL_CLASSES := $(patsubst $(TOOL_DIR)/%.java, $(TOOL_OUT)/%.class, $(TOOL_SRC))

.PHONY: all clean clean_build

all : out/lox/

clean_build : clean all

tool : out/tool/

out/lox/ : $(SRC)
	$(JC) $(JFLAGS) $(SRC)

out/tool/ : $(TOOL_SRC)
	$(JC) $(JFLAGS) $(TOOL_SRC)

clean :
	$(RM) *.class
	rm -rf out/*

