/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 13:01:31 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/09/03 13:10:08 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;
long long *fac;

long long fastpow(long long a, long long n, long long mod)
{
	if (n == 0)
	{
		return 1;
	}
	if(n % 2 == 1)
	{
		return (a * fastpow(a, n - 1, mod) % mod);
	}
	long long tmp = fastpow(a, n / 2, mod);
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

long long extgcd(long long r1, long long r2, long long &x1, long long &y1, long long &x2, long long &y2, bool first = true)
{
	if(r1 < r2) return extgcd(r2, r1, y1, x1, y2, x2, first);
	if (first)
	{
		x1 = 1;y1 = 0;x2 = 0;y2 = 1;
	}
	if(r2 == 0) return r1;
	
	long long x = x1 - (r1 / r2) * x2;
	long long y = y1 - (r1 / r2) * y2;
	
	x1 = x2;x2 = x;y1 = y2;y2 = y;
	return extgcd(r2, r1 % r2, x1, y1, x2, y2, false);
}

long long Mdiv2(long long a, long long b, long long mod)
{
	long long x1, x2, y1, y2;
	long long d = extgcd(b, mod, x1, y1, x2, y2);

	if (a % d != 0) return -1LL;
	return Mmul((a / d), x1, mod);
}

long long C_n_k(long long n, long m, long k, long long mod)
{
	if (n < m * k) 
	{
		return (0);
	}
	return Mdiv2(fac[n], ((fac[n - m * k]) * fac[m * k]) % mod, mod);
}

int	main()
{
	long long n, m, l;
	long long mod = 1000000007;
	long long ans = 0;
	
	cin >> n >> m >> l;
	fac = new   long long[n + 1];
	fac[0] = 1;
	fac[1] = 1;
	for(long long i = 2;i <= n;i++)
	{
		fac[i] = (fac[i - 1] * i) % mod;
		// cout<<fac[i]<<" ";
	}
	for(int k = 1;k <= l;k++)
	{
		ans = ans + C_n_k(n, m, k, mod);
		ans = ans % mod;
	}
	cout << ans;
	return (0);
}
