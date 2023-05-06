#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_INPUT 1024
#define MAX_ARGS 64

/**
 * tokenize_input - Tokenizes input string into arguments
 * @input: User input string
 * @args: Array of argument strings
 *
 * Return: Number of arguments
 */
int tokenize_input(char *input, char **args) {
  int i = 0;
  char *token;

  token = strtok(input, " \n");
  while (token != NULL) {
    args[i++] = token;
    token = strtok(NULL, " \n");
  }
  args[i] = NULL;

  return (i);
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */

int main(void) {
  char input[MAX_INPUT]; /* Buffer to hold user input */
  char *args[MAX_ARGS];  /* Array to hold command arguments */
  pid_t pid;             /* Process ID */
  int status;            /* Exit status of child process */
  int num_args;          /* Number of arguments */
  int i;

  while (1) {
    printf("#cisfun$ "); /* Display prompt */
    fflush(stdout);      /* Make sure prompt is displayed */

    /* Read user input */
    if (fgets(input, MAX_INPUT, stdin) == NULL) {
      printf("\n");
      break;
    }

    /* Tokenize input into arguments */
    num_args = tokenize_input(input, args);

    /* Exit if no command provided */
    if (num_args == 0)
      continue;

    /* Exit if user enters "exit" */
    if (strcmp(args[0], "exit") == 0)
      break;

    pid = fork(); /* Create child process */

    if (pid < 0) /* Fork failed */
    {
      perror("Fork failed");
      exit(EXIT_FAILURE);
    }

    if (pid == 0) /* Child process */
    {
      if (execvp(args[0], args) < 0) /* Execute command */
      {
        perror("Command not found");
        exit(EXIT_FAILURE);
      }
    } else /* Parent process */
    {
      /* Wait for child process to complete */
      do {
        waitpid(pid, &status, WUNTRACED);
      } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    /* Reset argument array */
    for (i = 0; i < num_args; i++)
      args[i] = NULL;
  }

  return (0);
}
