/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 22:54:52 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/09/03 23:00:23 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;


long long maxi(long long a, long long b)
{

    if (a > b) return a;
    return b;
}

long long mini(long long a, long long b)
{
	if(a > b) return b;
	return a;
}

int	main()
{
	long long n;
	long long *a;
	long long *dp;
	
	cin >> n;
	if (n >= 5)
	{
		a = new long long [n + 1];
		dp = new long long [n + 1];
		dp[0] = 0;
		for (int i = 1;i <= n;i++)
		{
			cin >> a[i];
		}
		dp[1] = a[1];
		dp[2] = a[1] + a[2];
		dp[3] = maxi(dp[2], dp[0]) + a[3];
		dp[4] = maxi(dp[3], dp[1]) + a[4];
		for (int i = 5;i <= n;++i)
		{
			dp[i] = maxi(maxi(dp[i - 1],dp[i - 3]),dp[i - 5]) + a[i];
		}
		cout << dp[n];
	}
	else
	{
		a = new long long [n + 1];
		dp = new long long [n + 1];
		dp[0] = 0;
		for (int i = 1;i <= n;i++)
		{
			cin >> a[i];
		}
		dp[1] = a[1];
	       	dp[2] = a[1] + a[2];
		dp[3] = maxi(dp[2], dp[0]) + a[3];
		dp[4] = maxi(dp[3], dp[1]) + a[4];
		cout << dp[1];
	}
	return (0);
}
