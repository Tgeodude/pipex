#include <stdlib.h>

static size_t	ft_quantity(char const *s, char c)
{
	size_t	k;
	size_t	i;

	k = 0;
	i = 0;
	while (s[i])
	{
		while ((s[i] == c || s[i] == 39) && s[i])
			i++;
		if (!s[i])
			return (k);
		while ((s[i] != c && s[i] != 39) && s[i])
			i++;
		k++;
	}
	return (k);
}

static size_t	ft_word(char const *s, char c)
{
	size_t	i;
	size_t	j;


	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
		{
			i++;
			j++;
		}
		if (s[i] == 39)
		{
			i++;
			while (s[i] != 39 && s[i])
				i++;
			return (i - j);
		}
		while (s[i] != c && s[i])
			i++;
		return (i - j);
	}
	return (0);
}

static void	*ft_free(char **s1)
{
	size_t	i;

	i = -1;
	while (i++, s1[i])
		free(s1[i]);
	free(s1);
	return (NULL);
}

static void	*ft_splt(char const *s, char c, char **s1, size_t j)
{
	size_t	k;
	size_t	i;
	size_t	flag;

	k = -1;
	flag = 1;
	while (k++, k < j)
	{
		i = -1;
		s1[k] = malloc((ft_word(s, c) + 1));
		if (!s1[k])
			return (ft_free(s1));
		flag = 0;
		while (i++, i < ft_word(s, c))
		{
			while (*s == c && *s && !flag)
				s++;
			if (*s == 39 && *s && !flag)
				flag = 1;
			if (s[i + flag] != 39)
				s1[k][i] = s[i + flag];
		}
		s1[k][i] = '\0';
		if (flag)
		{
			s++;
			while (*s != 39 && *s)
				s++;
		}
		while (*s != c && *s)
			s++;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**s1;
	size_t	j;

	if (!s)
		return (NULL);
	j = ft_quantity(s, c);
	s1 = malloc((j + 1) * sizeof(char *));
	if (!s1)
		return (NULL);
	ft_splt(s, c, s1, j);
	s1[j] = NULL;
	return (s1);
}

#include <stdio.h>
int main()
{
    char    **s;
    int i;

    i = -1;
    s = ft_split("kek lol 'a' 'chek' ", ' ');
    while (i++, s[i])
        printf("%s\n", s[i]);
    return (0);
}