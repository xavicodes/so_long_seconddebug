/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: hguerrei <hguerrei@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/04/10 13:10:12 by hguerrei          #+#    #+#             */
/*   Updated: 2024/04/10 13:10:12 by hguerrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*Adds the node  at the beggening of the list*/
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
	{
		return ;
	}
	new->next = *lst;
	*lst = new;
}
/*
int main(void)
{
	t_list *node = ft_lstnew("Hello, world!");
	t_list *node2 = ft_lstnew("Hello, world!2");
	t_list *node3 = ft_lstnew("Hello, world!3");
	ft_lstadd_front(&node, node2);
	ft_lstadd_front(&node, node3);
	while (node)
	{
		printf("Content of the node: %s\n", (char *)node->content);
		node = node->next;
	}
	return (0);
}
*/