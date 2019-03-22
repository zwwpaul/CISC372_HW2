all : test1 test2 test3 test4
  
evens_lib.o: evens_lib.h evens_lib.c
	cc -c -std=c11 -pedantic evens_lib.c
        
evens_driver.o: evens_lib.h evens_driver.c
	cc -c -std=c11 -pedantic evens_driver.c

evens.exe: evens_lib.o evens_driver.o
	cc -o evens.exe evens_lib.o evens_driver.o

test1 : evens_driver.c evens.exe
	./evens.exe 0 1 2 3 4 5 6 7 8 9

test2 : evens_driver.c evens.exe
	./evens.exe -2 -2 -2 
        
test3 : evens_driver.c evens.exe
	./evens.exe

test4 : evens_driver.c evens.exe
	./evens.exe 80 2 3 4

clean :
	rm -f *.exe *~ *.o
