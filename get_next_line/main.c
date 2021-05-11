#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
	int fd, fd2, fd3;
	char *line;

	fd = open("text.txt", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
		printf("%s\n", line);
	close(fd);
	fd = open("text.txt", O_RDONLY);
	fd2 = open("test.txt", O_RDONLY);
	fd3 = open("test3.txt", O_RDONLY);
	get_next_line(fd3, &line);
	printf("%s\n", line);
	get_next_line(fd2, &line);
	printf("%s\n", line);
	while (get_next_line(fd, &line) > 0)
		printf("%s\n", line);
	close(fd);
	while (get_next_line(fd2, &line) > 0)
		printf("%s\n", line);
	close(fd2);
	close(fd3);
}