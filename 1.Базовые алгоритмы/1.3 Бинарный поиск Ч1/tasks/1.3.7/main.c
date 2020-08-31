/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 17:46:55 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/08/31 17:55:36 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

bool CheckNumber(int n, int k, int *array)
{
	int l =- 1;
	int r = n;
	
	while (l + 1 < r)
	{
		int mid = (l+r)/2;
		if (array[mid] == k)
		{
			return (true);
		}
		if (array[mid] < k)
		{
			l = mid;
		}
		else
		{
			r = mid;
		}
	}
	if (array[r] == k && r < n)
	{
		return (true);
	}
	return (false);
}

int MinNumber(int n, int k, int *array)
{
	int	l =- 1;
	int	r = n;
   
	while (l + 1 < r)
	{
		int mid=(l+r)/2;
		
		if (array[mid] <= k)
		{
			l = mid;
		}
		else
		{
			r = mid;
		}
	}
        if (array[r] == k)
	{   
            return array[r+1];
        }
        return array[r];
}

int main()
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
            if (CheckNumber(n, MinNumber(n, k, array), array) == false)
	    {
                cout <<"NO SOLUTION"<<endl;
            }
	    else
	    {
		    cout<<MinNumber(n,k,array)<<endl;
	    }
	}
}
