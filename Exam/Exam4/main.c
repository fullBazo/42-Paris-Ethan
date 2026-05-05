#include <unistd.h>


int main(void)
{
	char *str = 0;

	if (str == 0)
		str = "(null)";

	for (int i = 0; str[i]; ++i)
		write(1, &str[i], 1);
}
