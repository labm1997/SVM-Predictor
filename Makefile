

bin/svm: src/main.c obj/svm.o bin
	gcc src/main.c obj/svm.o -o bin/svm -O3 -I include/ -lm -Wall
	
obj/svm.o: src/svm.c obj
	gcc src/svm.c -o obj/svm.o -O3 -c -I include/ -Wall

bin:
	mkdir bin

obj:
	mkdir obj

clean:
	rm -R obj
	rm -R bin
