#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

char pidname[];

void childTask(){
printf("Please enter my name :");
scanf("%s", pidname);
printf("\n my name is %s.PPID:%d PID:%d \n", pidname, getpid(), getpid());
}

int main(void) {
for (int i=1; i<5; i++){
pid_t pid =fork();
if (pid==0){
printf("%d.", i);
childTask();
exit(0);
}
else {
wait(NULL);
printf("Next child process \n");
}
}
printf("The task is finished \n");
return EXIT_SUCCESS;
}
