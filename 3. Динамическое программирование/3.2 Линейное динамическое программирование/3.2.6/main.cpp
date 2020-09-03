/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 23:09:45 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/09/03 23:17:14 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

long long mod=1000000007;
int *dp;
string l;

int f(int i)
{
	if (i < 0){return 0;}
	if (i == 0) {return 1;}
	if (dp[i] != -1)
	{
		return dp[i];
	}
	if (l[i - 1] == '1')
	{
		return 0;
	}
	else
	{
		dp[i] = f(i - 1) + f(i - 2) + f(i - 3);
		return  dp[i] % mod;
	}
}

int	main()
{
	int n;
	cin >> n;
	dp = new int[n + 2];
	cin >> l;
	for(int i = 0;i <= n + 1;i++)
	{
		dp[i] = -1;
	}
	for(int i = 0;i <= n;i++)
	{
		if (i == 0){dp[i] = 1;}
		else if (i == 1)
		{
			if (l[i - 1] == '1')
			{
				dp[i] = 0;
			}
			else
			{
				dp[1] = dp[0];
			}
		}
		else if (i == 2)
		{
			if( l[i - 1] == '1')
			{
				dp[i] = 0;
			}
			else
			{
				dp[2] = dp[1] + dp[0];
			}
		}
		else if (i == 3)
		{
			if (l[i - 1] == '1')
			{
				dp[i] = 0;
			}
			else
			{
				dp[3] = dp[2] + dp[1] + dp[0];
			}
		}
		else
		{
			if (l[i - 1] == '1')
			{
				dp[i] = 0;
			}
			else
			{
				dp[i] = (dp[i - 1] + dp[i - 2]) % mod + dp[i - 3];
				dp[i] = dp[i] % mod;
			}
		}
	}
	cout << dp[n];
	return (0);
}
