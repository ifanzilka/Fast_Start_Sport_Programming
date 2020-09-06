/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 13:28:13 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/09/06 13:31:30 by ifanzilka        ###   ########.fr       */
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
        cin >> m;
        vector <vector <int> > arr(n + 1, vector <int> (n + 1, 0));
        i = 0;
        while (i < m)
        {
                int u;
                int v;
                cin >> u;
                cin >> v;
                arr[u][v] = 1;
                arr[v][u] = 1;
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
