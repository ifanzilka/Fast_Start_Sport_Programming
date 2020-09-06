/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 11:23:08 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/09/06 11:49:32 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

using namespace std;

int	main()
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
        vector <int> s;
	i = 0;
	while (++i <= n)
	{
		j = 0;
		while (++j <= n)
		{
			if (arr[i][j]) 
				s.push_back(j);
		}
		s_size = s.size();	
		cout << s_size << " ";
		j = -1;
		while (++j < s_size)
			cout << s[j] << " ";
		cout << "\n";
		s.clear();
	}
	return(0);
}
