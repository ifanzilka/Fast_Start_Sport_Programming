/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 19:23:16 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/09/08 19:40:23 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> used(501, 0);
int pos;
vector<int> solve;
int cicle;

void dfs(const vector<vector<int> >& graf, int to, int from)
{
	used[to] = 1;
	for (auto u : graf[to])
	{
		if (1 == used[u])
			cicle = 1;
		else if (0 == used[u])
			dfs(graf, u, to);
	}
	used[to] = 2;
	solve[--pos] = to;
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
		graf[u].push_back(v);
	}
	pos = n;
	solve.resize(n + 1);
	cicle = 0;
	i = 0;
	while (++i <= n)
	{
		if (0 == used[i])
			dfs(graf, i, 0);
		if (cicle)
		{
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	i = -1;
	while (++i < n)
		cout << solve[i] << " ";
	return 0;
}
