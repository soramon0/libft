/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaayoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:18:11 by klaayoun          #+#    #+#             */
/*   Updated: 2024/10/25 22:21:05 by klaayoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*tmp;

	if (lst == NULL || f == NULL)
		return (NULL);
	head = ft_lstnew((*f)(lst->content));
	if (head == NULL)
		return (NULL);
	lst = lst->next;
	tmp = head;
	while (lst)
	{
		tmp->next = ft_lstnew((*f)(lst->content));
		if (tmp->next == NULL)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		tmp = tmp->next;
		lst = lst->next;
	}
	return (head);
}
