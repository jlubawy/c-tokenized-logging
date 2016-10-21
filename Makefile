.PHONY: all
all:
	./generate_log_modules --output log_modules.h .
	gcc -o main main.c log.c module1.c module2.c module3.c

.PHONY: clean
clean:
	rm -f main main.exe
