#include "libft.h"
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>

bool	test_memset(void)
{
	char	buf[1024];
	int		i;

	ft_memset(buf, 2, 1024);
	i = 0;
	while (i < 1024)
		if (buf[i++] != 2)
			return (false);

	ft_memset(buf, 0, 512);
	i = 0;
	while (i < 512)
		if (buf[i++] != 0)
			return (false);
	while (i < 1024)
		if (buf[i++] != 2)
			return (false);
	
	ft_memset(buf, 5, 0);
	i = 0;
	while (i < 512)
		if (buf[i++] != 0)
			return (false);
	while (i < 1024)
		if (buf[i++] != 2)
			return (false);
	return (true);
}

bool	test_bzero(void)
{
	char	buf[1024];
	int		i;

	memset(buf + 512, 2, 512);
	ft_bzero(buf, 512);
	i = 0;
	while (i < 512)
		if (buf[i++] != 0)
			return (false);
	while (i < 1024)
		if (buf[i++] != 2)
			return (false);

	ft_bzero(buf, 1024);
	i = 0;
	while (i < 1024)
		if (buf[i++] != 0)
			return (false);
	return (true);
}

bool	test_memcpy(void)
{
	char	buf[512];
	char	buf2[512];
	char	src1[512];
	char	src2[512];
	int		i;

	i = 0;
	while (i < 512)
	{
		src1[i] = rand() % 256;
		src2[i++] = rand() % 256;
	}
	ft_memcpy(buf, src1, 512);
	memcpy(buf2, src1, 512);
	if (memcmp(buf, buf2, 512) != 0)
		return (false);

	ft_memcpy(buf, src2, 0);
	memcpy(buf2, src2, 0);
	if (memcmp(buf, buf2, 512) != 0)
		return (false);
	return (true);
}

bool	test_memccpy(void)
{
	char	buf[1024];
	char	buf2[1024];
	char	*end;
	char	*p;
	char	*p2;

	end = buf + sizeof(buf);
	p = ft_memccpy(buf, "Hello ", '\0', sizeof(buf));
	p2 = memccpy(buf2, "Hello ", '\0', sizeof(buf2));
	if (p)
	{
		p = ft_memccpy(p - 1, "", '\0', end - p);
		p2 = memccpy(p2 - 1, "", '\0', end - p2);
	}
	if (p)
	{
		p = ft_memccpy(p - 1, "world", '\0', end - p);
		p2 = memccpy(p2 - 1, "world", '\0', end - p2);
	}
	if (p)
	{
		p = ft_memccpy(p - 1, "!!!", '\0', end - p);
		p2 = memccpy(p2 - 1, "!!!", '\0', end - p2);
	}
	if (strcmp(buf, buf2) != 0)
		return (false);
	return (true);
}

