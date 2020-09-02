/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 11:55:20 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/09/02 11:58:49 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

unsigned long long Trans(int number[64])
{
	typedef unsigned __int128 uint128_t;
	unsigned long long sum = 0;
	unsigned long long two = 1;
	
	for (int i = 0;i < 64;i++)
	{
		sum += number[i] * two;
		two = two * 2;
	}
	return (sum / 3) + (two / 3);
}

using namespace std;

int main()
{
	unsigned long long x;
	unsigned long long obr = 12297829382473034411;
	int number[64]={0};
	cin >> x;
	unsigned long long y = x / 3;
	
	if(y * 3 == x)
	{
		cout << y;
	}
	else
	{
		cout << x * obr;
	}
	return  (0);
}
