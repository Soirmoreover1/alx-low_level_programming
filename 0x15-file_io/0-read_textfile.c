#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Read text file print to STDOUT.
 *
 * @filename: text file being read
 *
 * @letters: num of letters to be read
 *
 * Return: q- actual num of bytes read and printed
 *
 *        0 when function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t fs;
	ssize_t q;
	ssize_t p;

	fs = open(filename, O_RDONLY);
	if (fs == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	p = read(fs, buf, letters);
	q = write(STDOUT_FILENO, buf, p);

	free(buf);
	close(fs);
	return (q);
}
