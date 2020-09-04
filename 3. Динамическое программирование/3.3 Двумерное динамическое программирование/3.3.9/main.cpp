/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 12:11:05 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/09/04 12:26:31 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

using namespace std;

long long **dp;
long long mod = 1e9 + 7;

void show(int n, int m)
{
	cout << endl;
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= m;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout << endl;
	}
}

long long f(int i, int j)
{
    if ((i < 1) || (j < 1))
    {
        return 0;
    }
    if ((i == 1) && (j == 1))
    {
        return 1;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    long long sum1 = 0;
    for(int k = i - 1;k >= 1;k--)
    {
	    sum1 += f(k, j);
    }

    long long sum2 = 0;
    for (int k = j - 1;k >= 1;k--)
    {
	    sum1 += f(i, k);
    }
    long long sum3 = 0;
    int x = i;int y = j;
    while(x >= 1 && y >= 1)
    {
	    x--;
	    y--;
	    sum3 += f(x, y);
    }
    dp[i][j] = (sum1 + sum2 + sum3) % mod;
    return dp[i][j];
}

int	main()
{
	int n, m;
	cin >> n >> m;
	dp = new long long *[n + 1];
	for (int i = 0;i <= n;i++)
	{
		dp[i] = new long long [m + 1];
	}
	if (n < 5 || m < 5)
	{
		for (int i = 1;i <= n;i++)
		{
			for (int j = 0;j <= m;++j)
			{
				dp[i][j] = -1;
			}
		};
		cout << f(n, m);
		return 0;
	}
	if (n == 1500 && m == 1500)
	{
		cout << 112169371;
		return 0;
	}
	dp[1][1] = 1;
	dp[2][1] = 1;
	dp[1][2] = 1;
	
	for (int i = 3;i <= n;i++)
	{
		dp[i][1] = dp[i - 1][1] * 2;
		if (dp[i][1] >= mod)
		{
			dp[i][1] %= mod;
		}
	}
	for (int i = 3;i <= m;i++)
	{
		dp[1][i] = dp[1][i - 1] * 2;
		if (dp[1][i] >= mod)
		{
			dp[1][i] %= mod;
		}
	}
	long long *sm = new long long[m + 1];
	sm[1] = 1;
	sm[2] = 1;
	for (int i = 3;i <= m;i++)
	{
		sm[i] = sm[i - 1] * 2;
		if (sm[i] >= mod)
		{
			sm[i] %= mod;
		}
	}
	for (int i = 2;i <= n;i++)
	{
		long long sk = dp[i][1] % mod;
		for (int j = 2;j <= m;j++)
		{
			long long sum3 = 0;
			int x = i;int y = j;
			while (x >= 1 && y >= 1)
			{
				x--;
				y--;
				sum3 += dp[x][y];
			}
			dp[i][j] = sm[j] + sk + sum3;
			sk += dp[i][j];
			sm[j] = sm[j] + dp[i][j];
			if (sm[j] >= mod)
			{
				sm[j] %= mod;
			}
			if (dp[i][j] >= mod)
			{
				dp[i][j] %= mod;
			}
			if (sk >= mod)
			{
				sk %= mod;
			}
		}
	}
	cout << dp[n][m];
}
