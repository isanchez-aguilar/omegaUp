/*
*	User: Isanchez_Aguilar
*	Problem: omegaUp Aerodrom
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int people;
	cin >> n >> people;
	
	ll lTime = 1;
	ll rTime = -1;
	ll checkInTime[n];
	
	for (int i = 0; i < n; ++i)
	{
		cin >> checkInTime[i];
		ll currentTime = checkInTime[i] * people;
		
		rTime = max(rTime, currentTime);
	}

	ll t = lTime;
	
	while (lTime < rTime)
	{
		ll total = 0;
		ll halfTime = (lTime + rTime) >> 1ll;

		for (int i = 0; i < n; ++i)
			total += (halfTime / checkInTime[i]);
		
		if (total < people)
			lTime = halfTime + 1;
		else
		{
			t = halfTime;
			rTime = halfTime;
		}
	}

	cout << t << "\n";

	return 0;
}