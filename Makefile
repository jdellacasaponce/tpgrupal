.PHONY: estatico dinamico all benchmark

estatico:
	gcc -o test_estatico StackModuleContiguousStatic.c StackModuleTest.c
	./test_estatico

dinamico:
	gcc -o test_dinamico StackModuleLinkedDynamic.c StackModuleTest.c
	./test_dinamico

all: estatico dinamico

benchmark: 
	@./benchmark_test.sh
