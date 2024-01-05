#Makefile
CC=gcc
CFLAGS=-g -Wall 
#TARGET=g2t t2n
#TARGET=g2t
#OBJS=g2t.o t2n.o
#OBJS=g2t.o

PREFIX=/home/ncdc/lee/tbin/

#INCDIR 추가
INCDIR += -I/home/ncdc/lee/opt/netcdf/include -I/home/ncdc/lee/opt/eccodes/include

#LIB 추가
NETCDFLIB = -L/home/ncdc/lee/opt/netcdf/lib -lnetcdf -L/home/ncdc/lee/opt/hdf5/lib -lhdf5 -lnetcdf

#$(TARGET) : $(OBJS)
#	$(CC) -o $(PREFIX)$(TARGET) $(OBJS)

gb2nc4 : gb2nc4.c 
	$(CC) -c -o gb2nc4.o gb2nc4.c $(INCDIR)
	$(CC) -o $(PREFIX)gb2nc4 gb2nc4.o $(NETCDFLIB)

gb2nc3 : gb2nc3.c 
	$(CC) -c -o gb2nc3.o gb2nc3.c $(INCDIR)
	$(CC) -o $(PREFIX)gb2nc3 gb2nc3.o $(NETCDFLIB)

grib : grib.c
	$(CC) -c -o gb2nc4.o gb2nc4.c $(INCDIR)
	$(CC) -o $(PREFIX)gb2nc4 gb2nc4.o $(NETCDFLIB)
	
clean : 
	rm -f $(TARGET) $(OBJS)