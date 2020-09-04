/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 10:39:14 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/09/04 10:44:42 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <math.h>

using namespace std;

int	main()
{
	int n, m;
	cin >> m >> n;
	int **array;
	int **dp;
	int** hs;
	
	array = new int*[n + 1];
	dp = new int*[n + 1];
	hs = new int*[n + 1];
	
	for(int i = 0;i <= n;i++)
	{
		array[i] = new int[m + 1];
		dp[i] = new int[m + 1];
		hs[i] = new int [m + 1];
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= m;j++)
		{
			cin >> array[i][j];
		}
	}
	dp[1][1] = 0;
	for(int j = 2;j <= m;++j)
	{
		dp[1][j] = dp[1][j - 1] + abs(array[1][j] - array[1][j - 1]);
	}
	for(int i = 2;i <= n;++i)
	{
		dp[i][1] = dp[i - 1][1] + abs(array[i - 1][1] - array[i][1]);

	}
	for(int i = 2;i <= n;i++)
	{
		for(int j = 2;j <= m;j++)
		{
			dp[i][j] = min(dp[i - 1][j] + abs(array[i][j] - array[i - 1][j]), dp[i][j - 1] + abs(array[i][j] - array[i][j - 1]));
		}
	}
	cout << dp[n][m];
	return (0);
}

