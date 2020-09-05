/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 20:31:14 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/09/05 20:31:17 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	int s;
	int i;
	int j;
	int a;
	int ret;

	cin >> s >> n;
	vector <int> w(n + 1);
	i = 0;
	while (++i <= n)
		cin >> w[i];
	vector <vector <int> > dp(n + 1, vector <int> (s + 1, 0));

	dp[0][0] = 1;
	i = 0;
	while (++i <= n)
	{
		j = -1;
		while (++j <= s)
		{
			if (w[i] <= j)
			{
				if (1 == dp[i - 1][j - w[i]])
					dp[i][j] = 1;
				else
					dp[i][j] = dp[i - 1][j];
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	ret = ++s;
	while (--ret >= 0)
	{
		if (dp[n][ret] == 1) {
			i = n;
			j = ret;
			cout << ret << " ";
			break;
		}
	}
	vector <pair <int, int> > ans;
	while (j > 0)
	{
		i = 0;
		while (dp[i][j] != 1)
			++i;
		ans.push_back(make_pair(i, j));
		j = j - w[i];
	}
	i = ans.size();
	cout << i << endl;
	while (--i >= 0)
		cout << ans[i].first << " ";
	return 0;
}
