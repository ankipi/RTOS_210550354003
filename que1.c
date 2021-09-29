/* Ankita Shukla
 210550354003
 */


#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

#define Size 64

int main()
{


 int pipefd[2];
 pid_t id;
 int buff[size];
 pipe(pipefd);
 id=fork();

 if(id==0)
 {
    close(pipefd[1]);
    read(pipefd[0],"4",2);
    close(pipefd[0]);
    read();
 }
 else
 {
     printf("Parent\n");
     close (pfd[0]);
     write(pfd[1],"4",2);
     printf("Data :%d\n",buff);
 }
 return 0;

}
