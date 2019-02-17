CFLAGS += -Wl,-Map=func1.map,--cref
sum.exe: main.o fun1.o fun2.o
	gcc -o sum.exe main.o fun1.o fun2.o
	gcc $^ --output $@ $(CFLAGS)
	objdumb -x main.o fun1.o fun2.o
main.o: fun1.h fun2.h
	gcc -c main.c
fun1.o: fun1.h fun1.c
	gcc -c fun1.c		
fun2.o: fun2.h fun2.c
	gcc -c fun2.c
clean: main.o fun1.o fun2.o
	del *.o


