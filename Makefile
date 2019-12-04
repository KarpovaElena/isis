OBJS = main.o
GCCFLAGS = -c
LIBS = -L/Users/Bear-/OneDrive/Рабочий стол/elite/lib_static -lshowpnm

INCLUDE = -I /Users/Bear-/OneDrive/Рабочий стол/elite/lib_static/include

vpath %.h /Users/Bear-/OneDrive/Рабочий стол/elite/lib_static/include


main: main.o 
	gcc $^ $(LIBS) -o $@

main.o: main.c showpnm.h
	gcc $(GCCFLAGS) $(INCLUDE) $< -o $@
 
