/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 15:57:47 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/08/31 16:05:54 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

int max1(int a, int b)
{
	if (a > b) return a;
	return b;
}

int min1(int a, int b)
{
	if (a > b) return b;
	return a;
}

int main()
{
	int n;
	bool neg = true;
	long int *array;
	long int *sum;

	cin >> n;
	array = new long int[n];
	sum = new long int[n+1];
	sum[0]=0;
	for (int i=1;i <= n;i++)
	{
		int tmp;
		cin >> tmp;
		if (tmp>0)
		{
		       	neg= false;
		}
		array[i-1] = tmp;
		sum[i] = sum[i-1] + tmp;
		if(sum[i] < 0)
		{
			sum[i]=0;
		}
	}
	long int max = sum[0];
	long int min = sum[0];
	int idmax=0;
	int idmin=0;

	for (int i = 0;i <= n;i++)
	{
		if(sum[i]>max)
		{
			max = sum[i];
			idmax = i;
		}
	}
	for (int i=0;i <= idmax;i++)
	{
		if(sum[i] < min)
		{
			min = sum[i];
			idmin = i;
		}
	}

    if (neg)
    {
	    int  max=array[0];

	    for(int i = 0;i < n;i++) 
	    {
		    if (array[i] > max) 
		    {
			    max = array[i];
		    }
	    }
        cout << max;
    }
    else
	    cout<<sum[idmax]-sum[idmin]<<endl;
    return (0);
}
