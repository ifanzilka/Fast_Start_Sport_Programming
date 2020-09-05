/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 20:27:47 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/09/05 20:27:53 by ifanzilka        ###   ########.fr       */
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
				dp[i][j] = dp[i - 1][j] || dp[i - 1][j - w[i]];
			else
				dp[i][j] = dp[i - 1][j];			
		}
	}
	i = ++s;
	while (--i >= 0)
	{
		if (dp[n][i] == 1) {
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}
