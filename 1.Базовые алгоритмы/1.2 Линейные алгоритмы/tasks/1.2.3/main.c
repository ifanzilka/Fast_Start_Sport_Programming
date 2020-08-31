/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 14:07:39 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/08/31 14:07:49 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>

using namespace std;

long int	maxi;
int		n;
long int 	tmp;
int		pos;
int main()
{
	int i;

       	pos = 0;
	maxi = -1;
	cin >> n;
    	i = 0;

    while (i < n)
    {
        cin >> tmp;
        if (tmp > maxi)
	{
            maxi = tmp;
            pos = i + 1;   
        }
	i++;
    }
    cout << pos;
    return (0);
}

