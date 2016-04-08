CC=g++
CFLAGS=-c -Wall -ggdb -I.
LDFLAGS=
SOURCES=prism.cpp pyramid.cpp pyramid.cpp breakup-strings.cpp
EXECUTABLE=
TESTS=

OBJECTS=$(SOURCES:.cpp=.o)


FLAGS   = -Iinclude

#all: $(SOURCES) $(EXECUTABLE)

all: pyramid prism cubiod breakup-strings
	

# These next lines do a bit of magic found from http://stackoverflow.com/questions/2394609/makefile-header-dependencies
# Essentially it asks the compiler to read the .cpp files and generate the needed .h dependencies.
# This way if any .h file changes the correct .cpp files will be recompiled
depend: .depend

.depend: $(SOURCES)
	rm -f ./.depend
	$(CC) $(CFLAGS) -MM $^ >> ./.depend;

include .depend
# End .h file magic

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *o $(EXECUTABLE)
	rm -f ./.depend
	rm -f Result*
	rm -f speed
	rm -f *.o pyramid prism cubiod breakup-strings
	
pyramid: pyramid.cpp
	g++ -I. -ggdb -Wall -O2 pyramid.cpp -o pyramid

prism: prism.cpp
	g++ -I. -ggdb -Wall -O2 prism.cpp -o prism

cubiod: cubiod.cpp
	g++ -I. -ggdb -Wall -O2 cubiod.cpp -o cubiod

breakup-strings: breakup-strings.cpp
	g++ -I. -ggdb -Wall -O2 breakup-strings.cpp -o breakup-strings
	
FORCE:


