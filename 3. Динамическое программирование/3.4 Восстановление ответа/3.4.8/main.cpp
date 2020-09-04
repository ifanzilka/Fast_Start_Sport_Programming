/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 00:25:59 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/09/05 01:02:47 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
using namespace std;

long long **dp;
long long *diags;
int **parent_x;
int **parent_y;
int n,m;
int **a;

const long long inf = 9223372036854775807;

void answer()
{
	int x = n;
	int y = m;
	
	vector <pair<int, int>> ans;
	while (x >= 1 && y >= 1)
	{
		ans.push_back({x, y});
		int old_x = x, old_y = y;
		x = parent_x[old_x][old_y];
		y = parent_y[old_x][old_y];
	}
	cout << dp[n][m] << " "<< ans.size() << endl;
	for (int i = ans.size() - 1;i >= 0;--i)
	{
		cout << ans[i].first << " " << ans[i].second << endl;
	}
};

void show(int n, int m)
{
	for (int i = 0;i <= n;i++)
	{
		for (int j = 0;j <= m;j++)
		{
			cout << dp[i][j] << " ";
		}
		cout<<endl;
	}
	cout << endl;
	for (int i = 0;i <= n;i++)
	{
		for (int j = 0;j <= m;j++)
		{
			cout << parent_x[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0;i <= n;i++)
	{
		for (int j = 0;j <= m;j++)
		{
			cout << parent_y[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "good" << endl;
	cout << endl;
}

long long f(int i, int j)
{
	if ((i == 1) && (j == 1))
	{
		return a[i][j];
	}
	if (dp[i][j] != -1)
	{
		return dp[i][j];
	}
       	long long mn = inf;
	int xi = i;
	int yj = j;
	for (int k = i - 1;k >= 1;k--)
	{
		if (f(k, j) < mn)
		{
			mn = f(k, j);
			xi = k;
			yj = j;
		}
	}
	for (int k = j - 1;k >= 1;k--)
	{
		if (f(i, k) < mn)
		{
			mn = f(i, k);
			xi = i;
			yj = k;
		}
	}
	int x = i;int y = j;
	while (x >= 1 && y >= 1)
	{
		x--;
		y--;
		if (f(x, y) < mn)
		{
			mn = f(x, y);
			xi = x;
			yj = y;
		}
	}
	dp[i][j] = mn + a[i][j];
	parent_x[i][j] = xi;
	parent_y[i][j] = yj;
	return dp[i][j];
}

int	main()
{
	cin >> n >> m;
	
	dp = new long long *[n + 1];
	a = new  int*[n + 1];
	parent_y = new int*[n + 1];
	parent_x = new int*[n + 1];
	diags = new long long [n + m + 2];
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
		for (int j = 1;j <= m;j++)
		{
			cin >> a[i][j];
		}
	}
	if (n < 200 && m < 200)
	{
		f(n, m);
		answer();
		return 0;
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
	dp[1][1] = a[1][1];
	long long *sm = new long long[m + 1];
	vector<pair<int, int >> sm1;
	for (int i = 0;i <= m;i++)
	{
		sm[i] = dp[1][i];
		sm1.push_back({1, i});
	}
	int x1, y1;
	vector <pair<int, int >> diags_xy;
	for (int i = 0;i <= n + m + 1;i++)
	{
		diags_xy.push_back({0, 0});
	}
	for (int i = 1;i <= n;i++)
	{
		diags[i - 1 + m - 1] = dp[i][1];
		diags_xy[i - 1 + m - 1] = {i, 1};
	}
       	for (int j = 1;j <= m;j++)
	{
		diags[1 - j + m - 1] = dp[1][j];
		diags_xy[1 - j + m - 1] = {1, j};
	}
	for (int i = 2;i <= n;i++)
	{
		long long miny = dp[i][1];
		x1 = i;y1 = 1;
		for (int j = 2;j <= m;j++)
		{
			long long sum3 = diags[i - j + m - 1];
			int xi = diags_xy[i - j + m - 1].first,yj = diags_xy[i - j + m - 1].second;
			if (miny < sm[j] && miny < sum3)
			{
				dp[i][j] = miny + a[i][j];
				parent_x[i][j] = x1;
				parent_y[i][j] = y1;
			}
			else if (sm[j] < miny && sm[j] < sum3)
			{
				dp[i][j] = sm[j] + a[i][j];
				parent_x[i][j] = sm1[j].first;
			       	parent_y[i][j] = sm1[j].second;
			}
			else
			{
				dp[i][j] = sum3 + a[i][j];
				parent_x[i][j] = xi;
				parent_y[i][j] = yj;
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
			if (dp[i][j] < sum3)
			{
				diags[i - j + m - 1] = dp[i][j];
				diags_xy[i - j + m - 1] = {i, j};
			}
		}
	}
	answer();
}
