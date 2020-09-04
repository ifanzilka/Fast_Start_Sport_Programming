/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 00:01:42 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/09/05 00:22:06 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

using namespace std;

const long long inf = 9223372036854775807;
long long **dp;
int **parent_x;
int **parent_y;
int n, m;

int **a;

long long f(int i, int j)
{
	if (i == 1 && j == 1)
	{
		return dp[i][j];
	}
	if (dp[i][j] != -1)
	{
		return dp[i][j];
	}
	int par_x = i;
	int par_y = j;
	long long mn = inf;
	int x = i - 1;int y = j;
	while (x >= 1)
	{
		if (f(x, j) <= mn)
		{
			par_x = x;
			par_y = j;
			mn = f(x,j);
		}
		x--;
	}
	y = j - 1;x = i;
	while (y >= 1)
	{
		if (f(i, y) <= mn)
		{
			par_x = i;
			par_y = y;
			mn = f(i, y);
		}
		y--;
	}
	dp[i][j] = mn + a[i][j];
	parent_x[i][j] = par_x;
	parent_y[i][j] = par_y;
	return dp[i][j];
}

int	main()
{
	cin >> n >> m;
	dp = new long long *[n + 1];
	a = new  int*[n + 1];
	parent_y = new int*[n + 1];
	parent_x = new int*[n + 1];
	for (int i = 0;i <= n;i++)
	{
		dp[i] = new long long [m + 1];
		a[i] = new  int [m + 1];
		parent_y[i] = new int[m + 1];
		parent_x[i] = new int[m + 1];
	}
	for (int i = 0;i <= n;i++)
	{
		for (int j = 0;j <= m;j++)
		{
		       	dp[i][j] = -1;
			parent_x[i][j] = -1;
			parent_y[i][j] = -1;
		}
	}
	for (int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= m;j++)
		{
			cin >> a[i][j];
		}
	}
	dp[1][1] = a[1][1];
	int x3 = 1,y3 = 1;
	long long sum = a[1][1];
	for (int i = 2;i <= n;i++)
	{
		dp[i][1] = sum + a[i][1];
		parent_x[i][1] = x3;
		parent_y[i][1] = y3;
		if (dp[i][1] < sum)
		{
			sum = dp[i][1];
			x3 = i;
			y3 = 1;
		}
	}
	sum = a[1][1];
	x3 = 1;
	y3 = 1;
	for (int j = 2;j <= m;j++)
	{
		dp[1][j] = sum + a[1][j];
		parent_x[1][j] = x3;
		parent_y[1][j] = y3;
		if (dp[1][j] < sum)
		{
			sum = dp[1][j];
			x3 = 1;
			y3 = j;
		}
	}
	long long *sm = new long long[m + 1];
	vector<pair<int,int >>sm1;
	for (int i = 0;i <= m;i++)
	{
		sm[i] = dp[1][i];
		sm1.push_back({1, i});
	}
	int x1, y1;
	for (int i = 2;i <= n;i++)
	{
		long long miny = dp[i][1];
		x1 = i;y1 = 1;
		for (int j = 2;j <= m;j++)
		{
			if (miny < sm[j])
			{
				dp[i][j] = miny + a[i][j];
				parent_x[i][j] = x1;
				parent_y[i][j] = y1;
			}
			else
			{
				dp[i][j] = sm[j] + a[i][j];
				parent_x[i][j] = sm1[j].first;
				parent_y[i][j] = sm1[j].second;
			}
			if (dp[i][j] < miny)
			{
				miny = dp[i][j];
				x1 = i;
				y1 = j;
			}
			if (dp[i][j] < sm[j])
			{
				sm[j] = dp[i][j];
				sm1[j].first = i;
				sm1[j].second = j;
			}
		}
	}
	int x = n;
	int y = m;
	
	vector<pair<int,int>> ans;
	while (x >= 1 && y >= 1 )
	{
		ans.push_back({x, y});
		int old_x = x, old_y = y;
		x = parent_x[old_x][old_y];
		y = parent_y[old_x][old_y];
	}
	cout << dp[n][m] << " " << ans.size() << endl;
	for (int i = ans.size() - 1;i >= 0;--i)
	{
		cout << ans[i].first << " " << ans[i].second << endl;
	}
	return (0);
}
