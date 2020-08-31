/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 14:18:28 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/08/31 14:31:25 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int mod = 1791791791;
long int n,cur ,a,b;

int NextRand()
{
	cur = (cur * a + b ) % mod;
	return (cur);
}

using namespace std;

int main() 
{
	int idmax1, idmax2;
	int max1, max2;
	std::cin >> n;
	cin >> cur >> a >> b;
	int *array = new int[n];
	
	for (int i = 0;i < n; i++)
	{
		array[i]=NextRand();
	}
	idmax1 = 0;
	max1 = array[0];
	for(int i = 0;i < n;i++)
	{
		if (array[i] > max1)
		{
			max1 = array[i];
			idmax1 = i;
		}
	}
	
	max2 = -1;
	for(int i = 1;i < n;i++)
	{
		if (array[i] > max2 && i != idmax1)
		{
			max2=array[i];
			idmax2=i;
		}
	}
	cout << (idmax1+1) << " " <<(idmax2+1);
	return (0);
}
