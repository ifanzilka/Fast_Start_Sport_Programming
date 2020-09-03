/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 23:19:12 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/09/03 23:24:38 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;
long long *dp;
string l;
long long mod = 1000000007;
long long norm(long long x, long long mod)
{
	return (((x % mod) + mod) % mod);
}

long long raz(long long a, long long b , long long mod)
{
	return norm(norm(a, mod) - norm(b, mod),mod);
}

int	main()
{
	long long s = 1;
	int n, k;
	cin >> n >> k;
	dp = new long long [n + 1];
	cin >> l;
	for (int i = 0;i <= n;i++)
	{
		dp[i] = -1;
	}
	dp[0] = 1;
	for(int i = 1;i <= n;i++)
	{
		if (l[i - 1] == '1')
		{
			dp[i] = 0;
			if(i > k)
			{
				s = raz(s, dp[i - k - 1], mod);
			}
		}
		else
		{
			if (i > k)
			{
				s = raz(s, dp[i - k - 1], mod);
				dp[i]=s;
				s += dp[i];
				s %= mod;
			}
			else
			{
				dp[i] = s;
				s += dp[i];
				s %=mod;
			}
		}
	}
	cout << dp[n] % mod;
	return (0);
}
