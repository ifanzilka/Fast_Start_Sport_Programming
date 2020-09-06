/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 22:57:26 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/09/06 22:57:33 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>

using namespace std;

vector <vector <int> > s;
vector <int> used;
int g_cnt = 0;

void f_dfs(int v, int from)
{
        used[v] = 1;
        for (auto u: s[v])
        {
                if (used[u] == 1 && u != from)
                        g_cnt++;
                else if (used[u] == 0)
                        f_dfs(u, v);
        }
        used[v] = 2;
}

int     main()
{
        int n, m;
        int i, j;
        int v;

        cin >> n;
        cin >> m;
        used.resize(n + 1, 0);
        s.resize(n + 1);
        i = 0;
        while (i < m)
        {
                int u;
                int v;

                cin >> u;
                cin >> v;
                s[u].push_back(v);
                s[v].push_back(u);
                i++;
        }
        f_dfs(1,0);
        cout << g_cnt;
        return 0;
}
