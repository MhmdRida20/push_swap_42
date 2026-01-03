/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhati <aalkhati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 16:07:14 by aalkhati          #+#    #+#             */
/*   Updated: 2025/11/05 18:27:25 by aalkhati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_start(char const *s1, char const *set)
{
	int	start;

	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
	{
		start++;
	}
	return (start);
}

static int	get_end(char const *s1, char const *set, size_t len)
{
	int	end;

	end = (int)len;
	while (end > 0 && ft_strchr(set, s1[end - 1]))
	{
		end--;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	int		end;
	int		start;
	char	*str;
	int		i;

	if (!s1 || !set)
		return (NULL);
	start = get_start(s1, set);
	end = get_end(s1, set, ft_strlen(s1));
	if (end <= start)
		len = 0;
	else
		len = end - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!s1)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s1[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
// int main()
// {
//	char s[] = "abddbdhadellodddaab";
//	char set[]= "abcd";
//	printf("%s", ft_strtrim(s,set));
// }