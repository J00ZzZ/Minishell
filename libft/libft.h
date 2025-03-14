/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harleyng <harleyng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 02:32:56 by hang              #+#    #+#             */
/*   Updated: 2025/03/14 17:05:16 by harleyng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#ifndef checks whether HEADERFILE_H is not declared.
# define will declare HEADERFILE_H once #ifndef generates true.
#endif is to know the scope of #ifndef i.e end of #ifndef
*/

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_isalnum(int x);
int					ft_isascii(int x);
int					ft_isalpha(int x);
int					ft_isdigit(int x);
int					ft_isprint(int x);
int					ft_tolower(int x);
int					ft_toupper(int x);
int					ft_lstsize(t_list *lst);
int					ft_atoi(const char *str);
int					ft_strlen(const char *str);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

void				ft_arrfree(char **arr);
void				ft_bzero(void *s, size_t n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putchar_fd(int c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putstr_fd(char *str, int fd);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));

void				printfputchar(int c, int *length);
void				printfstring(char *str, int *length);
void				printfpointer(uintptr_t ptr, int *length);
void				printfinteger(long numbers, int *length);
void				printfhexadecimal(unsigned long nb, int *length, char xorX);
int					ft_printf(const char *str, ...);

char				*get_next_line(int fd);
char				*cleanline(char *fd_str);
char				*delete_upto_nl(char *fd_str);
char				*readnjoin(int fd, char *fd_str);

char				*ft_itoa(int n);
char				*ft_strdup(const char *src);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strjoin_free(char *s1, char *s2);
void				*ft_calloc(size_t count, size_t size);
char				*ft_strtok(char *str, const char *delim);
void				*ft_memset(void *buffer, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
void				*ft_memmove(void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strtok_r(char *str, const char *delim, char **saveptr);
char				*ft_strjoin_three(char const *s1, char const *s2,
						char const *s3);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);

char				**ft_arrdup(char **arr);
char				**ft_split(char const *s, char set);

t_list				*ft_lstnew(void *content);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);

#endif

/*  @brief Finding the first instance of a character in a string
 *   @param *s : String to search through
 *   @param c : char to find in string
 *   @return Pointer to where charcter was found in string
 */