/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 12:31:53 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/09/05 12:32:00 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

int main()
{
	int n;
	int s;
	int i;
	int a;
	int ret;

	cin >> s >> n;
	ret = 0;
	i = 0;
	while (++i <= n)
	{
		cin >> a;
		ret += a;
		if (ret >= s)
			break ;
	}
    if (ret > s)
		ret = s;
	cout << ret << endl;
	return 0;
}
