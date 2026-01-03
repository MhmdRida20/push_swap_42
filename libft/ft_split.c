/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhati <aalkhati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 18:13:42 by aalkhati          #+#    #+#             */
/*   Updated: 2025/11/04 19:55:09 by aalkhati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			word++;
		i++;
	}
	if (*s != '\0' && word == 0)
		return (1);
	return (word);
}

static int	ft_strlenc(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

static int	ft_skip(char const *s, char c, int i)
{
	while (s[i] && s[i] == c)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!tab)
		return (NULL);
	i = ft_skip(s, c, 0);
	j = 0;
	while (s[i])
	{
		tab[j] = ft_substr(s, i, ft_strlenc(s + i, c));
		if (!tab[j])
			return (NULL);
		j++;
		i = ft_skip(s, c, i + ft_strlenc(s + i, c));
	}
	tab[j] = NULL;
	return (tab);
}

// int	main(void)
//{
//	char	**result;
//	int		i;
//	char	*s = "   Hello,42,Network,School";
//	char	sep = ',';

//	result = ft_split(s, sep);
//	if (!result)
//	{
//		printf("Allocation failed\n");
//		return (1);
//	}
//	i = 0;
//	while (result[i])
//	{
//		printf("%s\n", result[i]);
//		i++;
//	}
//	return (0);
//}