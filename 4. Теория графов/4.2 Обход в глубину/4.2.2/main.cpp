/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 16:57:45 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/09/06 16:58:10 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>

using namespace std;

vector <vector <int> > s;
vector <bool> used;
list <int> visit;

int g_cnt = 0;

void f_dfs(int v)
{
        used[v] = true;
        g_cnt++;
        visit.push_back(v);
        for (auto u: s[v])
        {
                if (used[u])
                        continue;
                f_dfs(u);
                visit.push_back(v);
                g_cnt++;
        }
}

int     main()
{
        int n, m;
        int i, j;
        int v;

        cin >> n;
        cin >> m;
        vector <vector <int> > arr(n + 1, vector <int> (n + 1, 0));
        used.resize(n + 1, false);

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
        cin >> v ;

        s.resize(n + 1);
        i = 0;
        while (++i <= n)
        {
                j = 0;
                while (++j <= n)
                {
                        if (arr[i][j])
                                s[i].push_back(j);
                }
        }
        f_dfs(v);
        cout << visit.size() << "\n";
	    for (auto u: visit)
		    cout << u << " ";
	    return 0;
}
