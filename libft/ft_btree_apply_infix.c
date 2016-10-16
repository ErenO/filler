/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_infix.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 17:24:24 by eozdek            #+#    #+#             */
/*   Updated: 2015/12/03 10:01:22 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_apply_infix(t_btree *root, void (*applyf)(void *))
{
	if (!root)
	{
		if (root->left)
			ft_btree_apply_infix(root->left, applyf);
		(*applyf)(root->item);
		if (root->right)
			ft_btree_apply_infix(root->right, applyf);
	}
}
