/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 15:06:40 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/08/31 15:10:42 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

long int SumLeftRight(int left, int right, int *array)
{
	long int sum;

	sum = 0;
	for (int i = left-1; i < right; i++)
	{
		sum += array[i];
	}
	return (sum);
}

int	main() 
{
    int 	n;
    int 	q;
    long  int	*Partarray;
    int 	left;
    int		right;

    cin >> n >> q;

    Partarray = new long int[n+1];
    Partarray[0] = 0;
    
    for (int i = 1;i <= n;++i)
    {
        int tmp;
        cin >> tmp;
        Partarray[i] = Partarray[i-1] + tmp;
    }
    for(int i = 0;i < q;i++)
    {
	    cin >> left >> right;
	    cout << (Partarray[right]-Partarray[left-1]) << endl;
    }
    return (0);
}
