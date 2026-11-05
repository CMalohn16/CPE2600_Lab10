CC=gcc 
CFLAGS=-c -Wall
LDFLAGS=
SOURCES= signal_handler.c
OBJECTS=$(SOURCES:.c=.o) 
EXECUTABLE=signals

all: $(SOURCES) $(EXECUTABLE) 

# pull in dependency info for *existing* .o files
-include $(OBJECTS:.o=.d)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@ 

.c.o:
	$(CC) $(CFLAGS) $< -o $@
	$(CC) -MM $<>$ *.d

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE) *.d