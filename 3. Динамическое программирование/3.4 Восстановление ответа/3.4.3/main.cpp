/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 16:12:43 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/09/04 16:17:44 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>
#include <vector>

using  namespace  std;

int	main()
{
	long long n;
	cin >> n;
	long long *a;
	long long *dp;
	
	dp = new long long [n + 1];
	a = new long long [n + 1];
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (i < 3)
			dp[i] = a[i] + dp[i - 1];
		else if (i < 5)
			dp[i] = a[i] + max(dp[i - 1], dp[i - 3]);
		else
			dp[i] = a[i] + max(dp[i - 5], max(dp[i - 1], dp[i - 3]));
	}
	vector< pair<int,int> > ans;
	int x = n;
	while (x >= 0)
	{
		ans.push_back({x, 0});
		if (dp[x - 1] + a[x] == dp[x])
		{
			x--;
		}
		else if (dp[x - 3] + a[x] == dp[x])
		{
			x -= 3;
		}
		else
		{
		       	x -= 5;
		}
	}
	cout << dp[n]<< " " << ans.size() - 1;
	cout << endl;
	for (int i = ans.size() - 2;i >= 0;--i)
	{
		cout << ans[i].first << " ";
	}
}
