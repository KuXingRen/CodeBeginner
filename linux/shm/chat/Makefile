CC=gcc
CFLAGS=-I/root/CodeBeginner/C/.include
SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)
EXES=$(SRCS:.c=.out)

all: $(EXES)

%.out: %.o
	$(CC) -o $@ $<

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS) $(EXES)

.PHONY: all clean
