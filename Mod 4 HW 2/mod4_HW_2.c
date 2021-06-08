//include libaries 
#include<stdio.h> 
#include<sys/wait.h> 
#include<unistd.h>

//static variable
#define TRUE 1 //Setting the while loop to true

// Found refrences using geeks for geeks and made a partially functional code and
// still trying to understand what is really going on here.


int main(){ 
    int status; 
    char *args[] = {"ls", "-l", "-a", (char *)0};
    char *env_args[] = { (char*)0 }; // pointer to array
    while(TRUE){            // true is defined as 1 so the while loop won't break, running endlessly
        if (fork() != 0) {//fork is a unix system call that "forks" a child branch from the parent branch. I had a lot of trouble with these unix commands
                                //this basicly means that two processes can be ran at once
                             
                             // so if the forked branch is a parent than it runs the below code

            /* Parent Code */
            waitpid(-1, &status, 0); //suspending the execution of calling processes until the child terminates
        }else{
            /* Child Code */
            execve(args[0], args, env_args); // executing the command pointed to
        }
    }
    return 0;//end of method 
} 