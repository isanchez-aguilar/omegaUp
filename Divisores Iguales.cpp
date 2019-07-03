#include <bits/stdc++.h>

using namespace std;

const int MAX = 2000000;

short divisors[MAX];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 1; i < MAX; ++i)
	{
		for (int j = i; j < MAX; j += i)
			++divisors[j];
	}

	int n;
	cin >> n;

	int left = n - 1;
	int right = n + 1;
	int nDivisors = divisors[n];


	while (true)
	{
		if (right < MAX and nDivisors == divisors[right])
		{
			cout << right << "\n";
			break;
		}
		
		if (left > 0 and nDivisors == divisors[left])
		{
			cout << left << "\n";
			break;
		}

		--left;
		++right;
	}

	return 0;
}