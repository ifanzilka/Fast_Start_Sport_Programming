/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 16:31:11 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/08/31 16:37:36 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

int fastForward(int year) {
    if (year > 98765431) return -1;

    bool digits[10] = { true, false, true, false, false, false, false, false, false, false };
    int reversed[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    int numDigits = 0;

    do {
        int digit = year % 10;
        reversed[numDigits] = digit;
        year /= 10;
        numDigits++;
    } while (year > 0);

    int suggest = 0;
    for (int i = 0; i < numDigits; i++)
    {
        int digit = reversed[numDigits-i-1];
        if (digits[digit]) {
            bool found = false;
            for (int j = digit+1; j < 10; j++)
            {
                if (!digits[j]) {
                    digit = j;
                    found = true;
                    break;
                }
            }
            if (!found) {
                suggest = ++suggest * 10;
            } else {
                suggest = suggest * 10 + digit;
            }

            for (int j = 0; j < numDigits-i-1; j++)
            {
                suggest *= 10;
            }
            return fastForward(suggest);
        } else {
            //  regular path;
            suggest = suggest*10 + digit;
            digits[digit] = true;
        }
    }
    
    return suggest;
}

int main() {
    int year;
    cin >> year;

    int nextYear = fastForward(year+1);
    
    cout << nextYear;
    return 0;
}
