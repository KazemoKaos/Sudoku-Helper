.SUFFIXES: .cpp
.cpp.o:
	g++ -w -c $(CXXFLAGS) $<
	
# Compile with debug option and all warnings on.
CXXFLAGS = -g -w -Wall -I../..

# Object modules comprising this application
OBJ = *.cpp

P12: $(OBJ)
	g++ $(CXXFLAGS) -o P12 $(OBJ) && ./P12 puzt.txt

clean:
	rm -f $(OBJ) P12
