/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 16:08:45 by hstiv             #+#    #+#             */
/*   Updated: 2019/03/21 17:07:12 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int			ft_check(char *s, int i)
{
	if (((s[i] > 122 && s[i] < 97) && (s[i] < 65 || 90 > s[i]))
				|| s[i] == ' ' || s[i] == '\t' || s[i] == '\0')
		return (0);
	return (1);
}

static void	ft_putstr_ld(char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if ((s[i] >= 65 && s[i] <= 90) && (ft_check(s, i + 1) == 1))
			ft_putchar(s[i] - 'A' + 'a');
		else if ((s[i] >= 97 && s[i] <= 122) && (ft_check(s, i + 1) == 0))
			ft_putchar(s[i] - 'a' + 'A');
		else
			ft_putchar(s[i]);
		i++;
	}
}

int			main(int c, char **s)
{
	int		i;

	i = 1;
	if (c == 1)
	{
		ft_putchar('\n');
		return (0);
	}
	while (s[i] != NULL)
	{
		ft_putstr_ld(s[i]);
		ft_putchar('\n');
		i++;
	}
	return (0);
}
