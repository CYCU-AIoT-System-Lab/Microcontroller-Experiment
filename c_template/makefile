CFLAG=-Wno-implicit-function-declaration
DIR:=./executable/

# Cleaning only works on linux/WSL

test_1:test_1.c
	@echo Compiling $^ ...
	gcc $(CFLAG) $^ -o $(DIR)$@
	@echo Compiling $^ ... Done

ct1:
	@echo Clearing test_1 related files ...
	rm $(DIR)test_1*

test_2:test_2.c
	@echo Compiling $^ ...
	gcc $(CFLAG) $^ -o $(DIR)$@
	@echo Compiling $^ ... Done

ct2:
	@echo Clearing test_2 related files ...
	rm $(DIR)test_2*

test_3:test_3.c
	@echo Compiling $^ ...
	gcc $(CFLAG) $^ -o $(DIR)$@
	@echo Compiling $^ ... Done

ct3:
	@echo Clearing test_3 related files ...
	rm $(DIR)test_3*

test_4:test_4.c
	@echo Compiling $^ ...
	gcc $(CFLAG) $^ -o $(DIR)$@
	@echo Compiling $^ ... Done

ct4:
	@echo Clearing test_4 related files ...
	rm $(DIR)test_4*

all:
	@echo Compiling all ...
	gcc $(CFLAG) test_1.c -o $(DIR)test_1
	gcc $(CFLAG) test_2.c -o $(DIR)test_2
	gcc $(CFLAG) test_3.c -o $(DIR)test_3
	gcc $(CFLAG) test_3.c -o $(DIR)test_3
	@echo Compiling all ... Done

ca:
	@echo Cleaning all files besides source files ...
	rm $(DIR)*

help:
	@echo ==========================================
	@echo + Make options
	@echo + WARN -- Cleaning only works on linux/WSL
	@echo +  1. test_1 -- compile test_1
	@echo +  2. ct1    -- clear test_1
	@echo +  3. test_2 -- compile test_2
	@echo +  4. ct2    -- clear test_2
	@echo +  5. test_3 -- compile test_3
	@echo +  6. ct3    -- clear test_3
	@echo +  7. test_4 -- compile test_4
	@echo +  8. ct4    -- clear test_4
	@echo +  9. all    -- compile all
	@echo + 10. ca     -- clear all
	@echo + 11. help   -- display make options
	@echo ==========================================

