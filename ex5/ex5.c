// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write
// the three messages to the parent and have the parent print out
// the messages.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MSGSIZE 16

char *msg1 = "hello world #1";
char *msg2 = "hello world #2";
char *msg3 = "hello world #3";

int main(void)
{
  // Your code here
  char buf[128]; // Creates a buffer
  int fd[2];     // Creates a holder arr to make a pipe
  // char *msgs[] = {msg1, msg2, msg3};
  pipe(fd); // Creates a pipe form fd arr
  pid_t pid = fork();
  if (pid == 0)
  {
    printf("%d from the child\n", pid);
    int bytes_written1 = write(fd[1], msg1, MSGSIZE);
    int bytes_written2 = write(fd[1], msg2, MSGSIZE);
    int bytes_written3 = write(fd[1], msg3, MSGSIZE);
  }
  else
  {
    // wait(NULL);
    printf("%d from the parent\n", pid);
    int bytes_read1 = read(fd[0], buf, sizeof buf);
    int bytes_read2 = read(fd[0], buf, sizeof buf);
    int bytes_read3 = read(fd[0], buf, sizeof buf);

    write(STDOUT_FILENO, buf, bytes_read1);
    write(STDOUT_FILENO, buf, bytes_read2);
    write(STDOUT_FILENO, buf, bytes_read3);    
  }
  return 0;
}
