/*
*	User: Isanchez_Aguilar
*	Problem: omegaUp Cafetería
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int c;
	int n;
	int d;
	int t;
	cin >> c >> n >> d >> t;

	int times[c];
	for (int i = 0; i < c; ++i)
		cin >> times[i];

	sort(times, times + c);

	int totalTime = 0;
	int currentTime[c];
	memset(currentTime, 0, sizeof currentTime);

	for (int t = 1; t <= 20000000 and n > 0; ++t)
	{
		for (int j = 0; j < c; ++j)
		{
			++currentTime[j];
			n -= (currentTime[j] / times[j]);
			
			currentTime[j] %= times[j];
			
			if (n <= 0)
			{
				totalTime = t;
				break;
			}
		}
	}

	if (totalTime + times[0] + (d << 1) - t <= 0)
		cout << "SI\n";
	else
		cout << "NO\n";

	return 0;
}