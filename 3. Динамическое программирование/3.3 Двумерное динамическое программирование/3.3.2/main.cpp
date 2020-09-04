/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 10:30:34 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/09/04 10:34:58 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <math.h>

using namespace std;

int	main()
{
	int n, m;
	cin >> n >> m;
	int **array;
	int **dp;
	array = new int*[n + 1];
	dp = new int*[n + 1];
	for (int i = 0;i <= n;i++)
	{
		array[i] = new int[m + 1];
		dp[i] = new int[m + 1];
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= m;j++)
		{
			cin >> array[i][j];
		}
	}
	dp[1][1] = array[1][1];
	for(int j = 2;j <= m;++j)
	{
		dp[1][j] = dp[1][j-1] + array[1][j];
	}
	for(int i = 2;i <= n;++i)
	{
		dp[i][1] = dp[i - 1][1] + array[i][1];

	}
	for(int i = 2;i <= n;i++)
	{
		for(int j = 2;j <= m;j++)
		{
			dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]),dp[i - 1][j - 1]) + array[i][j];
		}
	}
	cout << dp[n][m];
	return (0);
}
