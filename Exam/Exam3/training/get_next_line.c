#include "get_next_line.h"

char *ft_strdup(char *src) {
	int i = 0;
	char *dest;
	while (src[i])
		i++;
	dest = malloc(sizeof(char) * i + 1);
	if (!dest)
		return NULL;
	i = 0;
	while (src[i]) {
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return dest;
}

char *get_next_line(int fd) {
	static int buf_pos = 0, buf_read = 0;
	static char *buf;
	int i = 0;
	char line[70000]
	while (1) {
		if (buf_pos >= buf_read) {
			buf_read = read(fd, buf, BUFFER_SIZE);
			buf_pos = 0;
			if (buf_read == 0)
				break ;
		}
		line[i++] = buf[buf_pos++];
		if (line[i - 1] == '\n')
			break ;
	}
	if (i == 0)
		return NULL;	
	line[i] = 0;
	return (ft_strdup(line));
}
