.PHONY: all
all: log
	gcc -o main main.c log.c module1.c module2.c module3.c

.PHONY: log
log:
	./generate_log_modules --json log_strings.json --header log_modules.h .

.PHONY: clean
clean:
	rm -f main main.exe
