/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: hguerrei <hguerrei@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/04/10 13:12:31 by hguerrei          #+#    #+#             */
/*   Updated: 2024/04/10 13:12:31 by hguerrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	Iterates through a string,
 enabling character and index manipulation.*/
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, s + i);
		i++;
	}
}
/* void function_f_striteri(unsigned int nr,char *str)
    {
        if(str)
            *str = ft_toupper(*str);
    }

int main()
{
    char str_striteri[10] = "ABCDefgh";

    ft_striteri(str_striteri, function_f_striteri);
    printf("New: %s", str_striteri);
    return 0;
} */
