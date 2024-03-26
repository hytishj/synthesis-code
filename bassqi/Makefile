a.out: test.o feature.o
	gcc -o a.out test.o feature.o -lm
test.o: feature_test.c
	gcc -c feature_test.c -o test.o
feature.o: feature.c
	gcc -c feature.c -o feature.o

.PHONY:clean

clean:
	-rm -rf *.o

RUN:run
run:
	./a.out