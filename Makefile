fuzzypet: main.c
	gcc -g main.c -o fuzzypet 
clean:
	rm *.o fuzzypet
install:
	cp fuzzypet /bin/.
uninstall:
	rm /bin/fuzzypet
	rm ~/.fuzzypet
