CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.c bme280.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=sensors

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

#all: sensors

#sensors: main.o bme280.o
#	$(CC) main.o bme280.o -o sensors
#
#main.o: main.c
#	$(CC) $(CFLAGS) main.c

#bme280.o: bme280.h
#	$(CC) $(CFLAGS) bme280.c

clean:
	rm *o sensors
