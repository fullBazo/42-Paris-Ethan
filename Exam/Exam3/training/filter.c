#includ <unistd.h>
#include <string.h>
#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, int len) {
	int i = 0;
	while (i < len - 1 && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int main(int ac, char **av) {
	if (ac == 2) {

		int i = 0, r = 0, j = 0, len = strlen(av[1]);
		char c;
		char line[10000];

		r = read(0, &c, 1);
		if (r <= 0) {
			perror("Error :");
			return 1;
		}
		while (r) {
			line[i] = c;
			i++;
			r = read(0, &c, 1);
		}
		line[i] = 0;
		i = 0;
		while(line[i]) {
			if (ft_strncmp(av[1], &line[i], len) == 0) {
				j = 0;
				while (j != len) {
					write(1, "*", 1);
					i++;
					j++;
				}
			}
			else
				write(1, &line[i++], 1);
		}
	}
	else
		return 1;

}
