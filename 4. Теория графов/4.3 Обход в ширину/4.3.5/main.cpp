/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 18:21:32 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/09/09 18:21:35 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


int main()
{
	int n;
	int m;
	int i;
	int u;
	int v;
	int d;
	queue <int> q;

	cin >> n >> m;
	vector <vector <int> > graf(n + 1);

	i = 0;
	while (++i <= m)
	{
		cin >> u >> v;
		graf[u].push_back(v);
		graf[v].push_back(u);
	}
	d = 0;
	vector <vector <int> > dist(n + 1, vector <int> (n + 1, - 1));
	i = 0;
	while (++i <= n)
	{
		v = i;
		dist[i][v] = 0;
		q.push(v);
		while (!q.empty())
		{
			v = q.front();
			q.pop();
			for (auto u: graf[v])
			{
				if (-1 == dist[i][u])
				{
					dist[i][u] = dist[i][v] + 1;
					d += dist[i][u];
					q.push(u);
				}
			}
		}
	}
 	cout << d / 2 << "\n";
	return 0;
}
