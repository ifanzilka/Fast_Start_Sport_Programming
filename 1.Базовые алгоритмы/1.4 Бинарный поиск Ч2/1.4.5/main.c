/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 18:50:50 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/08/31 18:53:53 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>

using namespace std;

long long  w ,h, n;

long long diplomMasNumber(long long w, long long h, long long len)
{
	return (len/w)*(len/h);
}

long long findAns(long w, long h, long n)
{
	long long l = 0;
	long long r = max(w,h) * n;

	while (l + 1 < r)
	{
		long long mid = (l + r)/2;
		
		if (diplomMasNumber(w, h, mid) >= n)
		{
			r=mid;
		}
		else
		{
			l = mid;
		}
	}
	return (r);
}

int	main()
{
	cin >> w >> h >> n;
	cout<<findAns(w, h, n);
	return (0);
}
