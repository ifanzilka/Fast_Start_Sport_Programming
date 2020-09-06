/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 20:48:03 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/09/06 20:48:41 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>

using namespace std;

vector <vector <int> > s;
vector <bool> used;
vector <vector <int> > cmp_num;

int g_num_comp = 1;

void f_find(int v)
{
        for (int i = 1; i < g_num_comp ; i++)
        {        
                for (auto s: cmp_num[i])
                {
                    if (v == s)
                    {
                        cout << i << " ";
                        return ;
                    }    
                }
        }
}

void f_dfs(int v)
{
        used[v] = true;
        cmp_num[g_num_comp].push_back(v);
        for (auto u: s[v])
        {
                if (used[u])
                        continue;
                f_dfs(u);
                cmp_num[g_num_comp].push_back(v);
        }
}

int     main()
{
        int n, m;
        int i, j;
        int v;

        cin >> n;
        cin >> m;
        used.resize(n + 1, false);
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
        cin >> v ;

        int cnt_comp = 0;
        cmp_num.resize(n + 1);  
        for (int i = 1; i <= n; i++)
        {
                if (used[i])
                    continue;
                f_dfs(i);
                cnt_comp++;
                g_num_comp++;
        }
        cout << cnt_comp << endl;
        for (int i = 1; i <= n ; i++)
        {        
                f_find(i);
        }
            return 0;
}

