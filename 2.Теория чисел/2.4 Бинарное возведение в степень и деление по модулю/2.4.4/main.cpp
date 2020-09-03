/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 12:51:33 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/09/03 12:59:09 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

long long  gcd(long long a, long long b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

long long fastpow(long long a, long long n, long long mod)
{
	if(n == 0)
	{
		return 1;
	}
	if(n % 2 == 1)
	{
		return (a * fastpow(a, n - 1,mod) % mod);
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
		x1 = 1; y1 = 0; x2 = 0; y2 = 1;
	}
	if (r2 == 0) return r1;

	long long x = x1 - (r1 / r2) * x2;
	long long y = y1 - (r1 / r2) * y2;
	x1 = x2;x2 = x;y1 = y2;y2 = y;
	
	return extgcd(r2, r1 % r2, x1, y1, x2, y2, false);
}

long long Mdiv2(long long a, long long b, long long mod)
{
	long long x1, x2, y1, y2;
	long long d = extgcd(b, mod, x1, y1, x2, y2);
	
	if(a % d != 0) return -1LL;
	return Mmul((a / d), x1, mod);
}

int	main()
{
    long long a, n, mod;
    
    cin >> a >> n >> mod;

    long long ans = 0;
    long long st = a;

    for (long long  i = 1;i <= n;i++)
    {
	    if(i % gcd(st, mod) != 0)
	    {
		    cout << -1;
		    return 0;
	    }
	    ans = norm(ans + Mdiv2(i, st, mod), mod);
	    st = Mmul(st, a, mod);
    }
    
    cout << ans;
    return (0);
}
