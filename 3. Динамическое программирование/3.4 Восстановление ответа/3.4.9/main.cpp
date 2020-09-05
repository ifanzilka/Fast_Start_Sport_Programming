/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 12:14:47 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/09/05 12:16:35 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	int k;
	int i;
	int j;
	int deque_i;   // deque size

	cin >> n >> k;
	vector <long long> ar(n + 1, 0);
	vector <long long> dp(n + 1, 0);
	vector <int> deque(k + 1, 0); //i-coordinate best parent for current dp
	vector <int> parent_i(n + 1, 0);
	i = 0;
	while (++i <= n)
		cin >> ar[i];
	deque[0] = 0;
	deque_i = 0;
    	i = 0;
	while (++i <= n)
    	{
		if (deque[0] < i - k)
		{
			if (deque_i)
			{
				j = -1;
				while (++j < deque_i)
					deque[j] = deque[j + 1];
				--deque_i;
			}
		}
		dp[i] = dp[deque[0]] + ar[i];
		parent_i[i] = deque[0];
		j = 0;
		while (j <= deque_i && dp[i] < dp[deque[deque_i - j]])
			++j;
		deque_i = deque_i - j;
		deque[++deque_i] = i;
	}

	vector <int> ans;
	i = n;
	int old_i;
	while (i > 0)
	{
		ans.push_back(i);
		old_i = i;
		i = parent_i[old_i];
	}
	i = ans.size();
	cout << dp[n] << " " << i << endl;
	while (--i >= 0)
		cout << ans[i] << " ";
	cout <<  endl;
	return 0;
}
