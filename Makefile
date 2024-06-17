OBJECT_FILES = dis6502.o
OBJECT_FILES += fds_snd.o
OBJECT_FILES += fmopl.o
OBJECT_FILES += log.o
OBJECT_FILES += memguard.o
OBJECT_FILES += mmc5_snd.o
OBJECT_FILES += nes_apu.o
OBJECT_FILES += nes6502.o
OBJECT_FILES += nsf.o
OBJECT_FILES += vrc7_snd.o
OBJECT_FILES += vrcvisnd.o

CFLAGS = -DNSF_PLAYER

all: nsfplay

clean:
	rm -f ${OBJECT_FILES}
	rm -f nsfplay
	rm -f nsfplay.o

nsfplay: nsfplay.cpp ${OBJECT_FILES}
	g++ -std=c++11 -o nsfplay nsfplay.cpp ${OBJECT_FILES} -lm

dis6502.o: nosefart/dis6502.c
	gcc ${CFLAGS} -c $<

fds_snd.o: nosefart/fds_snd.c
	gcc ${CFLAGS} -c $<

fmopl.o: nosefart/fmopl.c
	gcc ${CFLAGS} -c $<

log.o: nosefart/log.c
	gcc ${CFLAGS} -c $<

memguard.o: nosefart/memguard.c
	gcc ${CFLAGS} -c $<

mmc5_snd.o: nosefart/mmc5_snd.c
	gcc ${CFLAGS} -c $<

nes_apu.o: nosefart/nes_apu.c
	gcc ${CFLAGS} -c $<

nes6502.o: nosefart/nes6502.c
	gcc ${CFLAGS} -c $<

nsf.o: nosefart/nsf.c
	gcc ${CFLAGS} -c $<

vrc7_snd.o: nosefart/vrc7_snd.c
	gcc ${CFLAGS} -c $<

vrcvisnd.o: nosefart/vrcvisnd.c
	gcc ${CFLAGS} -c $<

nsfplay.o: nsfplay.c
	gcc ${CFLAGS} -c $<
