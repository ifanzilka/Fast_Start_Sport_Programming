/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 23:02:29 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/09/03 23:07:36 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>


using namespace std;

long long mini(long long a, long long b)
{
	if(a > b) return b;
	return a;
}

int	main()
{
	long long N;
	cin >> N;
	long long *a = new long long [N + 1];
	
	for (int i = 1;i <= N;i++) 
	{
		if (i == 1) a[i] = 0;
		else if (i == 2)
		{
			a[i] = 1;
		}
		else if (i % 2 == 0 && i % 3 == 0 && i > 3)
		{
			a[i] = mini(mini(a[i / 3], a[i / 2] ), a[i - 1] ) + 1;
		}
		else if (i % 3 ==0)
		{
			a[i] = (mini(a[i / 3], a[i - 1] )) + 1;
		}
		else if (i % 2 ==0)
		{
			a[i] = (mini(a[i / 2],a[i - 1] )) + 1;
		}
		else
		{
			a[i] = a[i - 1] + 1;
		}
	}
	cout << a[N];
	return 0;
}

