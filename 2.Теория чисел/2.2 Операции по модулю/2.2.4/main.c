/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 12:24:25 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/09/02 12:28:01 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>

using namespace std;

long long norm(long long x, long long mod)
{
       	return (((x % mod) + mod) % mod);
}

int main()
{
	long long Fac, n, mod;
	mod = 1000003;
	cin >> n;
	Fac = 2;
	
	for (long long i = 3;i <= n;i++)
	{
		Fac = ((Fac * i));
		if (Fac > mod)
		{
			Fac %= mod;
		}
	}
	cout << Fac;
	return (0);
}

