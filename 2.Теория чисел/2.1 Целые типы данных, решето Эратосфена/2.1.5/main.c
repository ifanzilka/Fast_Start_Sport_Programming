/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 12:02:45 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/09/02 12:07:12 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>

using namespace std;

int	main()
{
	unsigned long long n, sm;

	sm = 0;
	cin >> n;
	
	long long *Slieve = new long long[n+10];
	
	for (long long  i = 0;i < (n + 9);i++)
	{
		Slieve[i] = 0;
	}
	for (long long i = 2;(i * i) <= n;i++)
	{
		if (Slieve[i] == 0)
		{
			for (long long  j = i;j * i <= n;j++)
			{
				if (Slieve[i * j] == 0)
				{
					Slieve[i * j] = i;
				}
			}
		}
	}
	for(long long  i = 3;i <= n;i++)
	{
		sm += Slieve[i + 1];
        }
	cout << sm;
	return (0);
}
