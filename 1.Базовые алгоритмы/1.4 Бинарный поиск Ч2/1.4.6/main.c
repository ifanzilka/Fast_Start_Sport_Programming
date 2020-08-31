/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 18:56:14 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/08/31 18:59:25 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>

using namespace std;

long long n, t1, t2;

int	main()
{
	cin >> n >> t1 >> t2;
	long long tmin = min(t1, t2);
	long long t = max(t1, t2);
	long long l = 0;
	n--;
	long long  r = n * t;
	long long mid;
	while(l < r)
	{
		mid = (l + r)/2;
		if((mid/t1) + (mid/t2) < n)
		{
			l = mid + 1;
		}
		else
		{
			r = mid;
		}
	}
	// cout<<"R: "<<r<<" L:"<<l<<endl;
	cout << r + tmin << endl;
	return (0);
}
