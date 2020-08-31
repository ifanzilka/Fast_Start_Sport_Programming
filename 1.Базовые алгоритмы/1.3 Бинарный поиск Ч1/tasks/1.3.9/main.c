/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 18:12:18 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/08/31 18:19:00 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

int MinNumber(int n, int k, int *array)
{
	int l = -1;
	int r = n;
    	//инвариант l<x<=r
	
	while (l + 1 < r)
	{
		int mid = (l + r)/2;
		if (array[mid] <= k)
		{
			r = mid;

		}
		else
		{
			l = mid;
		}
	}

    int cnt = r;
    if (cnt >= n)
    {
	    return (-1);
    }
   
    while (array[cnt] > k)
    {
	    cnt++;
	    if (cnt == n)
	    {
		    return (-1);
	    }
    }
    return (cnt+1);
}

int	main()
{
	int n;
	int m;
	cin >> n;
	cin >> m;

	int *array = new int[n];
	
	for (int i = 0; i < n;i++)
	{
		cin >> array[i];
	}

	for (int i = 0;i < m;i++)
	{
		int k;
		cin >> k;
        if (MinNumber(n, k, array) == -1)
	{
            cout << "NO SOLUTION" << endl;
        }
	else
	{
		cout << MinNumber(n, k, array) << endl;
	}
    }
}
