/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:22:22 by liyu-her          #+#    #+#             */
/*   Updated: 2024/08/31 15:35:23 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <sys/wait.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	char			*str;
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_isalpha(int c);
int					ft_isdigit(int i);
int					ft_isalnum(int i);
int					ft_isascii(int i);
int					ft_isprint(int i);
int					ft_strlen(const char *str);
int					ft_toupper(int i);
int					ft_tolower(int i);
char				*ft_strchr(const char *s, int c);
int					ft_atoi(const char *str);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strdup(const char *s1);
void				*ft_calloc(size_t count, size_t size);
void				ft_putchar_fd(int c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putnbr_fd(int nb, int fd);
void				ft_putendl_fd(char *s, int fd);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_itoa(int n);
char				**ft_split(char const *s, char set);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

/* Get next line */
char				*get_next_line(int fd);
void				create_list(int fd, t_list **bufstr);
int					get_nwl(t_list **bufstr);
char				*get_line(t_list *bufstr);
char				*fill_letter(t_list *bufstr, int len);
t_list				*ft_lastlst(t_list *lst);
int					ft_lstsize(t_list *lst);
void				make_n(t_list **bufstr, char *str);
void				clean_list(t_list **bufstr);
void				ft_addlst_back(t_list **lst, t_list *n);

/* Printf */
int					ft_printf(const char *format, ...);
int					ft_args(va_list args, const char format);
int					my_strlen(const char *str);
int					my_string(char *c);
int					my_putchar(char c);
int					my_putnbr(int nb);
int					my_unputnbr(unsigned int nb);
int					my_hexa(unsigned long nb, char c);
int					my_pointer(void *n);

#endif