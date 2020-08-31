/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 17:31:54 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/08/31 17:34:55 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

bool CheckNumber(int n,int k,int *array)
{
    int l =- 1;
    int r = n;
    while (l + 1 < r)
    {
        int mid = (l+r)/2;
        if(array[mid] == k)
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
    if(array[r] == k && r < n)
    {
        return (true);
    }
    return (false);
}

int main() 
{
    int n;
    int m;
    cin >> n;
    cin >> m;

    int *array=new int[n];
    for(int i = 0;i < n;i++)
    {

        cin >> array[i];
    }

    for(int i = 0;i < m;i++)
    {
        int k;
        cin >> k;
        if(CheckNumber(n,k,array))
	{
            cout << "YES" << endl;
        }
	else
	{
            cout << "NO" << endl;
        }
    }
}
