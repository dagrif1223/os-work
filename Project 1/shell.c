#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>

#define MAX_COMMAND_LINE_LEN 1024
#define MAX_COMMAND_LINE_ARGS 128

char prompt[256];
char delimiters[] = " \t\r\n";
extern char **environ;
// Global variable to store the process ID of the running foreground process
pid_t running_process_pid = 0;

// Signal handler for SIGINT (Ctrl-C)
void sigint_handler(int signum) {
    // If there is a running foreground process, terminate it
    if (running_process_pid > 0) {
        kill(running_process_pid, SIGTERM);
        running_process_pid = 0;
    }
    // Print a message and return to the prompt
    printf("\nCtrl-C pressed.\n %s> ", prompt);
    fflush(stdout);
}


int main() {
    // Stores the string typed into the command line.
    char command_line[MAX_COMMAND_LINE_LEN];
    char cmd_bak[MAX_COMMAND_LINE_LEN];
    int i;
    
  
    // Stores the tokenized command line input.
    char *arguments[MAX_COMMAND_LINE_ARGS];
     // Register the SIGINT handler
    signal(SIGINT, sigint_handler);
    while (true) {
      int background = 0;
        do{ 
            // Print the shell prompt. step 0
            
            if (getcwd(prompt, sizeof(prompt)) == NULL) {
            perror("getcwd() error");
            exit(1);
            }
            else {
           
            printf("%s> ", prompt);
            fflush(stdout);
            }

            // Read input from stdin and store it in command_line. If there's an
            // error, exit immediately. (If you want to learn more about this line,
            // you can Google "man fgets")
        
            if ((fgets(command_line, MAX_COMMAND_LINE_LEN, stdin) == NULL) && ferror(stdin)) {
                fprintf(stderr, "fgets error");
                exit(0);
            }
 
        }while(command_line[0] == 0x0A);  // while just ENTER pressed

      
        // If the user input was EOF (ctrl+d), exit the shell.
        if (feof(stdin)) {
            printf("\n");
            fflush(stdout);
            fflush(stderr);
            return 0;
        }

        // TODO:
        // 
        
			  // 0. Modify the prompt to print the current working directory
			  
			
        // 1. Tokenize the command line input (split it on whitespace)
             arguments[0] = strtok(command_line, delimiters);
 
            // Keep printing tokens while one of the
            // delimiters present in str[].
            i = 0;
            while (arguments[i] != NULL) {
                //printf("%s\n", arguments[i]);
                i++;
                arguments[i] = strtok(NULL, delimiters);
            }
 
      
        // 2. Implement Built-In Commands
        if (strcmp(arguments[0], "cd") == 0){
            chdir(arguments[1]);
        }
        else if (strcmp(arguments[0], "pwd") == 0){
            printf("%s\n", prompt);
        }
        else if (strcmp(arguments[0], "echo") == 0){
            i = 1;
            while (arguments[i] != NULL) {
                if (*arguments[i] == '$'){
                    printf("%s\n", getenv(arguments[i] + 1));
                }
                else {
                    printf("%s ", arguments[i]);
                
                }
                i++;
               
            }
            printf("\n");
        }
        else if (strcmp(arguments[0], "exit") == 0){
            exit(0);
        }
        else if (strcmp(arguments[0], "env") == 0){
            if (arguments[1] != NULL) {
                printf("%s\n", getenv(arguments[1]));
            }
            else {
                for(i = 0; environ[i] != NULL; i++) {
                printf("%s\n", environ[i]);
                }
            }
            
            
        }
        else if (strcmp(arguments[0], "setenv") == 0){
              if (setenv(arguments[1], arguments[2], 1) == 0) {
                printf("Environment variable %s set to %s\n", arguments[1], arguments[2]);
            } else {
                perror("setenv");
            }
        }
        else {
    
        // 3. Create a child process which will execute the command line input
        i = 0;
        while (arguments[i] != NULL) {
            i++;
        }

        if (i > 0 && strcmp(arguments[i - 1], "&") == 0) {
                background = 1;
                arguments[i - 1] = NULL; // Remove the "&" from the arguments
            } 
            pid_t pid = fork();
            if (pid == -1) {
                perror("fork error");
            } else if (pid == 0) {
                // Child process
                if (background) {
                    // Redirect standard input, output, and error to /dev/null for background processes
                    int null_fd = open("/dev/null", O_RDWR);
                    dup2(null_fd, STDIN_FILENO);
                    dup2(null_fd, STDOUT_FILENO);
                    dup2(null_fd, STDERR_FILENO);
                    close(null_fd);
                }
                else {
                    alarm(10);
                }
                
                
                if (execvp(arguments[0], arguments) == -1) {
                // If execvp fails, report the error
                perror("execvp error");
                exit(1);
            }
                // Child process exits with an error status when execvp succeeds
                exit(1);
            }
            else {
                // Parent process
                // 4. The parent process should wait for the child to complete unless its a background process
                if (!background) {
                    running_process_pid = pid; // Set the running process PID
                    // Wait for the child process to finish
                    int status;
                    waitpid(pid, &status, 0);
                    running_process_pid = 0; // Reset the running process PID
                    if (WIFEXITED(status) && WEXITSTATUS(status) == 1) {
                        fprintf(stderr, "Error executing external command: %s\n", arguments[0]);
                    }
                }
                // Continue without waiting for background processes
  
        
      
        }
        // Hints (put these into Google):
        // man fork
        // man execvp
        // man wait
        // man strtok
        // man environ
        // man signals
        
        // Extra Credit
        // man dup2
        // man open
        // man pipes
    }
    }
    // This should never be reached.
    return -1;
}
