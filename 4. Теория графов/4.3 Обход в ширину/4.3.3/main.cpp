/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 18:10:46 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/09/09 18:11:10 by ifanzilka        ###   ########.fr       */
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
	queue <int> q;
	vector <int> solve;

	cin >> n >> m;
	vector <vector <int> > graf(n + 1);

	i = 0;
	while (++i <= m)
	{
		cin >> u >> v;
		graf[u].push_back(v);
		graf[v].push_back(u);
	}
	vector<int> used(n + 1, 0);
	cin >> v;
    
	used[v] = 1;
	q.push(v);
	solve.push_back(v);
	while (!q.empty())
	{
		v = q.front();
		q.pop();
		for (auto u: graf[v])
		{
			if (used[u])
				continue;
			used[u] = 1;
			q.push(u);
			solve.push_back(u);
		}
	}
	i = -1;
	while (++i < n)
		cout << solve[i] << " ";
	cout << "\n";
	return 0;
}
