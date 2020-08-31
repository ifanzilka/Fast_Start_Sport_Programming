/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 19:29:54 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/08/31 19:29:59 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>
using namespace std;
#define int long long
bool check(vector <int> a, int m, int k){
    int c = 0;
    for(int i = 0; i < a.size(); i++)
        c += a[i]/m;
    return c >= k;
}
main()
{

    int n, k;
    cin >> n >> k;
    vector <int> a;
    int d;
    int sum = 0;
    while(n--){
        cin >> d;
        a.push_back(d);
        sum += d;
    }
    if(sum < k){
        cout << 0 << endl;
        return 0;
    }
    int MAX = *max_element(a.begin(), a.end());
    int l = 0, r = LONG_MAX;
    int m;
    while(l < r){
        m = (l+r)/2;
        if(check(a, m, k)) l = m+1;
        else r = m;
    }
    cout << l-1 <<  endl;

}

