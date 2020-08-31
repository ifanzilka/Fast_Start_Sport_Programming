/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 18:40:08 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/08/31 18:48:26 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

constexpr double EPSILON = 1.e-8;

double long f(long double x, long double*kf, int n)
{
	long double sum = 0.0;
	for (int i = n;i >= 0;i--)
	{
		long double tmp = kf[i]*pow(x,i);
		sum += tmp;
	}
    return (sum);
}

double long ras(double long x0, double long y0, double long x1, double long y1)
{
    return sqrt(pow((x0 - x1), 2) + pow((y0 - y1), 2));
}


double long y(long double x, long double x0, long double y0, long double R)
{
    long double y = sqrt(pow(R, 2) - pow(x - x0, 2)) + y0;
    return y;
}
double long y2(long double x, long double x0, long double y0, long double R)
{
	long double y =-sqrt(pow(R, 2) - pow(x - x0, 2)) + y0;
	return y;
}

int main()
{
	long double x0, y0, R;
	cin >> x0;
	cin >> y0;
	cin >> R;
	
	int n;
	cin >> n;
	long double *kf = new  long double[n+1];
	for(int i = n;i >= 0;i--)
	{
		cin >> kf[i];
	}

	long double x;
	cin >> x;

	long double l = x - R;
	long double r = x + R;
	long double mid;
	mid = (l + r)/2;
	long double fx = f(mid, kf, n);
	
	while (abs(ras(mid, fx, x0, y0) - R) > EPSILON)
	{
		if(ras(mid, fx, x0, y0) - R < 0.0)
		{
			l = mid;
		}
		else
		{
			r = mid;
		}
		mid = (l+r)/2;
		fx = f(mid, kf, n);
	}
	cout << setprecision(16) <<(l+r)/2.0;
	return 0;
}
