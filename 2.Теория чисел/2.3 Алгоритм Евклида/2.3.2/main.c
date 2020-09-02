/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 15:21:58 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/09/02 15:23:44 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>

using namespace std;

long long cnt = 0;

long long  gcd(long long a, long long b)
{
	if (b == 0) return a;
	cnt++;
	return gcd(b, a % b);
}
int	main()
{
	long long a, b, c;
	cin >> a >> b;
	c = gcd(a, b);
	cout << cnt;
	
	return (0);
}
