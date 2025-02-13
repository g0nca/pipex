# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
#include <stdio.h>

int main(void)
{

	if (access("/bin/ls", X_OK) != -1)
		printf("I have permission\n");
	else
		printf("I don't have permission\n");

    return (0);
}