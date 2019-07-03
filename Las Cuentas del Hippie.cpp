/*
*	User: Isanchez_Aguilar
*	Problem: UVA Las Cuentas del Hippie
*/
#include <bits/stdc++.h>

using namespace std;

int n;
int m;
int size;
size_t l = 0;
size_t r = 0;
int colour[60000];
int currentBlack;
int differentColour;
int minimalWaste = 60000;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
		
	cin >> m >> n;
	
	for (size_t i = 0; i < n; ++i)
	{
		cin >> colour[i];
		colour[i + n] = colour[i];
	}

	size = n << 1;
	currentBlack = (colour[0] == 0?1:0);
	differentColour = 1 - currentBlack;
	
	
	while (r < size)
	{
		if (currentBlack < m)
		{
			if (r + 1 < size)
			{
				if (colour[++r] == 0)
					++currentBlack;
				else
					++differentColour;
			}
			else
				break;
		}
		else
		{
			if (differentColour < minimalWaste)
				minimalWaste = differentColour;	
			
			if (colour[l++] == 0)
				--currentBlack;
			else
				--differentColour;
		}
	}
	
	cout << minimalWaste << "\n";

	return 0;
}
