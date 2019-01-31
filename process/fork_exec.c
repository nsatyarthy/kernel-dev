#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include "../myutil.h"

int main(void)
{
  int status;
  char* args[] = { "/bin/ls", NULL };
  pid_t pid = fork();

  if (pid == 0) {
    execv(args[0], args);
    p("Should not reach here");
  }
  else {
    wait(&status);
    p("Done");
  }

  return 0;
}
