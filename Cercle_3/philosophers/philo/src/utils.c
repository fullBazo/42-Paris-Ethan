#include "../philo.h"

bool	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}
bool	is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

char	*valid_arg(char *str)
{
	int		len;
	char	*nb;
	int		i;

	len = 0;
	while (is_space(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		printf("Only positives numbers\n");
		return (NULL);
	}
	i = 0;
	while (str[i])
	{
		if (!is_digit(str[i]))
		{
			printf("Only digits\n");
			return (NULL);
		}
		i++;
	}
	nb = str;
	while (is_digit(*str++))
		len++;
	if (len > 10)
	{
		printf("One numbers is too big\n");
		return (NULL);
	}
	return (nb);
}

long long	ft_atol(char *str)
{
	long long result;

	result = 0;
	str = valid_arg(str);
	if (!str)
		return (-1);
	while (is_digit(*str))
		result = result * 10 + (*str++ - 48);
	if (result > INT_MAX)
		return (-1);
	return (result);
}