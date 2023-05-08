#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)

{
	char *buf = NULL;
	size_t bufsize = 0;
	ssize_t nread;
	int status;

	while (1)
	{ /* Loop indefinitely */
		printf("$ "); /* Print prompt */
		nread = getline(&buf, &bufsize, stdin); /* Read command line */
		if (nread == -1)
		{ /* If an error occurred */
			if (feof(stdin))
		{ /* Check if it's end-of-file condition */
			putchar('\n'); /* Print new line */
			exit(EXIT_SUCCESS); /* Exit the program */
		} else
		{
			perror("getline"); /* Print the error message */
			exit(EXIT_FAILURE); /* Exit the program with failure status */
		}
		}
		/* Remove the trailing newline character, if there is one */
		if (buf[nread - 1] == '\n')
			buf[nread - 1] = '\0';
		/* Execute the command */
		status = system(buf);
		if (status == -1)
		{ /* If an error occurred */
			perror("system"); /* Print the error message */
			exit(EXIT_FAILURE); /* Exit the program with failure status */
		}
	}

	free(buf); /* Free memory */
	buf = NULL; /* Reset pointer */

	return (0);
}
