/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 21:15:57 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/09/05 21:17:13 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#define MAXN	301

using namespace std;

int f_sort(long long *p, long long *w, long long *c, int i)
{
	if (w[p[i]] == 0 && w[p[i - 1]] == 0 && c[p[i]] < c[p[i - 1]])
		return 1;
	if (w[p[i]] != 0 && w[p[i - 1]] == 0)
		return 1;
	if (c[p[i]] * w[p[i - 1]] < c[p[i - 1]] * w[p[i]]) 
		return 1;
	return 0;
}

int main()
{
	int n;
	int s;
	int i;
	int j;
	int k;
	int tmp;
	long long w[MAXN];
	long long c[MAXN];
	long long p[MAXN];  //order

	cin >> s >> n;
	i = -1;
	while (++i <= n)
		p[i] = i;
	i = 0;
	while (++i <= n)
		cin >> w[i];
	i = 0;
	while (++i <= n)
		cin >> c[i];
	i = n;
	while (i > 1)
	{
		k = 0;
		j = 1;
		while (++j <= i)
		{
			if (f_sort(p, w, c, j))
			{
				tmp = p[j -1];
				p[j - 1] = p[j];
				p[j] = tmp;
				k = j;
			}
		}
		i = k;
	}
	i = n;
	long long w_tmp = 0;  //summa weight
	long long c_tmp = 0;  //summa cost
	while (i > 0)
	{
 		if (w_tmp + w[p[i]] > s)
		{
			c_tmp += ((s - w_tmp) * c[p[i]] + w[p[i]] - 1) / w[p[i]];
			break;
		}
		else
		{
			w_tmp += w[p[i]];
			c_tmp += c[p[i]];
		}
		i--;
	}
	cout << c_tmp << endl;
	return 0;
}

