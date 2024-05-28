all:
	gcc main.c functions.c cozi.c -o clasament

clean:
	rm -f clasament