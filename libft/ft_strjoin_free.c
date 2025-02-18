#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*result;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	result = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, ft_strlen(s1) + 1);
	ft_strlcat(result, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	free(s1);
	free(s2);
	return (result);
}
