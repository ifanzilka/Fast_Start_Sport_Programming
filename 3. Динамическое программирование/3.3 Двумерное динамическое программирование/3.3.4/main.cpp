/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 10:49:39 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/09/04 10:49:57 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include<vector>
#include"string"
#include<algorithm>
#include<map>
#include"queue"
#include"stdlib.h"
#include"stdio.h"
using namespace std;


int main()
{

    int n;
    cin >> n;
    vector<vector<int>>v;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        v[i].resize(i + 1);
        for (int j = 0; j <= i; j++) {
            cin >> v[i][j];
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            int temp = -1000;
            if (j != i) {
                temp = v[i - 1][j];
            }
            if (j != 0 && temp < v[i - 1][j - 1]) {
                temp = v[i - 1][j - 1];
            }
            v[i][j] = v[i][j] + temp;
        }
    }
    int ma = -1000000;
    for (int i = 0; i < n; i++) {
        if (v[n - 1][i]>ma)
        {
            ma = v[n - 1][i];
        }
    }
    cout << ma;
}
