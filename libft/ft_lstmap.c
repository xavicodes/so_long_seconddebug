/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: hguerrei <hguerrei@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/04/10 13:10:44 by hguerrei          #+#    #+#             */
/*   Updated: 2024/04/10 13:10:44 by hguerrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*Ierates the list and applies the function
’f’ on the content of each node. Creates a new
list resulting of the successive applications of
the function ’f’. The ’del’ function is used to
delete the content of a node if needed.*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*temp;

	head = NULL;
	while (lst)
	{
		temp = ft_lstnew((*f)(lst->content));
		if (!temp)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, temp);
		lst = lst->next;
	}
	return (head);
}
/*
void *add_one(void *content)
{
    int *num = (int *)content;
    int *result = malloc(sizeof(int));
    if (result == NULL)
        return NULL;
    *result = *num + 1;
    return result;
}

void del_int(void *content)
{
    free(content);
}

int main()
{
    // Create some list elements
    int content1 = 10;
    int content2 = 20;
    int content3 = 30;

    t_list *elem1 = ft_lstnew(&content1);
    t_list *elem2 = ft_lstnew(&content2);
    t_list *elem3 = ft_lstnew(&content3);

    elem1->next = elem2;
    elem2->next = elem3;
    elem3->next = NULL;

    t_list *mapped_list = ft_lstmap(elem1, &add_one, &del_int);

    while (mapped_list != NULL)
    {
        printf("%d\n", *(int *)(mapped_list->content));
        mapped_list = mapped_list->next;
    }
    
    ft_lstclear(&elem1, &del_int);
    ft_lstclear(&mapped_list, &del_int);

    return 0;
}
*/