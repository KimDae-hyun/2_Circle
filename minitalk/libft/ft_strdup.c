/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 17:15:23 by daekim            #+#    #+#             */
/*   Updated: 2021/07/16 17:15:24 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s1)
{
	char	*tmp;
	int		len;

	len = ft_strlen(s1);
	tmp = (char *)malloc(sizeof(char) * len + 1);
	if (tmp == 0)
		return (0);
	ft_strlcpy(tmp, s1, len + 1);
	return (tmp);
}
