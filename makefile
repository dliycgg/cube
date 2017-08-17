sharedir=./shared
object=cube.o action.o in_out.o $(sharedir)/s2a.o
cube : $(object)
	gcc -o cube $(object)  -lm 
cube.o : cube.c
	gcc -o cube.o -c cube.c -I$(sharedir)
action.o in_out.o :
.PHONY : clean clear
clean :
	rm cube $(object)
clear :
	rm  $(object)

