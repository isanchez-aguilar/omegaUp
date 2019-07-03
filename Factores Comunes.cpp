#include <bits/stdc++.h>

using namespace std;

typedef long long Long;

Long a;
Long b;
Long i;
Long factor;
pair<Long, int> divisors[10002];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int size = 0;

	cin >> a >> b;

	if (a > b)
		swap(a, b);
	
	for (i = 2; a > 1 and i * i <= a; ++i)
	{
		if (a % i == 0)
		{
			int power = 0;

			while (a % i == 0)
			{
				a /= i;
				++power;
			}

			divisors[size].first = i;
			divisors[size++].second = power;
		}
	}

	if (a > 1)
	{
		divisors[size].first = a;
		divisors[size++].second = 1;	
	}

	int factors = 1;

	for (int j = 0; j < size; ++j)
	{
		factor = divisors[j].first;
		
		if (b < factor)
			break;

		if (b % factor == 0)
		{	
			int power = 0;
			int p = divisors[j].second;


			while (b % factor == 0 and power < p)
			{
				++power;
				b /= factor;
			}

			factors *= (power + 1);
		}
	}

	cout << factors << "\n";
	
	return 0;
}