bool	test_memmove(void)
{
	const char	src[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	char		buf[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	char		buf2[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	ft_memmove(buf, buf + 2, 8);
	memmove(buf2, buf2 + 2, 8);
	if (memcmp(buf, buf2, 10) != 0)
		return (false);

	memcpy(buf, src, 10);
	memcpy(buf2, src, 10);

	ft_memmove(buf + 2, buf, 8);
	memmove(buf2 + 2, buf2, 8);
	if (memcmp(buf, buf2, 10) != 0)
		return (false);
	return (true);
}

bool	test_memchr(void)
{
	char	buf[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	char	*p;

	p = ft_memchr(buf, 7, 10);
	if (p != memchr(buf, 7, 10))
		return (false);

	p = ft_memchr(buf, 3, 10);
	if (p != memchr(buf, 3, 10))
		return (false);

	p = ft_memchr(buf, 3 + 256, 10);
	if (p != memchr(buf, 3 + 256, 10))
		return (false);
	return (true);
}

bool	test_memcmp(void)
{
	char	src[512];
	char	buf1[512];
	char	buf2[512];
	int		i;

	i = 0;
	while (i < 512)
		src[i++] = rand() % 256;
	memcpy(buf1, src, 512);
	memcpy(buf2, src, 512);
	if (ft_memcmp(buf1, buf2, 512) != memcmp(buf1, buf2, 512))
		return (false);

	src[5] = 3;
	buf1[5] = 0;
	buf2[5] = 0;
	if (ft_memcmp(buf1, src, 512) != memcmp(buf1, src, 512))
		return (false);

	src[5] = 45;
	buf1[5] = 123;
	buf2[5] = 123;
	if (ft_memcmp(buf1, src, 512) != memcmp(buf1, src, 512))
		return (false);
	return (true);
}

bool	test_strlen(void)
{
	char	*str1 = "Hello World!";
	char	*str2 = "Ddgd dfg adjk\t\\ fdkd f\n ssd qwey45 ";
	char	*str3 = "";

	if (ft_strlen(str1) != strlen(str1))
		return (false);

	if (ft_strlen(str2) != strlen(str2))
		return (false);

	if (ft_strlen(str3) != strlen(str3))
		return (false);
	return (true);
}

bool	test_is_x(int (*ft)(int), int (*c_ft)(int))
{
	int	res1;
	int	res2;
	int	c;

	c = 0;
	while (c < 256)
	{
		res1 = (*ft)(c);
		res2 = (*c_ft)(c++);
		if ((res1 && !res2) || (!res1 && res2))
			return (false);
	}
	return (true);
}

bool	test_isalpha(void)
{
	return (test_is_x(ft_isalpha, isalpha));
}

bool	test_isdigit(void)
{
	return (test_is_x(ft_isdigit, isdigit));
}

bool	test_isalnum(void)
{
	return (test_is_x(ft_isalnum, isalnum));
}

bool	test_isascii(void)
{
	return (test_is_x(ft_isascii, isascii));
}

bool	test_isprint(void)
{
	return (test_is_x(ft_isprint, isprint));
}

bool	test_toupper(void)
{
	int	c = 0;
	while (c < 256)
	{
		if (ft_toupper(c) != toupper(c))
			return (false);
		c++;
	}
	return (true);
}

bool	test_tolower(void)
{
	int	c = 0;
	while (c < 256)
	{
		if (ft_tolower(c) != tolower(c))
			return (false);
		c++;
	}
	return (true);
}

bool	test_strchr(void)
{
	char	*str = "Hello World!";

	if (ft_strchr(str, 'l') != strchr(str, 'l'))
		return (false);

	if (ft_strchr(str, ' ') != strchr(str, ' '))
		return (false);

	if (ft_strchr(str, '\0') != strchr(str, '\0'))
		return (false);

	if (ft_strchr(str, '!') != strchr(str, '!'))
		return (false);

	if (ft_strchr("", '!') != strchr("", '!'))
		return (false);

	if (ft_strchr(str, 'H' + 256) != strchr(str, 'H' + 256))
		return (false);
	return (true);
}

bool	test_strrchr(void)
{
	char	*str = "Hello World!";

	if (ft_strrchr(str, 'l') != strrchr(str, 'l'))
		return (false);

	if (ft_strrchr(str, 'o') != strrchr(str, 'o'))
		return (false);

	if (ft_strrchr(str, '\0') != strrchr(str, '\0'))
		return (false);

	if (ft_strrchr(str, 'H') != strrchr(str, 'H'))
		return (false);

	if (ft_strrchr("", 'H') != strrchr("", 'H'))
		return (false);

	if (ft_strrchr(str, 'H' + 256) != strrchr(str, 'H' + 256))
		return (false);
	
	return (true);
}

bool	test_strncmp(void)
{
	char	*str = "Hello World!";
	
	if (ft_strncmp(str, "Hello!", 5) != strncmp(str, "Hello!", 5))
		return (false);

	if (ft_strncmp(str, "Hello", 10) != strncmp(str, "Hello", 10))
		return (false);

	if (ft_strncmp(str, "Hello there", 10) != strncmp(str, "Hello there", 10))
		return (false);

	if (ft_strncmp(str, "World", 0) != strncmp(str, "World", 0))
		return (false);

	if (ft_strncmp("", "World", 0) != strncmp("", "World", 0))
		return (false);

	if (ft_strncmp(&"Hello, everybody!"[12], &"Hello, somebody!"[11], 5)
		!= strncmp(&"Hello, everybody!"[12], &"Hello, somebody!"[11], 5))
		return (false);
	return (true);
}

bool	test_strlcpy(void)
{
	const char	*str = "Hello World!";
	char		buf[1024];
	char		buf2[1024];
	size_t		len;
	size_t		len2;
	
	len = ft_strlcpy(buf, str, 1024);
	len2 = strlcpy(buf2, str, 1024);
	if (strcmp(buf, buf2) != 0 || len != len2)
		return (false);

	len = ft_strlcpy(buf, str, 0);
	len2 = strlcpy(buf2, str, 0);
	if (strcmp(buf, buf2) != 0 || len != len2)
		return (false);

	len = ft_strlcpy(buf, str, 6);
	len2 = strlcpy(buf2, str, 6);
	if (strcmp(buf, buf2) != 0 || len != len2)
		return (false);

	len = ft_strlcpy(buf, "", 6);
	len2 = strlcpy(buf2, "", 6);
	if (strcmp(buf, buf2) != 0 || len != len2)
		return (false);
	return (true);
}

bool	test_strlcat(void)
{
	char	*str = "Hello World!";
	char	buf[1024] = "Hello";
	char	buf2[1024] = "Hello";
	size_t	len;
	size_t	len2;

	len = ft_strlcat(buf, " World!", 1024);
	len2 = strlcat(buf2, " World!", 1024);
	if (len != len2 || strcmp(buf, buf2) != 0)
		return (false);

	strcpy(buf, "Hello");
	strcpy(buf2, "Hello");

	len = ft_strlcat(buf, " World!", 12);
	len2 = strlcat(buf2, " World!", 12);
	if (len != len2 || strcmp(buf, buf2) != 0)
		return (false);

	strcpy(buf, "Hello");
	strcpy(buf2, "Hello");

	len = ft_strlcat(buf, " World!", 0);
	len2 = strlcat(buf2, " World!", 0);
	if (len != len2 || strcmp(buf, buf2) != 0)
		return (false);
	
	len = ft_strlcat(buf, " World!", 6);
	len2 = strlcat(buf2, " World!", 6);
	if (len != len2 || strcmp(buf, buf2) != 0)
		return (false);

	strcpy(buf, "Hello");
	strcpy(buf2, "Hello");

	len = ft_strlcat(buf, " World!", 5);
	len2 = strlcat(buf2, " World!", 5);
	if (len != len2 || strcmp(buf, buf2) != 0)
		return (false);

	strcpy(buf, "");
	strcpy(buf2, "");

	len = ft_strlcat(buf, " World!", 5);
	len2 = strlcat(buf2, " World!", 5);
	if (len != len2 || strcmp(buf, buf2) != 0)
		return (false);
	return (true);
}

char	*strnstr(const char *s, const char *find, size_t slen)
{
	char c, sc;
	size_t len;

	if ((c = *find++) != '\0') {
		len = strlen(find);
		do {
			do {
				if (slen-- < 1 || (sc = *s++) == '\0')
					return (NULL);
			} while (sc != c);
			if (len > slen)
				return (NULL);
		} while (strncmp(s, find, len) != 0);
		s--;
	}
	return ((char *)s);
}

bool	test_strnstr(void)
{
	char	*haystack = "Foo Bar Baz Bed";

	if (ft_strnstr(haystack, "Bed", strlen(haystack)) != strnstr(haystack, "Bed", strlen(haystack)))
		return (false);

	if (ft_strnstr(haystack, "", strlen(haystack)) != strnstr(haystack, "", strlen(haystack)))
		return (false);

	if (ft_strnstr(haystack, "Bad", strlen(haystack)) != strnstr(haystack, "Bad", strlen(haystack)))
		return (false);

	if (ft_strnstr(haystack, "Baz", 11) != strnstr(haystack, "Baz", 11))
		return (false);

	if (ft_strnstr(haystack, "Baz", 10) != strnstr(haystack, "Baz", 10))
		return (false);

	if (ft_strnstr(haystack, "Foo", 3) != strnstr(haystack, "Foo", 3))
		return (false);

	if (ft_strnstr(haystack, "Foo", 0) != strnstr(haystack, "Foo", 0))
		return (false);

	if (ft_strnstr("", "Foo", 3) != strnstr("", "Foo", 3))
		return (false);
	return (true);
}

bool	test_atoi(void)
{
	if (ft_atoi("\t\n\r   1234567  \t234") != atoi("\t\n\r   1234567  \t234"))
		return (false);

	if (ft_atoi("  \t\n   \r\t ") != atoi("  \t\n   \r\t "))
		return (false);

	if (ft_atoi("  \t\n   \r000000\t ") != atoi("  \t\n   \r000000\t "))
		return (false);

	if (ft_atoi("  \t\n   \r-00000056\t ") != atoi("  \t\n   \r-00000056\t "))
		return (false);
	return (true);
}

bool	test_strdup(void)
{
	char	*str;
	char	*str2;
	
	str = ft_strdup("Hello World!");
	str2 = strdup("Hello World!");
	if (strcmp(str, "Hello World!") != 0)
		return (false);
	free(str);
	free(str2);

	str = ft_strdup("This a big long long long long long long long long long long long long long long long long long long long long long long long long long long long long string");
	str2 = ft_strdup("This a big long long long long long long long long long long long long long long long long long long long long long long long long long long long long string");
	if (strcmp(str, str2) != 0)
		return (false);
	free(str);
	free(str2);

	str = ft_strdup("");
	str2 = ft_strdup("");
	if (strcmp(str, str2) != 0)
		return (false);
	free(str);
	free(str2);
	return (true);
}

bool	test_calloc(void)
{
	void	*ptr1;
	void	*ptr2;

	ptr1 = ft_calloc(512, 1); 
	ptr2 = calloc(512, 1);
	if (memcmp(ptr1, ptr2, 512) != 0)
		return (false);
	free(ptr1);
	free(ptr2);

	ptr1 = ft_calloc(0, 8); 
	ptr2 = calloc(0, 8);
	if (memcmp(ptr1, ptr2, 1) != 0)
		return (false);
	free(ptr1);
	free(ptr2);

	ptr1 = ft_calloc(8, 0); 
	ptr2 = calloc(8, 0);
	if (memcmp(ptr1, ptr2, 1) != 0)
		return (false);
	free(ptr1);
	free(ptr2);
	return (true);
}

bool	test_substr(void)
{
	char	*str = "Hello World!";
	char	*substr;

	substr = ft_substr(str, 6, 6);
	if (strcmp(substr, "World!") != 0)
		return (false);
	free(substr);

	substr = ft_substr(str, 2, 4);
	if (strcmp(substr, "llo ") != 0)
		return (false);
	free(substr);

	substr = ft_substr(str, 8, 0);
	if (strcmp(substr, "") != 0)
		return (false);
	free(substr);

	substr = ft_substr(str, 400, 6);
	if (strcmp(substr, "") != 0)
		return (false);
	free(substr);

	substr = ft_substr("", 0, 6);
	if (strcmp(substr, "") != 0)
		return (false);
	free(substr);
	return (true);
}

bool	test_strjoin(void)
{
	char	*str1 = "Hello";
	char	*str2 = " World!";
	char	*newstr;

	newstr = ft_strjoin(str1, str2);
	if (strcmp(newstr, "Hello World!") != 0)
		return (false);
	free(newstr);

	newstr = ft_strjoin(str1, "");
	if (strcmp(newstr, "Hello") != 0)
		return (false);
	free(newstr);

	newstr = ft_strjoin("", str2);
	if (strcmp(newstr, " World!") != 0)
		return (false);
	free(newstr);
	return (true);
}

bool	test_strtrim(void)
{
	char	*trimmed;

	trimmed = ft_strtrim("  Hello World!   ", " ");
	if (strcmp(trimmed, "Hello World!") != 0)
		return (false);
	free(trimmed);

	trimmed = ft_strtrim("Hello World!", " ");
	if (strcmp(trimmed, "Hello World!") != 0)
		return (false);
	free(trimmed);

	trimmed = ft_strtrim("1233212312211Hello World!", "123l ");
	if (strcmp(trimmed, "Hello World!") != 0)
		return (false);
	free(trimmed);

	trimmed = ft_strtrim("Hello World!1233212312211", "123l ");
	if (strcmp(trimmed, "Hello World!") != 0)
		return (false);
	free(trimmed);
	
	trimmed = ft_strtrim("1233212312211Hello World!1233212312211", "123 ll");
	if (strcmp(trimmed, "Hello World!") != 0)
		return (false);
	free(trimmed);

	trimmed = ft_strtrim("12332123122111233212312211", "12345678");
	if (strcmp(trimmed, "") != 0)
		return (false);
	free(trimmed);

	trimmed = ft_strtrim("", "12345678");
	if (strcmp(trimmed, "") != 0)
		return (false);
	free(trimmed);
	return (true);
}

bool	test_split(void)
{
	char	*str = " Hello World Split This Big String    Please I Beg You";
	char	*ans1[] = { "Hello", "World", "Split", "This", "Big", "String", "Please", "I", "Beg", "You" };
	char	*str2 = " Hello World Split This Big String    Please I Beg You ";
	char	*ans2[] = { "Hello", "World", "Split", "This", "Big", "String", "Please", "I", "Beg", "You" };
	char 	**split;
	size_t	i;

	split = ft_split(str, ' ');
	i = 0;
	while (split[i] != NULL)
	{
		if (strcmp(split[i], ans1[i]) != 0)
			return (false);
		i++;
	}
	if (i != 10)
		return (false);
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);

	split = ft_split(str2, ' ');
	i = 0;
	while (split[i] != NULL)
	{
		if (strcmp(split[i], ans2[i]) != 0)
			return (false);
		i++;
	}
	if (i != 10)
		return (false);
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);

	split = ft_split("1", '1');
	if (split[0] != NULL)
		return (false);
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
	return (true);
}

bool	test_itoa(void)
{
	char	*str;

	str = ft_itoa(-340020000);
	if (strcmp(str, "-340020000") != 0)
		return (false);
	free(str);

	str = ft_itoa(340020000);
	if (strcmp(str, "340020000") != 0)
		return (false);
	free(str);

	str = ft_itoa(INT_MAX);
	if (strcmp(str, "2147483647") != 0)
		return (false);
	free(str);

	str = ft_itoa(INT_MIN);
	if (strcmp(str, "-2147483648") != 0)
		return (false);
	free(str);

	str = ft_itoa(0);
	if (strcmp(str, "0") != 0)
		return (false);
	free(str);

	return (true);
}

char	alternate_case(unsigned int i, char c)
{
	if (i % 2 != 0)
		return (ft_tolower(c));
	else
		return (ft_toupper(c));
}

char	alternate_erase(unsigned int i, char c)
{
	if (i % 2 != 0)
		return (' ');
	else
		return (c);
}

bool	test_strmapi(void)
{
	char	*str = "hello world!!";
	char	*mapped;

	mapped = ft_strmapi(str, alternate_case);
	if (strcmp(mapped, "HeLlO WoRlD!!") != 0)
		return (false);
	free(mapped);

	mapped = ft_strmapi(str, alternate_erase);
	if (strcmp(mapped, "h l o w r d !") != 0)
		return (false);
	free(mapped);
	return (true);
}

bool	test_lstnew(void)
{
	t_list	*node;

	node = ft_lstnew("Hello World!");
	if (strcmp(node->content, "Hello World!") != 0 || node->next)
		return (false);
	free(node);
	return (true);
}

t_list	*ft_lstnewone(void *content)
{
	t_list	*node;

	node = (t_list *)ft_calloc(1, sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

bool	test_lstadd_front(void)
{
	t_list	*lst = NULL;

	ft_lstadd_front(&lst, ft_lstnewone("Hello"));
	ft_lstadd_front(&lst, ft_lstnewone("World"));
	ft_lstadd_front(&lst, ft_lstnewone("!"));
	if (strcmp(lst->content, "!") != 0 
		|| strcmp(lst->next->content, "World") != 0
		|| strcmp(lst->next->next->content, "Hello") != 0
		|| lst->next->next->next)
		return (false);
	return (true);
}

bool	test_lstadd_back(void)
{
	t_list	*lst = NULL;
	t_list	*lst1 = NULL;

	ft_lstadd_back(&lst, ft_lstnewone("Hello"));
	ft_lstadd_back(&lst, ft_lstnewone("World"));
	ft_lstadd_back(&lst, ft_lstnewone("!"));
	if (strcmp(lst->content, "Hello") != 0 
		|| strcmp(lst->next->content, "World") != 0
		|| strcmp(lst->next->next->content, "!") != 0
		|| lst->next->next->next)
		return (false);

	lst = NULL;
	ft_lstadd_back(&lst, ft_lstnewone("Hello"));
	ft_lstadd_back(&lst1, ft_lstnewone("World"));
	ft_lstadd_back(&lst1, ft_lstnewone("!"));
	ft_lstadd_back(&lst, lst1);
	if (strcmp(lst->content, "Hello") != 0 
		|| strcmp(lst->next->content, "World") != 0
		|| strcmp(lst->next->next->content, "!") != 0
		|| lst->next->next->next)
		return (false);
	return (true);
}

bool	test_lstdelone(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	node1 = ft_lstnewone(strdup("Hello World!"));
	node2 = ft_lstnewone(strdup("Hello"));
	node3 = ft_lstnewone(strdup("World!"));
	node1->next = node2;
	node2->next = node3;
	ft_lstdelone(node2, free);
	if (strcmp(node1->content, "Hello World!") != 0
		|| strcmp(node3->content, "World!") != 0)
		return (false);
	ft_lstdelone(NULL, free);
	return (true);
}

bool	test_lstclear(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	node1 = ft_lstnewone(strdup("Hello World!"));
	node2 = ft_lstnewone(strdup("Hello"));
	node3 = ft_lstnewone(strdup("World!"));
	node1->next = node2;
	node2->next = node3;
	ft_lstclear(&node1->next, free);
	if (strcmp(node1->content, "Hello World!") != 0 || node1->next)
		return (false);
	ft_lstclear(&node1, free);
	if (node1)
		return (false);
	node1 = NULL;
	ft_lstclear(&node1, free);
	ft_lstclear(NULL, free);
	return (true);
}

bool	test_lstlast(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	node1 = ft_lstnewone(strdup("Hello World!"));
	node2 = ft_lstnewone(strdup("Hello"));
	node3 = ft_lstnewone(strdup("World!"));
	node1->next = node2;
	node2->next = node3;
	if (ft_lstlast(node1) != node3)
		return (false);
	if (ft_lstlast(NULL) != NULL)
		return (false);
	return (true);
}

bool	test_lstsize(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	node1 = ft_lstnewone(strdup("Hello World!"));
	node2 = ft_lstnewone(strdup("Hello"));
	node3 = ft_lstnewone(strdup("World!"));
	node1->next = node2;
	node2->next = node3;
	if (ft_lstsize(node1) != 3)
		return (false);
	if (ft_lstsize(NULL) != 0)
		return (false);
	return (true);
}

void	iter(void *content)
{
	char	*str;

	str = (char *)content;
	while (*str)
		*str++ = 'A';
}

bool	test_lstiter(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	node1 = ft_lstnewone(strdup("Hello"));
	node2 = ft_lstnewone(strdup("World!"));
	node3 = ft_lstnewone(strdup("!"));
	node1->next = node2;
	node2->next = node3;
	ft_lstiter(node1, iter);

	if (strcmp(node1->content, "AAAAA") != 0)
		return (false);
	if (strcmp(node2->content, "AAAAAA") != 0)
		return (false);
	if (strcmp(node3->content, "A") != 0)
		return (false);
	return (true);
}

void	*map(void *content)
{
	char	*str;
	char	*ret;

	str = strdup((char *)content);
	ret = str;
	while (*str)
		*str++ = 'A';
	return (ret);
}

bool	test_lstmap(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*lst2;

	node1 = ft_lstnewone(strdup("Hello"));
	node2 = ft_lstnewone(strdup("World!"));
	node3 = ft_lstnewone(strdup("!"));
	node1->next = node2;
	node2->next = node3;
	lst2 = ft_lstmap(node1, map, free);

	if (strcmp(lst2->content, "AAAAA") != 0)
		return (false);
	if (strcmp(lst2->next->content, "AAAAAA") != 0)
		return (false);
	if (strcmp(lst2->next->next->content, "A") != 0)
		return (false);
	return (true);
}

bool	test_putchar_fd(void)
{
	ft_putchar_fd('\t', 1);
	ft_putchar_fd('\t', 1);
	ft_putchar_fd('H', 1);
	ft_putchar_fd('e', 1);
	ft_putchar_fd('l', 1);
	ft_putchar_fd('l', 1);
	ft_putchar_fd('o', 1);
	ft_putchar_fd(' ', 1);
	ft_putchar_fd('W', 2);
	ft_putchar_fd('o', 2);
	ft_putchar_fd('r', 2);
	ft_putchar_fd('l', 2);
	ft_putchar_fd('d', 2);
	ft_putchar_fd('!', 2);
	ft_putchar_fd(' ', 2);
	ft_putchar_fd('<', 2);
	ft_putchar_fd('-', 2);
	ft_putchar_fd('-', 2);
	ft_putchar_fd('-', 2);
	ft_putchar_fd('>', 2);
	ft_putchar_fd('\n', 2);
	return (true);
}

bool	test_putstr_fd(void)
{
	ft_putstr_fd("\t\tHel\0lo ", 1);
	ft_putstr_fd("lo World! <--->\n", 2);
	return (true);
}

bool	test_putendl_fd(void)
{
	ft_putendl_fd("\t\tHello <--->", 1);
	ft_putendl_fd("\t\tWorld <--->", 2);
	return (true);
}

bool	test_putnbr_fd(void)
{
	ft_putstr_fd("\t\t", 1);
	ft_putnbr_fd(INT_MAX, 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("\t\t", 2);
	ft_putnbr_fd(INT_MIN, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("\t\t", 1);
	ft_putnbr_fd(0, 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("\t\t", 2);
	ft_putnbr_fd(-3000, 2);
	ft_putstr_fd("\n", 2);
	return (true);
}

bool	test(bool (*fn)(void), char *fn_name)
{
	bool result = (*fn)();
	if (result)
		printf("%s ok!\n", fn_name);
	else
		printf("%s failed!\n", fn_name);
	return (result);
}

int	main(void)
{
	int failed = 0;
	failed += !test(test_memset, "memset");
	failed += !test(test_bzero, "bzero");
	failed += !test(test_memcpy, "memcpy");
	failed += !test(test_memccpy, "memccpy");
	failed += !test(test_memmove, "memmove");
	failed += !test(test_memchr, "memchr");
	failed += !test(test_memcmp, "memcmp");
	failed += !test(test_strlen, "strlen");
	failed += !test(test_isalpha, "isalpha");
	failed += !test(test_isdigit, "isdigit");
	failed += !test(test_isalnum, "isalnum");
	failed += !test(test_isascii, "isascii");
	failed += !test(test_isprint, "isprint");
	failed += !test(test_toupper, "toupper");
	failed += !test(test_tolower, "tolower");
	failed += !test(test_strchr, "strchr");
	failed += !test(test_strrchr, "strrchr");
	failed += !test(test_strncmp, "strncmp");
	failed += !test(test_strlcpy, "strlcpy");
	failed += !test(test_strlcat, "strlcat");
	failed += !test(test_strnstr, "strnstr");
	failed += !test(test_atoi, "atoi");
	failed += !test(test_strdup, "strdup");
	failed += !test(test_calloc, "calloc");
	failed += !test(test_substr, "substr");
	failed += !test(test_strjoin, "strjoin");
	failed += !test(test_strtrim, "strtrim");
	failed += !test(test_split, "split");
	failed += !test(test_itoa, "itoa");
	failed += !test(test_strmapi, "strmapi");
	failed += !test(test_lstnew, "lstnew");
	failed += !test(test_lstadd_front, "lstadd_front");
	failed += !test(test_lstadd_back, "lstadd_back");
	failed += !test(test_lstdelone, "lstdelone");
	failed += !test(test_lstclear, "lstclear");
	failed += !test(test_lstlast, "lstlast");
	failed += !test(test_lstiter, "lstiter");
	failed += !test(test_lstmap, "lstmap");
	failed += !test(test_putchar_fd, "putchar_fd");
	failed += !test(test_putstr_fd, "putstr_fd");
	failed += !test(test_putendl_fd, "putendl_fd");
	failed += !test(test_putnbr_fd, "putnbr_fd");
	printf("tests failed: %d\n", failed);
}
