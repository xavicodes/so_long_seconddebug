/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: hguerrei <hguerrei@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/04/10 13:10:26 by hguerrei          #+#    #+#             */
/*   Updated: 2024/04/10 13:10:26 by hguerrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*Deletes a node of a list*/
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	(*del)(lst->content);
	free(lst);
}

/*
int main(void)
{
	t_list *node = ft_lstnew("Hello, world!");
			
	printf("Before deletion: %s\n", (char *)node->content);

	// Delete the node
	ft_lstdelone(node, &free);

	printf("After deletion: %s\n", (char *)node->content);

	return 0;
}
*/