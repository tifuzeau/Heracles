/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 21:19:43 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/16 16:01:18 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*
********************************************************************************
**							INCLUDES                                          **
********************************************************************************
*/

# include "colors.h"

# include <unistd.h>
# include <stdlib.h>
#include <stdio.h>
/*
********************************************************************************
**							DEFINE                                            **
********************************************************************************
*/

# ifndef SUCCESS

#  define SUCCESS	1
#  define FAIL		0

# endif

/*
** for gnl
*/

# define BUFF_SIZE	1024
# define MAX_FD_CALL 128

/*
********************************************************************************
**							STRUCT                                            **
********************************************************************************
*/

# ifndef T_POINT
#  define T_POINT

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

# endif

# ifndef T_SPOINT
#  define T_SPOINT

typedef struct	s_spoint
{
	size_t		x;
	size_t		y;
}				t_spoint;

# endif

# ifndef T_LIST
#  define T_LIST

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

# endif

typedef struct		s_read
{
	int				fd;
	char			*str;
}					t_read;

/*
********************************************************************************
**							FONCTIONS                                         **
********************************************************************************
*/

int				get_next_line(const int fd, char **line);

/*
**	in ft_memset.c
*/
void			*ft_memset(void *b, int c, size_t len);

/*
**	in ft_bzero
*/
void			ft_bzero(void *s, size_t n);

/*
**	in ft_memcpy.c
*/
void			*ft_memcpy(void *dst, const void *src, size_t n);

/*
**	in ft_memccpy.c
*/
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);

/*
**	in ft_memmove.c
*/
void			*ft_memmove(void *dst, const void *src, size_t n);

/*
**	in ft_memchr.c
*/
void			*ft_memchr(const void *src, int c, size_t n);

/*
**	in ft_memcmp.c
*/
int				ft_memcmp(const void *s1, const void *s2, size_t n);

/*
**	in ft_strlen.c
*/
size_t			ft_strlen(const char *s);

/*
**	in ft_strdup.c
*/
char			*ft_strdup(const char *s1);

/*
**	in ft_strcpy.c
*/
char			*ft_strcpy(char *dst, const char *src);

/*
**	in ft_strncpy.c
*/
char			*ft_strncpy(char *dst, const char *src, size_t n);

/*
**	in ft_strcat.c
*/
char			*ft_strcat(char *dst, const char *src);

/*
**	in ft_strncat.c
*/
char			*ft_strncat(char *dst, const char *src, size_t n);

/*
**	in ft_strlcat.c
*/
size_t			ft_strlcat(char *dst, const char *src, size_t size);

/*
**	in ft_strchr.c
*/
char			*ft_strchr(const char *src, char c);

/*
**	in ft_strrchr.c
*/
char			*ft_strrchr(const char *str, char c);

/*
**	in ft_strstr.c
*/
char			*ft_strstr(const char *haystack, const char *needle);

/*
**	in ft_strnstr.c
*/
char			*ft_strnstr(const char *haystack, const char *needle, size_t n);

/*
**	in ft_strcmp.c
*/
int				ft_strcmp(const char *s1, const char *s2);

/*
**	in ft_strncmp.c
*/
int				ft_strncmp(const char *s1, const char *s2, size_t n);

/*
**	in ft_atoi.c
*/
int				ft_atoi(const char *str);

/*
**	in ft_isalpha.c
*/
int				ft_isalpha(int c);

/*
**	in ft_isdigit.c
*/
int				ft_isdigit(int c);

/*
**	in ft_isalnum.c
*/
int				ft_isalnum(int c);

/*
**	in ft_isascii.c
*/
int				ft_isascii(int c);

/*
**	in ft_isprint.c
*/
int				ft_isprint(int c);

/*
**	in ft_toupper
*/
int				ft_toupper(int c);

/*
**	in ft_tolower.c
*/
int				ft_tolower(int c);

/*
**	in ft_memalloc.c
*/
void			*ft_memalloc(size_t size);

/*
**	in ft_memdel.c
*/
void			ft_memdel(void **as);

/*
**	in ft_strnew.c
*/
char			*ft_strnew(size_t size);

/*
**	in ft_strdel.c
*/
void			ft_strdel(char **as);

/*
**	in ft_strclr.c
*/
void			ft_strclr(char *s);

/*
**	in ft_striter.c
*/
void			ft_striter(char *s, void (*f)(char *));

/*
**	in ft_striter.c
*/
void			ft_striteri(char *s, void (*f)(unsigned int, char *));

