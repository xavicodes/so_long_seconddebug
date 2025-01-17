/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: hguerrei <hguerrei@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/04/10 13:10:32 by hguerrei          #+#    #+#             */
/*   Updated: 2024/04/10 13:10:32 by hguerrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*Iterates the list and applies the function
’f’ on the content of each node.
*/
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst != NULL)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}
/*
void print_list_contents(void *content) {
    printf("%s\n", (char *)content);
}

int main(void) {
    t_list *head = NULL;

    ft_lstadd_back(&head, ft_lstnew("Primeiro nó"));
    ft_lstadd_back(&head, ft_lstnew("Segundo nó"));
    ft_lstadd_back(&head, ft_lstnew("Terceiro nó"));

    // Imprimindo o conteúdo da lista usando ft_lstiter
    printf("Conteúdo da lista:\n");
    ft_lstiter(head, &print_list_contents);

    return 0;
}
*/