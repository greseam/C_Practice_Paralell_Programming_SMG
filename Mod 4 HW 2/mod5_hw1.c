#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
int main() 
{ 
	pid_t process_id;
	pid_t p_process_id;
    pid_t child_process;

	//getpid() - will return process id of calling function
	process_id = getpid();
	//getppid() - will return process id of parent function
	p_process_id = getppid();


	printf("The parent process id of my C-code: %d\n",p_process_id);
    printf("The process id of my running C-code is: %d\n",process_id);

    child_process = fork(); //singles out the child process for the next bit of code

	 // child process because return value zero 
    if (child_process == 0)
        child_process = getpid();
    else
        printf("The process id of my child C-code is: %d\n",child_process);
    

    return 0;
} 
