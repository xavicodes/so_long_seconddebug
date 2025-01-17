/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: hguerrei <hguerrei@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/04/10 13:10:21 by hguerrei          #+#    #+#             */
/*   Updated: 2024/04/10 13:10:21 by hguerrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*Deletes and frees the given node and every
successor of that node
the pointer to the list must be set to
NULL.*/
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*head;
	t_list	*temp;

	if (lst == NULL || del == NULL)
		return ;
	head = *lst;
	while (head)
	{
		temp = head->next;
		(*del)(head->content);
		free(head);
		head = temp;
	}
	*lst = NULL;
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
		ft_lstclear(&node, &free);
	}
	
	return (0);
}
*/