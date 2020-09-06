/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 13:33:57 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/09/06 13:38:10 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

using namespace std;

int     main()
{
        int n;
        int m;
        int i;
        int j;
        int s_size;

        cin >> n;
        vector <vector <int> > arr(n + 1, vector <int> (n + 1, 0));
        i = 1;
        while (i <= n)
        {
		cin >> m;
		j = 0;
		while (j < m)
		{
			int tmp;
			cin >> tmp;
			arr[i][tmp] = 1;
			j++;
		}
                i++;
        }    
        i = 1;
        j = 1;
        while (i <= n)
        {
                j = 1;
                while(j <= n)
                {
                        cout <<arr[i][j];
                        j++;
                }
                i++;
                cout << endl;
        }
        return(0);
}
