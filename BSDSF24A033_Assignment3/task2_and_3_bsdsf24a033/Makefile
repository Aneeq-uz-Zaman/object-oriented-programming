all: main.exe
	./main.exe

main.exe: main.o employee.o officer.o dailywager.o payroll.o
	g++ main.o employee.o officer.o dailywager.o payroll.o -o main.exe

main.o: main.cpp payroll.h officer.h dailywager.h
	g++ -c main.cpp

employee.o: employee.cpp employee.h
	g++ -c employee.cpp

officer.o: officer.cpp officer.h employee.h
	g++ -c officer.cpp

dailywager.o: dailywager.cpp dailywager.h employee.h
	g++ -c dailywager.cpp

payroll.o: payroll.cpp payroll.h employee.h
	g++ -c payroll.cpp

clean:
	del *.o main.exe