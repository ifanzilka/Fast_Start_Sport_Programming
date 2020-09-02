/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 11:50:08 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/09/02 11:52:51 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>

using namespace std;

bool	Prime(unsigned long long a)
{
    if (a < 2)
    {
	    return true;
    }
    for (unsigned long long i = 2;i * i < a + 1; i++)
    {
	    if (a % i == 0) return false;
    }
    return true;
}

int	main()
{
	unsigned long long n;

	cin >> n;
	if (Prime(n))
	{
		cout<<1; 
	}
	else
	{
		cout << 0;
	}
	return 0;
}
