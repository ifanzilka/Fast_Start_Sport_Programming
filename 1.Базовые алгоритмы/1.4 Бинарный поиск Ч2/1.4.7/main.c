/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 19:27:05 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/08/31 19:27:22 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main() {
    int K, l, r, N, barns[10000];
    
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; scanf("%d", barns + i++));
    
    for (int i = 1; i < N; barns[i++] -= barns[0]);
    barns[0] = 0;

    for (l = - 1, r = barns[N-1]; l + 1 < r;) {
        int L = (l + r) / 2, max_cows = 1;
        for (int i = 1, start = barns[0]; i < N; ++i)
            if (barns[i] > start + L) {
                start = barns[i];
                ++max_cows;
            }
        max_cows >= K ? (l = L) : (r = L);
    }
    
    printf("%d", r);
}
