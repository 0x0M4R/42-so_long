#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
int main()
{
     char* cmd1[] = { "/bin/ls", NULL };
    char* cmd2[] = { "/bin/grep","src", NULL };
     char* more[] = { "/usr/bin/wc",  NULL };
    char* const* cmds[] = { cmd1, cmd2, more, NULL };
    int upstream[2];
    int downstream[2];
    char readbuffer[3][300];
    char *new;
    int status;
    int r;
    int i=0;
    int lastfd;
    readbuffer[0][0]='1';
    readbuffer[0][1]='s';
    readbuffer[0][2]='t';
    readbuffer[0][3]=0;
    pid_t pid[3];
    //pipe(downstream);
    pipe(downstream);
    pipe(upstream);
    while(i<2)
    {
    pid[i] = (pid_t)fork();
    if(pid[i] == 0)
    {
        if(dup2(downstream[0],0) != 0 ||close(downstream[0]) != 0 || close(downstream[1])!= 0)
         printf("child faild to setup stdin");
        if(dup2(upstream[1],1)!=0 || close(upstream[0])!=0 || close(upstream[0]) != 0)
        printf("child failed to setup stdout");
        execve(cmds[i][0], cmds[i], NULL);
    }
    else
    {		
        const char data[] = "hello how are you\nvery well thanks\n";
        
        close(upstream[1]);
        //write input to exec //close unused
		printf("\nwriting to downstream/child: \n %s  ",readbuffer[i]);
        //close(upstream[1]);
        close(downstream[0]);
        write(downstream[1], data, sizeof(data));
       //close(downstream[0]);
        close(downstream[1]);
        //close(downstream[1]);
        //close(upstream[1]);
        //close(downstream[1]);
        //close(downstream[1]);
        //close(downstream[0]);
        //printf("wrote %s to child\n",readbuffer);
       // printf("parent");
		r = read(upstream[0], readbuffer[i+1], 300);
		;
        readbuffer[i+1][r] = 0;
        close(upstream[0]);
        printf("\nfrom child \n%s",readbuffer[i+1]);
        //seek(0);
        //close(upstream[0]);

        //printf("read from parent %d:%s",i,readbuffer);
        
        
        //waitpid(pid, &status, WUNTRACED);
        //printf("parent");
    }

    i++;
    }
    //close(downstream[0]);
		//write(downstream[1], readbuffer, strlen(readbuffer));
        //close(downstream[1]);
        //close(upstream[1]);
        //close(downstream[1]);
        //close(downstream[1]);
        //close(downstream[0]);
        //printf("wrote %s to child\n",readbuffer);
       // printf("parent");
		//while((r = read(upstream[0], readbuffer, strlen(readbuffer))))
		//readbuffer[r] = 0;
        //printf("%s",readbuffer);
        //seek(0);
        //close(upstream[0]);
        //close(downstream[0]);
        //close(downstream[1]);
    //close(downstream[1]);
    //waitpid(pid[0], &status, WUNTRACED);
    //close(downstream[1]);
    //close(downstream[0]);
    //close(downstream[1]);
    //waitpid(pid[1], &status, WUNTRACED);
   //close(downstream[1]);
    //close(downstream[0]);
    //close(downstream[1]);
    //waitpid(pid[2], &status, WUNTRACED);
    //close(downstream[1]);
    //close(downstream[0]);
    //close(downstream[1]);
    //printf("%s",readbuffer);
}