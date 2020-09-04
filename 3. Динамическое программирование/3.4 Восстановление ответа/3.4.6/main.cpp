/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 16:35:51 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/09/04 16:54:39 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

using namespace std;

long long **dp;
long long inf = 922337203685477580;
int n, m;
int **a;

long long f(int i, int j)
{
	if ((i < 0) || (j < 0))
	{
		return 0;
	}
	if (i == 0 && j == 0)
	{
		return a[0][0];
	}
	if (dp[i][j] != -1)
	{
		return dp[i][j];
	}
	long long mn = inf;
	if (i - 2 >= 0 && j + 1 < m)
	{
		mn = min(f(i - 2,j + 1), mn);

	}
	if (i - 2 >= 0 && j - 1 >= 0)
	{
		mn = min(f(i - 2, j - 1), mn);
	}
	if (i - 1 >= 0 && j - 2 >= 0)
	{
		mn = min(f(i - 1, j - 2), mn);
	}
	if (i + 1 < n && j - 2 >= 0)
	{
		mn = min(f(i + 1, j - 2), mn);
	}
	dp[i][j] = mn + a[i][j];
	return dp[i][j];
}

int	main()
{
	cin >> n >> m;
	a = new  int*[n];
	dp = new long long *[n];
	for (int i = 0;i < n;i++)
	{
		a[i] = new  int [m];
		dp[i] = new long long [m];
	}
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;++j)
		{
			dp[i][j] = -1;
		}
	};
	
	dp[0][0] = a[0][0];
	f(n - 1, m - 1);
	if (dp[n - 1][m - 1] >= inf)
	{
		cout << "NO";
	}
	else
	{
		vector< pair<int, int> > ans;
		int x = n - 1;int y = m - 1;
		while (true)
		{
			ans.push_back({x + 1, y + 1});
			if (x == 0 && y == 0)
			{
				break;
			}
			if (ans.size() > 10)
			{
				if (ans[ans.size() - 1] == ans[ans.size() - 2])
				{
					cout << "NO" << endl;
					return 0;
					break;
				}
			}
			bool k= true;
			if (x - 2 >= 0 && y + 1 < m && k)
			{
				if (dp[x - 2][y + 1] + a[x][y] == dp[x][y])
				{
					x -= 2;
					y += 1;
					k = false;
				}
			}
			
			if (x - 2 >= 0 && y - 1 >= 0 && k)
			{
				if (dp[x - 2][y - 1] + a[x][y] == dp[x][y])
				{
					x -= 2;
					y--;
					k = false;
				}
			}
			if (x - 1 >= 0 && y - 2 >= 0 && k)
			{
				if (dp[x - 1][y - 2] + a[x][y] == dp[x][y])
				{
					x--;
					y -= 2;
					k = false;
				}
			}
			if (x + 1 < n && y - 2 >= 0 && k)
			{
				if (dp[x + 1][y - 2] + a[x][y] == dp[x][y])
				{
					x++;
					y -= 2;
				       	k = false;
				}
			}
		}
		cout << "YES" << endl;
		cout << dp[n - 1][m - 1]<< " " << ans.size()<< endl;
		for (int i = ans.size() - 1;i >= 0;--i)
		{
			cout << ans[i].first << " " << ans[i].second << endl;
		}
	}
	return (0);
}
