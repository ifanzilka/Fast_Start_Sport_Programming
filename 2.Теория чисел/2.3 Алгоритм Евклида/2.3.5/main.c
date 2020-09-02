/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 15:34:23 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/09/02 15:37:15 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <math.h>

using namespace std;

unsigned long long  gcd(unsigned long long a,unsigned long long b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}
unsigned long long nok(unsigned long long a, unsigned long long b)
{
	unsigned long long c = gcd(a, b);
	return (a * b) / (a);
}

int	main()
{
	unsigned long long a, b, c, d, r;
	cin >> a;
	cin >> b;
	c = a; 
	d = b;
	while (d)r = c % d, c= d,d = r;
	if (a / c * b < 1e18)
	{
		cout << a / c * b << endl;
	}
	else
	{
		cout << -1;
	}
	return (0);
}

