/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 11:09:13 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/09/04 11:11:09 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

using namespace std;

long long dp[1010][1010];
long long f(int i, int j)
{
    if ((i < 1) || (j < 1))
    {
        return 0;
    }
    if ((i == 1) && (j == 1))
    {
        return 1;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    dp[i][j] = (f(i - 2,j + 1) + f(i - 2,j - 1) + f(i - 1,j - 2) + f(i + 1,j - 2)) % 1000000123;
    return dp[i][j];
}

int	main()
{
    int n, m;

    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 0;j <= m;++j)
	{
            dp[i][j] = -1;
        }
    };
    cout << f(n, m);
}

