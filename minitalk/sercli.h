/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sercli.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 17:13:05 by daekim            #+#    #+#             */
/*   Updated: 2021/07/16 17:13:07 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERCLI_H
# define SERCLI_H

# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <signal.h>
# include "./libft/libft.h"

# include <sys/time.h>

int		ft_atoi_base(char *str, char *base);

#endif
