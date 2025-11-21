CXX = g++
CXXFLAGS = -c
LDFLAGS =
OBJ = main.o Date.o Saleline.o Cashmemo.o
TARGET = app

all: $(TARGET)
	./$(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

main.o: main.cpp Date.h Saleline.h Cashmemo.h
	$(CXX) $(CXXFLAGS) main.cpp

Date.o: Date.cpp Date.h
	$(CXX) $(CXXFLAGS) Date.cpp

Saleline.o: Saleline.cpp Saleline.h
	$(CXX) $(CXXFLAGS) Saleline.cpp

Cashmemo.o: Cashmemo.cpp Cashmemo.h
	$(CXX) $(CXXFLAGS) Cashmemo.cpp

clean:
	del /Q *.o $(TARGET).exe
