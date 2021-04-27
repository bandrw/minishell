#include "libft.h"

char	**ft_lsttoarr(t_list *list)
{
	int		i;
	char	**arr;

	if (!list)
		return (0);
	arr = (char**)malloc(sizeof(char*) * (ft_lstsize(list) + 1));
	if (arr)
	{
		i = -1;
		while (list)
		{
			arr[++i] = list->content;
			list = list->next;
		}
		arr[i] = 0;
	}
	return (arr);
}
