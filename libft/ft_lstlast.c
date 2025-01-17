/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: hguerrei <hguerrei@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/04/10 13:10:38 by hguerrei          #+#    #+#             */
/*   Updated: 2024/04/10 13:10:38 by hguerrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*Returns the last node*/
t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}
/*
int main(void)
{
	t_list *node = ft_lstnew("Hello, world!");
	t_list *node2 = ft_lstnew("Hello, world!2");
	t_list *node3 = ft_lstnew("Hello, world!3");
	t_list *last_node;
	ft_lstadd_front(&node, node2);
	ft_lstadd_front(&node, node3);
	last_node = ft_lstlast(node);
	printf("Content of the last node: %s\n", (char *)last_node->content);
	return (0);
}
*/