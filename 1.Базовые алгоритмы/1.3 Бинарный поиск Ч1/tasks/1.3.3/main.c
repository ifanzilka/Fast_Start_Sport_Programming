/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 17:08:30 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/08/31 17:11:26 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

int main()
{
	int n;
	int m;

	cin >> n;
	cin >> m;
	int l = -1;
	int r = n;

    int *array = new int[n];
    for(int i = 0;i < n;i++)
    {

        array[i] = 0;
    }
    for(int i = 0;i < m;i++)
    {
	    int k;
	    cin >> k;
	    int mid = (l+r)/2;
	    array[mid] = k;

        if (array[mid] == 0)
	{
            l = mid;
        }
	else
	{
		r=mid;
        }
    }

    int answer = n;
    for(int i = 0;i < n;i++)
    {
        if (array[i] == 1)
	{
		cout << i;
            return (0);
        }
    }
    cout << answer;
}
