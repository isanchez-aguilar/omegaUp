#include <bits/stdc++.h>

using namespace std;

typedef int Long;

const int MAX = 5111500;

short divisors[MAX];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i < MAX; ++i)
	{
		for (int j = i; j < MAX; j += i)
			++divisors[j];

		if (divisors[i] == 4)
		{
			if (--n == 0)
			{
				cout << i << "\n";
				break;
			}
		}
	}
	
	return 0;
}