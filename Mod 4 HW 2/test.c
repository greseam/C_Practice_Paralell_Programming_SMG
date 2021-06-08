/*
Sean Gregor
10/11/2020

Mod 4 HW 2

Generally speaking i have a hard time understanding this code
as i ran into many conusing errors 
but most of the comments talk more about what each aspect does, such as each methods and variables.
*/

//Included libraries
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>

//defines constant variables
#define TRUE 1
#define LINELENGTH 256
#define ARGNUM 256
char type_prompt(); 

void read_command(char *command, char * parameters[]) ; //

//main method
int main(){   
int status; 
char *command = (char *) //
malloc(LINELENGTH);  //allocates memory to the size of linelength or 256
char *parameters[ARGNUM] ; //
   
   while(TRUE){      // true is defined as 1 so the while loop won't break, running endlessly
        type_prompt();      // displays prompt on the screen
        read_command(command, parameters);  // reads input
        if(fork()!=0){       //fork is a unix system call that "forks" a child branch from the parent branch. I had a lot of trouble with these unix commands
                                //this basicly means that two processes can be ran at once
                             
                             // so if the forked branch is a parent, or in this case not a child, than it runs the below code 
            // parent code
            waitpid(-1, &status, 0);        // waits for the completion of the child branch
        }
        else{        
            //Child code / branch
            execve(command, parameters, 0); // executes the program pointed to by filename. 
            //for refrence: please ignore : int execve(const char *pathname, char *const argv[],char *const envp[]);
        }   
    }  
return 0; //end of method
}