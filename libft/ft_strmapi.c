/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: hguerrei <hguerrei@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/04/10 13:12:59 by hguerrei          #+#    #+#             */
/*   Updated: 2024/04/10 13:12:59 by hguerrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	Create a new string by modifying the string with a specified function.*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		i;
	char				*newstr;

	if (!s)
		return (NULL);
	newstr = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		newstr[i] = f(i, s[i]);
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
/* char function_f_mapi(unsigned int i, char c)
    {
        (void)i;
        return(c + 1);
    }
int main()
{
    char *str_strmapi = "AbCd";
    char *result_strmapi = ft_strmapi(str_strmapi, function_f_mapi);
    printf("Origial: %s\n", str_strmapi);
    printf("New: %s\n", result_strmapi);
    free(result_strmapi);
}
 */
