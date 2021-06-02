CC?=cc
CFLAGS?=-g -pipe -Iinclude -Wall -Werror

srcs = ej_exec.c  ej_exit.c  ej_fifo.c  ej_fork.c  ej_pipe.c  ej_sigaction2.c  ej_sigaction.c  ej_signal.c  mytest.c
targs = $(srcs:%.c=%)

all : ${targs}

$(targs): %: %.c
	${CC} ${CFLAGS} $^ -o $@

clean:
		rm -f *.o
		rm -f ej_exec  ej_exit  ej_fifo  ej_fork  ej_pipe  ej_sigaction2  ej_sigaction  ej_signal  mytest
