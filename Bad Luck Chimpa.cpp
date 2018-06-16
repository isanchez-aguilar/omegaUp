/*
*	User: Isanchez_Aguilar
*	Problem: omegaUp El Bryan
*/
#include <bits/stdc++.h>

using namespace std;

class Point
{
public:
	unsigned long long x;
	unsigned long long y;
	Point():x(0), y(0){ }
};

inline unsigned long long distSq(const Point a, const Point b)
{
	unsigned long long dx = max(a.x, b.x) - min(a.x, b.x);
	unsigned long long dy = max(a.y, b.y) - min(a.y, b.y);

	return dx * dx + dy * dy;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int m;
	cin >> n >> m;

	Point chimpa;
	Point medina;
	cin >> chimpa.x >> chimpa.y >> medina.x >> medina.y;

	unsigned long long radius[26];

	for (int i = 0; i < n; ++i)
	{
		char c;
		unsigned long long r;
		
		cin >> c >> r;
		radius[c - 'A'] = r * r;
	}

	int times = 0;
	bool tie = false;
	bool winChimpa = false;
	bool ignoreMoves = false;

	for (int i = 0; i < m; ++i)
	{
		char c;
		Point center;
		cin >> c >> center.x >> center.y;

		if (ignoreMoves)
			continue;

		unsigned long long explosionChimpa = distSq(center, chimpa);
		unsigned long long explosionMedina = distSq(center, medina);

		if (explosionChimpa <= radius[c - 'A'])
		{
			if (explosionMedina <= radius[c - 'A'])
				tie = true;

			ignoreMoves = true;	
			continue;
		}

		if (explosionMedina <= radius[c - 'A'])
		{
			++times;
			winChimpa = true;
		}

	}

	if (winChimpa)
	{
		cout << "Chimpa gana";

		if (times > 1)
			cout << " x " << times;
		
		cout << "!\n";
	}
	else if (tie)
		cout << "Ethan dira: Au au, no puedo ganar, amo\n";
	else
		cout << "El futuro esta condenado\n";

	return 0;
}