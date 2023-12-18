#Makefile
CC=gcc
CFLAGS=-g -Wall 
#TARGET=g2t t2n
#TARGET=g2t
#OBJS=g2t.o t2n.o
#OBJS=g2t.o

PREFIX=/home/ncdc/lee/tbin/

#INCDIR 추가
INCDIR += -I/home/ncdc/lee/opt/netcdf/include

#LIB 추가
NETCDFLIB = -L/home/ncdc/lee/opt/netcdf/lib -lnetcdf

$(TARGET) : $(OBJS)
	$(CC) -o $(PREFIX)$(TARGET) $(OBJS)

g2t : g2t.c 
	$(CC) -c -o g2t.o g2t.c $(INCDIR)
	$(CC) -o $(PREFIX)g2t g2t.o $(NETCDFLIB)

t2n : t2n.c 
	$(CC) -c -o t2n.o t2n.c $(INCDIR)
	$(CC) -o $(PREFIX)t2n t2n.o $(NETCDFLIB)

clean : 
	rm -f $(TARGET) $(OBJS)