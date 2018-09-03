/*
*	User: Isanchez_Aguilar
*	Problem: omegaUp Planetas
*/
#include <bits/stdc++.h>

using namespace std;

int n;
double position[1000];

inline double f(double x)
{
	double force = 0;

	for (int i = 0; i < n; ++i)
		force += 1.0 / (position[i] - x);
	
	return force;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> position[i];
	
	double l;
	double r;
	double m;

	cout << n - 1 << "\n";
	sort(position, position + n);

	for (int i = 0; i < n - 1; ++i)
	{
		l = position[i];
		int iterations = 0;
		r = position[i + 1];
		
		while (iterations < 26)
		{
			m = (l + r) / 2.0;

			if (f(m) < 0.0)
				l = m;
			else
				r = m;

			++iterations;
		}

		cout << (i?" ":"") << fixed << setprecision(3) << l;
	}

	return 0;
}