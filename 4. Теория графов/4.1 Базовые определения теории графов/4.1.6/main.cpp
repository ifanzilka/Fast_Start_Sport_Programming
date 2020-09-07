/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 10:59:09 by ifanzilka         #+#    #+#             */
/*   Updated: 2020/09/07 12:24:48 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

using namespace std;

int     main()
{
        int n;
        char str[501];
        int i , j;
        int s_size;
    
        cin >> n;
        vector <vector <int>> arr(n + 1, vector <int> (n + 1));
    
        i = 0;
        while (++i <= n)
        {
		    scanf("%s", str);
		    j = -1;
		    while (++j <= n)
		    {
			    if (str[j] == '0')
				    arr[i][j + 1] = 0;
			    else
				    arr[i][j + 1] = 1;
		    }
	    }
        
        vector <int> s;
	    i = 0;
	    while (++i <= n)
	    {
		    j = 0;
		    while (++j <= n)
		    {
			    if (arr[i][j]) 
				    s.push_back(j);
		    }
		    s_size = s.size();	
		    cout << s_size << " ";
		    j = -1;
		    while (++j < s_size)
			    cout << s[j] << " ";
		    cout << "\n";
		    s.clear();
	    }
    return 0;
}
