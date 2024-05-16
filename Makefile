SRC=$(wildcard *.c)
EXE=fmt

all: run

run: $(EXE)
	@./$(EXE)

test: $(EXE)
	@cp -f test test.txt
	@./$(EXE) test.txt
	@cat test
	@echo ====================
	@cat test.txt
	@rm test.txt

$(EXE): $(SRC)
	@gcc -o $(EXE) $(SRC)
