/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlambert <nlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:34:24 by nlambert          #+#    #+#             */
/*   Updated: 2024/10/10 16:58:10 by nlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int count_C(t_data *data)
{
	int i;
	int j;
	int count_c;

	j = 0;
	i = 0;
	count_c = 0;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i] == 'C')
				count_c ++;
			i ++;
		}
		j ++;
	}
	return (count_c);
}
