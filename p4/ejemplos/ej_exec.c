#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  char* myargv[] = { "mytest", "Una", "dola", "tela", "catola", NULL };
  char* myenv[] = { NULL };

  printf("Me. (PID: %d)\n", getpid());

  if ( execve(myargv[0], myargv, myenv) == -1 ) {
    perror("Error al lanzar el programa de ejemplo.");
    exit(1);
  }

  return 0;
}

