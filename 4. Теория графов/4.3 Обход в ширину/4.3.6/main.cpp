/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 18:25:27 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/09/09 18:32:40 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#define MAXN 101
using namespace std;


int m;
int n;
int p;
int q;
int is_solve;
int x2;
int y2;
vector<pair<int, int>> vertices;
vector <set <int> > graf(MAXN * MAXN);
int matrix[MAXN][MAXN];

void build_graf(int x, int y, int prev)
{
	int current;
	if (-1 == matrix[x][y])
	{
		vertices.push_back(make_pair(x, y));
		current = vertices.size() - 1;
		matrix[x][y] = current;
		if (current)
		{
			graf[current].insert(prev);
			graf[prev].insert(current);
		}
	}
	else 
	{
		current = matrix[x][y];
		if (current)
		{
			graf[current].insert(prev);
			graf[prev].insert(current);
		}
		return;
	}
	if (x == x2 && y == y2)
		is_solve = current;
	if (x + p <= m && y + q <= n)
		build_graf(x + p, y + q, current);
	if (x + p <= m && y - q > 0)
		build_graf(x + p, y - q, current);
	if (x - p > 0 && y + q <= n)
		build_graf(x - p, y + q, current);
	if (x - p > 0 && y - q > 0)
		build_graf(x - p, y - q, current);
	if (x + q <= m && y + p <= n)
		build_graf(x + q, y + p, current);
	if (x + q <= m && y - p > 0)
		build_graf(x + q, y - p, current);
	if (x - q > 0 && y + p <= n)
		build_graf(x - q, y + p, current);
	if (x - q > 0 && y - p > 0)
		build_graf(x - q, y - p, current);
}

int main()
{
	int x1;
	int y1;
	int v;
	int d;
	queue <int> qu;

	for (int i1 = 0; i1 < MAXN; ++i1)
	{
		for (int j1 = 0; j1 < MAXN; ++j1)
			matrix[i1][j1] = -1;
	}

	cin >> m >> n >> p >> q >> x1 >> y1 >> x2 >> y2;
	is_solve = -1;
	build_graf(x1, y1, 0);
	/*cout << "MATRIX \n ";
	for (int i1 = 0; i1 <= m; ++i1)
	{
		for (int j1 = 0; j1 <= n; ++j1)
			cout << matrix[i1][j1] << " ";
		cout << "\n ";
	}
	*/
	n = vertices.size();
	/*
	cout << "GRAF \n ";
	for (int i1 = 0; i1 < n; ++i1)
	{
		for (int j1 : graf[i1])
			cout << j1 << " ";
		cout << "\n ";
	}

	cout << "vertices \n ";
	for (auto i1 : vertices)
	{
			cout << i1.first << " " << i1.second << "\n";
	}
	cout << "vertices end \n ";
	*/	
	if (is_solve < 1)
	{
		cout << is_solve << "\n";
		return 0;
	}

	d = 0;
	vector <int>  dist(n,- 1);
	v = 0;
	dist[v] = 0;
	qu.push(v);
	while (!qu.empty())
	{
		v = qu.front();
		qu.pop();
		for (int u : graf[v])
		{
			if (-1 == dist[u])
			{
				dist[u] = dist[v] + 1;
				if (matrix[x2][y2] == u)
				{
					cout <<  dist[u] << "\n";
					return 0;
				}
				qu.push(u);
			}
		}
	}
	return 0;
}
