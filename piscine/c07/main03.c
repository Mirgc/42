/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 18:51:45 by iibanez-          #+#    #+#             */
/*   Updated: 2021/04/29 16:18:08 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>
#include "ex03/ft_strjoin.c"

int	main(void)
{
	char *s[4] = {"Hola1","Hola2","hola3"};
	char *sep = "---";

	char *dest;	
	dest = ft_strjoin(3, s, sep);
	printf("%s",dest);
}
