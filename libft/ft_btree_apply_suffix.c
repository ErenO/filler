/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_suffix.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozdek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 17:36:40 by eozdek            #+#    #+#             */
/*   Updated: 2015/12/03 10:01:51 by eozdek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_apply_suffix(t_btree *root, void (*applyf)(void *))
{
	if (!root)
	{
		if (root->left)
			ft_btree_apply_suffix(root->left, applyf);
		if (root->right)
			ft_btree_apply_suffix(root->right, applyf);
		(*applyf)(root->item);
	}
}
