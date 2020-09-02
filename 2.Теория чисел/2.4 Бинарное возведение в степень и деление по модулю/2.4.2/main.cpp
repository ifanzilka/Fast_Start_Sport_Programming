/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 19:37:15 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/09/02 19:40:05 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

long long fastpow(long long a, long long n,long long mod)
{
	if (n == 0)
	{
		return 1;
	}
	if (n % 2 == 1)
	{
		return (a * fastpow(a, n - 1,mod) % mod);
	}
	long long tmp = fastpow(a, n / 2,mod);
	return (tmp * tmp % mod);
}

int	main()
{
	long long n, mod;
	cin >> n >> mod;
	cout << fastpow(n, n, mod);
	return (0);
}
