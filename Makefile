school: school_system.o forFaculty.o forStudent.o newStudent.o changeStudent.o showStudent.o searchStudent.o
	gcc -o school school_system.o forFaculty.o forStudent.o newStudent.o changeStudent.o showStudent.o searchStudent.o
school_system.o: school_system.c
	gcc -g -Wall -c school_system.c
forFaculty.o: forFaculty.c 
	gcc -g -Wall -c forFaculty.c
forStudent.o: forStudent.c
	gcc -g -Wall -c forStudent.c
newStudent.o: newStudent.c school_system.h
	gcc -g -Wall -c newStudent.c
changeStudent.o: changeStudent.c school_system.h
	gcc -g -Wall -c changeStudent.c
showStudent.o: showStudent.c school_system.h
	gcc -g -Wall -c showStudent.c
searchStudent.o: searchStudent.c school_system.h
	gcc -g -Wall -c searchStudent.c
clean:
	rm *.o
