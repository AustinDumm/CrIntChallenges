all : out/runner.out

clean :
	rm bin/*


bin/bad_dl_list.o : ./src/bad_dl_list.c
	clang -c -o bin/bad_dl_list.o ./src/bad_dl_list.c

bin/runner.o : ./test/runner.c
	clang -c -o bin/runner.o ./test/runner.c

out/runner.out : bin/bad_dl_list.o bin/runner.o
	clang -o out/runner.out bin/bad_dl_list.o bin/runner.o
