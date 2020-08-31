/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 17:37:28 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/08/31 17:41:56 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

int MinNumber(int n, int k, int *array)
{
	int l =- 1;
	int r = n;

	while (l + 1 < r)
	{
		int mid = (l+r)/2;

		if(array[mid] < k)
		{
			l = mid;
		}
		else
		{
			r = mid;
		}
	}
    return (array[r]);
}

int	main()
{
	int n;
	int m;

	cin >> n;
	cin >> m;
	int *array = new int[n];

	for(int i = 0;i < n;i++)
	{
		cin >> array[i];
	}

	for(int i = 0;i < m;i++)
	{

		int k;
		cin >> k;
		if(MinNumber(n, k, array) < k)
		{
			cout << "NO SOLUTION" << endl;
		}
		else
		{
			cout<<MinNumber(n,k,array)<<endl;
		}
	}
}
