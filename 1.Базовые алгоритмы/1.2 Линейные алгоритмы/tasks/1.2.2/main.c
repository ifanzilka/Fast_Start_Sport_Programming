#include <iostream>

using namespace std;

int 		n;
long int 	sum;
int 		k;

int	main(void)
{
	int i;

	i = 0;
	sum = 0;
	k = 0;
	cin>>n;

        while (i < n)
	{
	       	cin >> k;
		sum += k;
		i++; 
	}
	cout << sum;
	return (0);
}
