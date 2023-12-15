#Makefile
CC=gcc
CFLAGS=-g -Wall 
#TARGET=g2t t2n
TARGET=g2t
#OBJS=g2t.o t2n.o
OBJS=g2t.o

$(TARGET) : $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

g2t.o : g2t.c 
	$(CC) -c -o g2t.o g2t.c

#t2n.o : t2n.c 
#	$(CC) -c -o t2n.o t2n.c

clean : 
	rm -f $(TARGET) $(OBJS)