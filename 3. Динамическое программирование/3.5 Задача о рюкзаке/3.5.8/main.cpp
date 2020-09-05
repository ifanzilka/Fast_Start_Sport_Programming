/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 21:41:31 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/09/05 21:42:40 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>


using namespace std;

int inf = 1000000000;

int     f_max(int a, int b)
{
        if (a > b) return a;
        return b;
}

int     main()
{
        int n, W;
        cin >> W >> n;
    
        vector <int> w(n + 1);
        vector <int> c(n + 1);
        for (int i = 1; i <= n; ++i)
        {
                cin >> w[i];
        }
        for (int i = 1; i <= n; ++i)
        {
                cin >> c[i];
        }
        vector <vector <int >> dp(n + 1, vector <int> (W + 1, -inf));
        dp[0][0] = 0;
    
        for (int i = 1; i <= n; ++i)
        {
                for (int j = 0; j <= W; ++j)
                {
                        if (w[i] <= j)
                        {
                                dp[i][j] = f_max(dp[i - 1][j], dp[i - 1][j - w[i]] + c[i]);
                        }
                        else
                        {
                                dp[i][j] = dp[i - 1][j];
                        }
                }
        }
	int j = -1;
	int i;
	int ret = 0;
	int ans_j = 0;
	while (++j <= W)
	{
		if (dp[n][j] >= ret)
		{
			ret = dp[n][j];
			ans_j = j;
		}
	}
	cout << ret << " ";
	vector <int> ans;
	i = n;
	j = ans_j;
	while (i > 0 && j >= 0)
	{
		if (w[i] <= j && dp[i][j] == dp[i - 1][j - w[i]] + c[i])
		{
			ans.push_back(i);
			j -= w[i];
		}
		i--;
	}
	i = ans.size();
	cout << i << endl;
	while (--i >= 0)
		cout << ans[i] << " ";
}

