/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 19:41:53 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/09/02 19:46:32 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>

using namespace std;

long long fastpow(long long a, long long n,long long mod)
{
	if(n == 0)
	{
		return 1;
	}
	if (n % 2 == 1)
	{
		return(a * fastpow(a, n - 1,mod) % mod);
	}
	long long tmp = fastpow(a, n / 2,mod);
	return (tmp * tmp % mod);
}

long long norm(long long x, long long mod)
{
	return (((x % mod) + mod) % mod);
}

long long Mmul(long long a, long long b, long long mod)
{    
	return (norm(a * b, mod));
}

long long Mdiv(long long a, long long b, long long mod)
{
	return Mmul(a, fastpow(b, mod - 2LL, mod), mod);
}

int	main()
{
	long long a, b, c, d, mod;
	mod = 1000000007;
	cin >> a >> b >> c >> d;
	long long ad, bc, bd;
	
	ad = norm((norm(a, mod)) * (norm(d, mod)), mod);
	bc = norm((norm(b, mod)) * (norm(c, mod)), mod);
	bd = norm((norm(b, mod)) * (norm(d, mod)), mod);
	cout << Mdiv(((ad + bc) % mod), (bd), mod);
	
	return (0);
}
