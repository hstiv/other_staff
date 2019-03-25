/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 01:20:49 by hstiv             #+#    #+#             */
/*   Updated: 2019/03/24 01:45:56 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void		ft_putchar(char c)
{
	write(1, &c, 1);
}

static void		print_hex(int n)
{
	if (n >= 16)
		print_hex(n / 16);
	if ((n % 16) < 10)
		ft_putchar((n % 16) + 48);
	else
		ft_putchar((n % 16) - 10 + 97);
}

static int		ft_atoi(char *s)
{
	int			res;
	int			i;

	i = 0;
	res = 0;
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i] != '\0')
		i++;
	if (s[i] == '-')
		return (-1);
	if (s[i] == '+')
		i++;
	while (s[i] >= '0' && '9' >= s[i])
	{
		res *= 10;
		res += s[i] - '0';
		i++;
	}
	return (res);
}

int				main(int c, char **s)
{
	int			nb;

	if (c == 2)
	{
		if ((nb = ft_atoi(s[1])) != -1)
			print_hex(nb);
	}
	ft_putchar('\n');
	return (0);
}
