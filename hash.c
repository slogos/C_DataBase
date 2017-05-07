/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 20:04:16 by dbotova           #+#    #+#             */
/*   Updated: 2017/05/05 15:33:48 by slogos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

static unsigned int	mix(unsigned int internal_state, \
		unsigned int message_block)
{
	return ((internal_state * message_block) ^ \
			((internal_state << 3) + (message_block >> 2)));
}

unsigned int		hash(char *message)
{
	unsigned int	internal_state;
	unsigned int	message_block;
	size_t			message_length;

	internal_state = MAGIC_NUMBER;
	message_block = 0;
	message_length = strlen(message);
	while (message_length >= 4)
	{
		memcpy(&message_block, message, sizeof(unsigned int));
		internal_state = mix(message_block, internal_state);
		message_length -= sizeof(unsigned int);
		message += sizeof(unsigned int);
	}
	if (message_length)
	{
		memcpy(&message_block, message, message_length);
		internal_state = mix(message_block, internal_state);
	}
	return (internal_state % DICTIONARY_SIZE);
}
