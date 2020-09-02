/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 12:19:00 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/09/02 12:23:46 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

int	main()
{
	long long A, B, mod, A2, B2;
	mod = 1000007;
	cin >> A >> B;
	A2 = ((A % mod)*(A % mod))% mod;
	
	if(A2 < 0)
	{
		A2 += mod;
	}
	B2 = ((B % mod) * (B % mod)) % mod;
        
	if (B2 < 0)
	{
		B2 += mod;
	}
    
	if ((A2 - B2) % mod < 0)
	{
		cout << (A2 - B2) % mod + mod;
	}
	else
	{
		cout << (A2 - B2) % mod;
	}
	return (0);
}
