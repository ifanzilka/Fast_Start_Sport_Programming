/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 17:00:58 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/08/31 17:05:02 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

int GetFirstOne(int n,int k)
{
	int count=0;
	int l=-1;
	int r=n;
       	
	while (l + 1 < r)
	{
		int mid=(l+r)/2;
		if (mid < k)
		{
			l = mid;
			count +=1;
		}
		else
		{
			r = mid;
			count+=1;
		}
	}
	return (count);
}

int	main() 
{
	int n;
	int m;

	cin >> n;
	cin >> m;
	
	for(int i = 0;i < m;i++)
	{
		int k;
		cin >> k;
		cout << GetFirstOne(n,k) << endl;
	}
}
