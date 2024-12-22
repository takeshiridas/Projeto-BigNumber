all: client

client: client.o bignumber.o node.o
	gcc client.o bignumber.o node.o -g -lm -o client

client.o: client.c bignumber.h node.h
	gcc -std=c99 -Wall -Werror -Wvla -g -c client.c

bignumber.o: bignumber.c bignumber.h node.h
	gcc -std=c99 -Wall -Werror -Wvla -g -c bignumber.c

node.o: node.c node.h
	gcc -std=c99 -Wall -Werror -Wvla -g -c node.c

clean:
	rm -f client.o bignumber.o node.o client
