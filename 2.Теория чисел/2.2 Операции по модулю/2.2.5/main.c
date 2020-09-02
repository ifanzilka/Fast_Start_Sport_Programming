/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 12:30:59 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/09/02 12:35:59 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;
long long norm(long long x, long long mod)
{
	return (((x % mod) + mod) % mod);
}

long long pow3(int x, int y, int N)
{
	if (y == 0) return 1;
	
	long long z = pow3(x, y / 2, N);
	if (y % 2 == 0)
		return (z * z) % N;
	else
		return (x * z * z) % N;
}

long  long f(long  x, int *kf, int n, int mod)
{
	long long sum = 0;
	
	for(int i = n;i >= 0;i--)
	{
		long long tmp = kf[i] * ( pow3(x, i, mod));
		sum += tmp % mod;
	}
	return (sum % mod);
}

int	main()
{
	int n, m;
	cin >> n >> m;
	int *kf = new int[n + 1];
	
	for(int i = n;i >= 0;i--)
	{
		cin >> kf[i];
	}
	for(int x =- 1;x <= m;x++)
	{
		if(f(x, kf, n, m) % m == 0)
		{
			cout << x << endl;
			return 0;
		}
	}
	cout << -1;
	return (0);
}
