/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 16:20:19 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/09/04 16:30:25 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

using namespace std;

long long mini(long long a, long long b)
{
	if (a > b) return b;
	return a;
}

int	main()
{
	long long N;
	cin >> N;
	
	long long *a = new long long [N + 1];
	vector <pair<int, int> > ans;
	int  *dp = new int[N + 1];
	int k = 0;
	for (int i = 1;i <= N;i++)
	{
		if (i == 1)
		{
			a[i] = 0;
		}
		else if(i == 2)
		{
			a[i] = 1;
		}
		else if (i % 2 == 0 && i % 3 == 0 && i > 3)
		{
			a[i] = mini(mini(a[i / 3],a[i / 2] ), a[i - 1] ) + 1;
		}
		else if (i % 3 == 0)
		{
			a[i] = (mini(a[i / 3], a[i - 1] )) + 1;
		}
		else if (i % 2 == 0)
		{
			a[i] = (mini(a[i / 2], a[i - 1] )) + 1;
		}
		else
		{
			a[i] = a[i - 1] + 1;
		}
	}
	
	cout << a[N];
	cout << endl;
	int x = N;
	while (x >= 1)
	{
		ans.push_back({x, 0});
		if (x % 2 == 0 && x % 3 == 0 && x -1 >= 0)
		{
			if (a[x / 3] < a[x / 2] )
			{
			       	x = x / 3;
			}
			else
			{
				x = x / 2;
			}
		}
		else if (x % 3 == 0 && x - 1 >= 0) 
		{
			if (a[x / 3] < a[x - 1])
			{
				x = x / 3;
			}
			else
			{
				x--;
			}
		}
		else if (x % 2 == 0 && x - 1 >= 0)
		{
			if (a[x / 2] < a[x - 1])
			{
				x = x / 2;
			}
			else
			{
				x--;
			}
		}
		else
		{
			x--;
		}
	}
	for (int i = ans.size() - 1;i >= 0;--i)
	{
		cout << ans[i].first << " ";
	}
	return (0);
}

