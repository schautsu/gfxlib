make:
	gcc -o example example.c -Lgfx -lgfx -lSDL3 -lSDL3_ttf -Wall -Wextra -pedantic
clean:
	rm example
