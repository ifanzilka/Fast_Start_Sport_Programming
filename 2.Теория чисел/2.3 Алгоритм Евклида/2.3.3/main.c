/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 15:25:12 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/09/02 15:29:25 by ifanzilka        ###   ########.fr       */
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

bool Check(int a, int b, int c)
{
	if (abs(c) % a != 0)
	{
		cout << 1;
	}
	if (abs(c) % b != 0)
	{
		cout << 2;
	}
	if (abs(c) % a !=0 && abs(c) % b != 0)
	{
		return (false);
	}
	return (true);
}

int	main()
{
	long long a,b,c;

	cin >> a >> b >> c;
	if (c % gcd(a, b) == 0)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	return (0);
}
