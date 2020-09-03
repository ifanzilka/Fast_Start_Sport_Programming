/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 23:30:10 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/09/03 23:30:39 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

int main ()
{
	short n;
	cin >> n;
	if (n != 0)
	{
		unsigned long long next = 1, prev = 1, sum = 0;
		for (int i = 0; i < n; i ++)
			sum += prev, 
			next = next + prev, 
			prev = next - prev;
		return cout << sum + 1, 0;
	}
	else
		return cout << 1, 0;
}
