#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

#define MAXLINE 1024

void sigint_handler(int sig);
void sigtstp_handler(int sig);
void unix_error(char *msg);
void app_error(char *msg);
typedef void handler_t(int);
handler_t *Signal(int signum, handler_t *handler);
int global = 1;

int main(int argc, char **argv)
{

	char cmdline[MAXLINE];

	Signal(SIGINT, sigint_handler);
	Signal(SIGTSTP, sigtstp_handler);

	while (1)
	{
		printf("%d>", global);
		fgets(cmdline, MAXLINE, stdin);
	}

	exit(0);
}

void sigint_handler(int sig)
{
	global--;
	printf("\n%i>", global);
	fflush(stdout);
	if (global <= 0)
	{
		printf("\n");
		fflush(stdout);
		exit(0);
	}
	return;
}

void sigtstp_handler(int sig)
{
	global++;
	printf("\n%i>", global);
	fflush(stdout);
	return;
}

/***********************
 * Other helper routines
 ***********************/

/*
 * app_error - application-style error routine
 */
void app_error(char *msg)
{
	fprintf(stdout, "%s\n", msg);
	exit(1);
}

/*
 * unix_error - unix-style error routine
 */
void unix_error(char *msg)
{
	fprintf(stdout, "%s: %s\n", msg, strerror(errno));
	exit(1);
}

/*
 * Signal - wrapper for the sigaction function
 */
handler_t *Signal(int signum, handler_t *handler)
{
	struct sigaction action, old_action;

	action.sa_handler = handler;
	sigemptyset(&action.sa_mask); /* block sigs of type being handled */
	action.sa_flags = SA_RESTART; /* restart syscalls if possible */

	if (sigaction(signum, &action, &old_action) < 0)
		unix_error("Signal error");
	return (old_action.sa_handler);
}