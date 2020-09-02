/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 12:14:37 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/09/02 12:16:56 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>

using namespace std;

int	main()
{
	unsigned long long *res, n, mod;
	
	mod = 1000003;
	cin >> n;
	res = new  unsigned long long[n + 2];
	res[0] = res[1] = res[2] = 1;
	
	for(long long i = 3;i <= n + 1;i++)
	{
		res[i] = (res[i - 1] + res[i - 2]) % mod;
	}
	cout << res[n + 1];
	return (0);
}
