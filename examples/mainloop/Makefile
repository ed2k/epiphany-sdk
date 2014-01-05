ESDK=$(EPIPHANY_HOME)
ELIBS=$(ESDK)/tools/host/lib
EINCS=$(ESDK)/tools/host/include
ELDF=$(ESDK)/bsps/current/internal.ldf
OBJS=epiphany.elf

all: $(OBJS)


epiphany.elf: epiphany.c shared.h 
	e-gcc -std=c99 -T $(ELDF) epiphany.c  -o epiphany.elf -le-lib

#replace.o: replace.c
#	e-gcc -O3 -std=c99 -c replace.c -o replace.o 

clean:
	rm replace.o $(OBJS)
