/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 22:50:25 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/09/03 22:53:22 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

long long maxi(long long a, long long b)
{
	if (a > b) return a;
	return (b);
}

long long mini(long long a, long long b)
{
	if (a > b) return (b);
	return (a);
}

int	main()
{
	long long n;
	long long *a;
	long long *dp;
	
	cin >> n;
	a = new long long [n + 1];
	dp = new long long [n + 1];
	dp[0] = 0;
	
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	dp[1] = a[1];

	for (int i = 2;i <= n;i++)
	{
		dp[i] = maxi(dp[i - 1],dp[i - 2]) + a[i];
	}
	cout << dp[n];
	return (0);
}
