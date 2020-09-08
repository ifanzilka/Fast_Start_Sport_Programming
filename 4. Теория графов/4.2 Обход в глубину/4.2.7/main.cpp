/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 01:06:06 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/09/08 01:07:09 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

int matrix[501][501];
vector<int> used(501, 0);
vector<pair<int, int>> edges;
set<int> edges_numbers;
vector<int> edges_solve;
int n;

void add_number(int u, int v)
{
	int tmp;

	tmp = matrix[u][v];
	if (tmp)
		edges_numbers.insert(tmp);
}

void dfs(const vector<vector<int> >& graf, int to, int from, vector<int> & edges_track, int edge)
{
	int tmp; 
	int count_vertices;

	
	edges_track[edge] = 1;
	add_number(to, from);
	used[to] = 1;
	count_vertices = 0;
	for (auto u : graf[to])
	{
		if (0 == used[u])
		{
			tmp = matrix[to][u];
			++count_vertices;
			if (edges_solve[tmp] && edges_track[tmp] == 0)
			{
				--count_vertices;
				dfs(graf, u, to, edges_track, tmp);
			}
		}
	}
	if (count_vertices)
	{
		for (int j = 0; j <= n; ++j)
			used[j] = 1;
	}
}

int main()
{
	int m;
	int i;
	int u;
	int v;
	set<int> vertices;
	set<int> set_edges_solve;
	vector<int> edges_diff;
	int tmp;
	int q;

	cin >> n >> m;
	vector <vector <int> > graf(n + 1);
	i = 0;
	while (++i <= m)
	{
		cin >> u >> v;
		edges.push_back(make_pair(u, v));
		graf[u].push_back(v);
		graf[v].push_back(u);
		matrix[u][v] = i;
		matrix[v][u] = i;
	}
	cin >> q;
	edges_solve.resize(m + 1);
	for (int j = 0; j <= m; ++j)
		edges_solve[j] = 0;

	for (int i  = 1; i <= q; ++i)
	{
		cin >> tmp;
		edges_solve[tmp] = i;
		set_edges_solve.insert(tmp);
		vertices.insert(edges[tmp - 1].first);
		vertices.insert(edges[tmp - 1].second);
	}
	if (q != n - 1)
    {
        cout << "NO";
        return 0;
    }
	if (q == 0 && n == 1)
    {
        cout << "YES";
        return 0;
    }
	vector<int> edges_track(m + 1, 0);
	for (int i1 : vertices)
	{
		used[0] = 2;
		for (int j = 1; j <= n; ++j)
			used[j] = 0;
		edges_numbers.clear();
		edges_diff.clear();
		for (int j = 0; j <= m; ++j)
			edges_track[j] = 0;

		dfs(graf, i1, 0, edges_track, 0);
		set_symmetric_difference(set_edges_solve.begin(), set_edges_solve.end(), edges_numbers.begin(), edges_numbers.end(), back_inserter(edges_diff)); 
		if (edges_diff.size() == 0)
		{
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}
