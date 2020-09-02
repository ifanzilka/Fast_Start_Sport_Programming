/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 15:31:12 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/09/02 15:32:53 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <math.h>

using namespace std;

long long  gcd(long long a, long long b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

int	main()
{
	long long n, a, b;
	
	cin >> n;
	cin >> b;
	for(int i = 0;i < n - 1;i++)
	{
		cin >> a;
		b = gcd(a, b);
	}
	cout << b;
	return (0);
}
