// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as
// `execl()`, `execle()`, `execv()`, and others. Why do you think there
// are so many variants of the same basic call?

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
  // Your code here
  pid_t pid = fork();
  if (pid == 0)
  {
    printf("%d from the child\n", pid);

    execlp("/bin/ls", "ls", NULL);
  }
  else
  {
    // wait(NULL);
    printf("%d from the parent\n", pid);
    execlp("/bin/ls", "ls", NULL);
  }
  return 0;
}
