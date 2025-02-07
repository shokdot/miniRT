/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:26:24 by healeksa          #+#    #+#             */
/*   Updated: 2025/02/04 23:09:44 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	resolve_sign(char *str, int *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

static double	parse_integer(char *str, int *i)
{
	double	res;

	res = 0.0;
	while (ft_isdigit(str[*i]))
	{
		res *= 10;
		res += str[*i] - '0';
		(*i)++;
	}
	return (res);
}

static double	parse_fraction(char *str, int *i)
{
	double	fraction;
	double	divisor;

	divisor = 10.0;
	fraction = 0.0;
	if (str[*i] && str[*i] == '.')
	{
		(*i)++;
		while (ft_isdigit(str[*i]))
		{
			fraction += (str[*i] - '0') / divisor;
			divisor *= 10.0;
			(*i)++;
		}
		return (fraction);
	}
	return (0);
}

double	ft_atof(char *str)
{
	int		i;
	int		sign;
	double	integer;
	double	fraction;

	integer = 0.0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	sign = resolve_sign(str, &i);
	integer = parse_integer(str, &i);
	fraction = parse_fraction(str, &i);
	return (sign * (integer + fraction));
}
