/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: hguerrei <hguerrei@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/04/10 13:10:05 by hguerrei          #+#    #+#             */
/*   Updated: 2024/04/10 13:10:05 by hguerrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*Adds a new node at the end of a linked list.*/
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = ft_lstlast(*lst);
	if (!temp)
	{
		*lst = new;
	}
	else
	{
		temp->next = new;
	}
}
/*
int main(void)
{
	t_list *node = ft_lstnew("Hello, world!");
	t_list *node2 = ft_lstnew("Hello, world!2");
	t_list *node3 = ft_lstnew("Hello, world!3");
	ft_lstadd_back(&node, node2);
	ft_lstadd_back(&node, node3);
	while (node)
	{
		printf("Content of the node: %s\n", (char *)node->content);
		node = node->next;
	}
	return (0);
}
*/