/*
**	in ft_strmap.c
*/
char			*ft_strmap(char const *s, char (*f)(char));

/*
**	in ft_strmapi.c
*/
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/*
**	in ft_strequ.c
*/
int				ft_strequ(char const *s1, char const *s2);

/*
**	in ft_strnequ.c
*/
int				ft_strnequ(char const *s1, char const *s2, size_t n);

/*
**	in ft_strsub.c
*/
char			*ft_strsub(char const *s, unsigned int start, size_t len);

/*
**	in ft_strjoin.c
*/
char			*ft_strjoin(char const *s1, char const *s2);

/*
**	in ft_strtrim.c
*/
char			*ft_strtrim(char const *s);

/*
**	in ft_strsplit.c
*/
char			**ft_strsplit(char const *s, char c);

/*
**	in ft_itoa.c
*/
char			*ft_itoa(int n);

/*
**	in ft_putchar.c
*/
void			ft_putchar(char c);

/*
**	in ft_putstr.c
*/
void			ft_putstr(char const *s);

/*
**	in ft_putendl.c
*/
void			ft_putendl(char const *s);

/*
**	in ft_putnbr.c
*/
void			ft_putnbr(int n);

/*
**	in ft_putchar_fd.c
*/
void			ft_putchar_fd(char c, int fd);

/*
**	in ft_putstr_fd.c
*/
void			ft_putstr_fd(char const *s, int fd);

/*
**	in ft_putendl_fd.c
*/
void			ft_putendl_fd(char const *s, int fd);

/*
**	in ft_putnbr_fd.c
*/
void			ft_putnbr_fd(int n, int fd);

/*
**			LST
*/

/*
**	in ft_lstnew.c
*/
t_list			*ft_lstnew(void const *content, size_t content_size);

/*
**	in ft_lstdelone.c
*/
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));

/*
**	in ft_lstdel.c
*/
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));

/*
**	in ft_lstadd.c
*/
void			ft_lstadd(t_list **alst, t_list *new);

/*
**	in ft_lstiter.c
*/
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));

/*
**	in ft_lstmap.c
*/
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
********************************************************************************
**							ADD FONCTIONS                                     **
********************************************************************************
*/

/*
**			IS
*/

/*
**	in ft_isalspace.c
*/
int				ft_isalspace(int c);

/*
**	in ft_str_isalpha.c
*/
int				ft_str_isalpha(const char *str);

/*
**	in ft_str_isdigit.c
*/
int				ft_str_isdigit(const char *str);

/*
**	in ft_str_isin.c
*/
int				ft_str_isin(const char *str, char c);

/*
**				OTHER
*/

/*
**	in ft_sizeint.c
*/
size_t			ft_sizeint(int n);

/*
**	in ft_memdup.c
*/
void			*ft_memdup(void const *content, size_t size);

/*
**	in ft_strndup.c
*/
char			*ft_strndup(const char *s1, size_t n);

/*
**	in ft_swap.c
*/
void			ft_swap(char *s1, char *s2);

/*
**	in ft_vswap.c
*/
void			ft_vswap(void **pt_1, void **pt_2);

/*
**	in ft_strjoin_free.c
*/
char			*ft_strjoin_free(char **as, const char *s2);

/*
**	in ft_strsplit_free.c
*/
char			**ft_strsplit_free(char **as, char c);

/*
**	in ft_strnclr.c
*/
void			ft_strnclr(char *str, size_t n);

/*
**	in ft_valide_base.c
*/
int				ft_valide_base(char *base, int size_base);

/*
**	in ft_putnbr_base.c
*/
void			ft_putnbr_base(int nbr, char *base);

/*
**					STR_2D
*/

/*
**	in ft_strnew_2d.c
*/
char			**ft_strnew_2d(size_t len);

/*
**	in ft_putstr_2d.c
*/
void			ft_putstr_2d(const char **str);

/*
**	in ft_putendl_2d.c
*/
void			ft_putendl_2d(const char **str);

/*
**	in ft_strdel_2d.c
*/
void			ft_strdel_2d(char ***as);

/*
**	in ft_strdup_2d.c
*/
char			**ft_strdup_2d(const char **str);

/*
**	in ft_strequ_2d.c
*/
int				ft_strequ_2d(const char **s1, const char **s2);

/*
**	in ft_strlen_2d.c
*/
size_t			ft_strlen_2d(const char **str);

/*
**	in ft_putstr_2dfd.c
*/
void			ft_putstr_2dfd(const char **str, int fd);

#endif
