stat: statStuff.c
	gcc statStuff.c

clean:
	rm a.out

run: a.out
	./a.out
