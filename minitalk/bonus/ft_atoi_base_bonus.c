/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 17:13:47 by daekim            #+#    #+#             */
/*   Updated: 2021/07/16 17:13:48 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sercli_bonus.h"

int	is_valid(char *base)
{
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	return (1);
}

int	is_inbase(char *base, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (base[i])
	{
		if (base[i] == c)
			cnt++;
		i++;
	}
	if (cnt == 0)
		return (0);
	return (1);
}

static int	ft_atoi2(char *str, char *base, int len)
{
	int	i;
	int	j;
	int	sum;

	sum = 0;
	i = 0;
	while (str[i])
	{
		if (!(is_inbase(base, str[i])))
				return (sum);
		j = 0;
		while (base[j])
		{
			if (base[j] == str[i])
				sum = sum * len + j;
			j++;
		}
		i++;
	}
	return (sum);
}

int	ft_atoi_base(char *str, char *base)
{
	int	result;
	int	len;

	if (!(is_valid(base)))
		return (0);
	len = 0;
	while (base[len])
		len++;
	result = ft_atoi2(str, base, len);
	return (result);
}
