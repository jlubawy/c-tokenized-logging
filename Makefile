.PHONY: all
all:
	gcc -o main main.c log.c module1.c module2.c module3.c

.PHONY: clean
clean:
	rm main main.exe
