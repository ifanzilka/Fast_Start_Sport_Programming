/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 00:46:39 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/09/08 00:59:04 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

using namespace std;

vector<int> used(501, 0);
vector<pair<int, int>> edges;
vector<int> edges_numbers;

void add_number(int u, int v)
{
	int ret;

	for (int i = 0; i <= edges.size(); ++i)
	{
		if ((edges[i].first == u && edges[i].second == v) || (edges[i].first == v && edges[i].second == u))
			{
				edges_numbers.push_back(i + 1);
				return ;
			}
	}
}

void dfs(const vector<vector<int> >& graf, int to)
{
	used[to] = 1;
	for (auto u : graf[to])
	{
		if (0 == used[u])
		{
			add_number(u, to);
			dfs(graf, u);
		}
	}
	used[to] = 2;
}

int main()
{
	int n;
	int m;
	int i;
	int u;
	int v;

	cin >> n >> m;
	vector <vector <int> > graf(n + 1);
	i = 0;
	while (++i <= m)
	{
		cin >> u >> v;
		edges.push_back(make_pair(u, v));
		graf[u].push_back(v);
		graf[v].push_back(u);
	}

	used[0] = 2;
	dfs(graf, 2);
	cout << edges_numbers.size() << "\n";
	for (auto i : edges_numbers)
		cout << i << " ";
	return 0;
}
