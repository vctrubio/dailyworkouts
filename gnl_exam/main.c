#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE 
#define BUFFER_SIZE 1
#endif

char	*gnl(int fd)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		printf("error.\n");
		return NULL;
	}

	char *line;
	line = (char*)malloc(10000);
	char *buf = malloc(BUFFER_SIZE);
	
	int rd = 0;
	char c;
	int i = 0;
	while ((rd = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		for (int j = 0; j < rd; j++)
		{
			c = buf[j];
			line[i++] = c;
			if (c == '\n')
				break;
		}
		if (c == '\n')
			break;
	}

	line[i] = 0;

	free(buf);
	if (i == 0 || rd == -1 || (!line[i-1] && !rd))
	{
		free(line);
		return NULL;
	}

	return line;
}


int main()
{
	int fd = open("file", O_RDONLY);

	char *p;

	while (1)
	{
		p = gnl(fd);
		if (!p)
			break;
			printf("-%s", p);
	}
	return 1;

}
