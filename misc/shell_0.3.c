#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKEN_SIZE 64
#define MAX_NUM_TOKENS 64
/**
 * tokenize_input - Tokenizes a given string
 * @input: String to be tokenize
 *
 * Returns an array of tokens. The last element of the array is set to NULL.
 */
char **tokenize_input(char *input) {
  { /* ... function implementation ... */
  }
  char **tokens = malloc(MAX_NUM_TOKENS * sizeof(char *));
  char *token = strtok(input, " \t\n");
  int i = 0;

  while (token != NULL) {
    tokens[i] = token;
    i++;
    token = strtok(NULL, " \t\n");
  }

  tokens[i] = NULL;
  return (tokens);
}

/**
 * search_path - Searches for a given command in the directories listed in PATH
 * @command: Command to search for
 *
 * Returns the full path to the command if found, or NULL if not found.
 */
char *search_path(char *command) {
  { /* ... function implementation ... */
  }
  char *path = getenv("PATH");
  char *dir = strtok(path, ":");

  while (dir != NULL) {
    char *cmd_path = malloc(strlen(dir) + strlen(command) + 2);

    sprintf(cmd_path, "%s/%s", dir, command);
    if (access(cmd_path, X_OK) == 0) {
      return (cmd_path);
    }

    free(cmd_path);
    dir = strtok(NULL, ":");
  }
  return (NULL);
}

/**
 * build_path - Builds the full path to a command given its directory and name
 * @path: Directory containing the command
 * @command: Name of the command
 *
 * Returns the full path to the command.
 */
char *build_path(char *path, char *command) {
  { /* ... function implementation ... */
  }
  char *cmd_path = malloc(strlen(path) + strlen(command) + 2);

  sprintf(cmd_path, "%s/%s", path, command);
  return (cmd_path);
}

/**
 * main - Entry point
 * @argc: Number of arguments passed to the program
 * @argv: Array of arguments passed to the program
 *
 * Returns 0 on success, non-zero on failure.
 */
int main(int argc, char *argv[]) {
  { /* ... function implementation ... */
  }
  char input[MAX_INPUT_SIZE];

  while (1) {
    printf("Shell >");
    fgets(input, MAX_INPUT_SIZE, stdin);
    input[strcspn(input, "\n")] = '\0'; /* remove trailing newline */

    if (strcmp(input, "exit") == 0) {
      break;
    }

    char **tokens = tokenize_input(input);
    pid_t pid = fork();

    if (pid == 0) { /* child process */
      char *path = search_path(tokens[0]);

      if (path == NULL) {
        printf("%s: command not found\n", tokens[0]);
        exit(1);
      }
      char *cmd_path = build_path(path, tokens[0]);

      execv(cmd_path, tokens);
      perror("execv");
      exit(1);
    } else { /* The parent process */
      waitpid(pid, NULL, 0);
    }

    free(tokens);
  }

  return (0);
}
