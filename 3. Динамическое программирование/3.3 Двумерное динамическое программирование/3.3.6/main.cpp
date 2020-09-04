/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 10:58:07 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/09/04 11:06:15 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

long long mod = 1000000009;

int	main()
{
	int n, m;
	int**a;
	int**dp;
	cin >> n >> m;
	
	a = new int*[n + 1];
	dp = new int*[n + 1];
	for  (int i = 0;i <= n;i++)
	{
		a[i] = new int[m + 1];
		dp[i] = new int[m + 1];
	}
	for(int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= m;j++)
			cin >> a[i][j];
	}
	
	dp[0][0] = 0;
	for(int i = 1;i <= n;i++)
	{
		if (a[i][1] == 0)
		{
			dp[i][1] = 1;
		}
		else
		{
			break;
		}
	}
	for (int j = 1;j <= m;j++)
	{
		if (a[1][j] == 0)
		{
			dp[1][j] = 1;
		}
		else
		{
			break;
		}
	}
	for(int i = 2;i <= n;i++)
	{
		for (int j = 2;j <= m;j++)
		{
			if (a[i][j] == 0)
			{
				if (a[i - 1][j] == 0) 
					dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
				if (a[i][j - 1] == 0) 
					dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
				if(a[i - 1][j - 1] == 0) 
					dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
			}
			else
			{
				dp[i][j] = 0;
			}
		}
	}
	cout << dp[n][m];
	return (0);
}
