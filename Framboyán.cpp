/*
*	User: Isanchez_Aguilar
*	Problem: omegaUp Framboyán
*/
#include<bits/stdc++.h>

using namespace std;

int main(void)
{
	long long n;
	cin >> n;

	if (n == 0)
		cout << "0\n";
	else if(n == 1)
		cout << "1\n";
	else
	{	
		double digits = 0;
		for (long long i = 1;i <= n; ++i)
			digits += log(i);

		digits /= log(8);
		digits = floor(digits + 1);

		cout << (long long)digits << "\n";
	}

	return 0;
}