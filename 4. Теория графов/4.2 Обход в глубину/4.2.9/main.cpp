/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 18:49:56 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/09/08 18:50:00 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#define GREY 1
#define WHITE 0
#define BLACK 2

using namespace std;

vector<int> used(501, 0);
int cicle;

void dfs(const vector<vector<int> >& graf, int to, int from)
{
	used[to] = GREY;
	for (auto u : graf[to])
	{
		if (GREY == used[u] && u != from)
			cicle = 1;
		else if (WHITE == used[u])
			dfs(graf, u, to);
	}
	used[to] = BLACK;
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
		graf[v].push_back(u);
	}
	cicle = 0;
	i = 0;
	while (++i <= n)
	{
		used[0] = 0;
		for (int j = 1; j <= n; ++j)
			used[j] = WHITE;
		dfs(graf, i, 0);
		if (cicle)
		{
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}
