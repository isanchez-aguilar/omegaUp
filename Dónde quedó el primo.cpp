/*
*	User: Isanchez_Aguilar
*	Problem: omegaUp ¿Dónde quedó el primo?
*/
#include <bits/stdc++.h>

#define MAX 9832718

using namespace std;

int main(void)
{
	int n;
	vector<int> primes;
	vector<bool> isNotPrime(MAX);
	
	cin >> n;
	for (int i = 2; i < MAX and primes.size() < n; ++i)
	{
		if (not isNotPrime[i])
		{
			for (int j = (i << 1); j < MAX; j += i)
				isNotPrime[j] = true;

			primes.push_back(i);
		}
	}

	cout << primes[n - 1] << "\n";

	return 0;
}