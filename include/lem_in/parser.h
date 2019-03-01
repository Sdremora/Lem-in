/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdremora <sdremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 15:07:19 by hharvey           #+#    #+#             */
/*   Updated: 2019/02/28 17:23:18 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "general.h"

typedef struct	s_connlst
{
	t_list		*conn;
	int			id;
	char		*name;
}				t_connlst;

t_farm			*parser(void);
void			farm_cleaner(t_farm *farm);


#endif
