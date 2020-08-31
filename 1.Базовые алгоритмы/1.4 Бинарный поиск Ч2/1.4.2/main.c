/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 18:31:34 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/08/31 18:38:02 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

constexpr double EPSILON = 1.e-9;

double long f (long double x, long double*kf, int n)
{
	long double sum = 0.0;
	
	for (int i = n;i >= 0; i--)
	{
		long double tmp = kf[i] * pow(x,i);
		sum += tmp;
	}
	return (sum);
}

int	main()
{
	int n;
	cin >> n;
	long double *kf = new  long double[n+1];
	for (int i = n;i >= 0; i--)
	{
		cin >> kf[i];
	}

    long double l = -10.0;
    long double r = 10.0;
    long double mid;

    while(r - l > EPSILON)
    {
	    mid = (l+r)/2;
	    
	    if (f(mid,kf,n) < 0.0)
		    l = mid;
	    else
		    r = mid;
    }
    cout << setprecision(16) << (l+r)/2.0;
    return (0);
}

