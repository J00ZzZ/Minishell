#include "libft.h"

// Function to join two strings and free the input strings
char *ft_strjoin_free(char *s1, char *s2) {
    char *result;

    if (!s1 && !s2) 
        return NULL; // If both strings are NULL, return NULL
    if (!s1)
        return ft_strdup(s2); // If s1 is NULL, return a duplicate of s2
    if (!s2)
        return ft_strdup(s1); // If s2 is NULL, return a duplicate of s1

    // Allocate memory for the concatenated string
    result = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
    if (!result)
        return NULL; // Return NULL if allocation fails
    // Copy s1 into the result
    ft_strlcpy(result, s1, ft_strlen(s1) + 1);
    // Concatenate s2 to the result
    ft_strlcat(result, s2, ft_strlen(s1) + ft_strlen(s2) + 1);

    // Free the input strings
    free(s1);
    free(s2);

    return result;
}
