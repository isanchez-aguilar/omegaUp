/*
*	User: Isanchez_Aguilar
*	Problem: UVA 11728 - Alternate Task
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string s1;
	string s2;
	
	while (cin >> s1 >> s2)
	{
		int i = 1;
		int j = 1;
		int mod1 = (s1[0] - 'A' + 1) % 47;
		int mod2 = (s2[0] - 'A' + 1) % 47;
		
		while (i < s1.length() and j < s2.length())
		{
			mod1 = mod1 * (s1[i++] - 'A' + 1) % 47;
			mod2 = mod2 * (s2[j++] - 'A' + 1) % 47;
		}

		while (i < s1.length())
			mod1 = mod1 * (s1[i++] - 'A' + 1) % 47;
		
		while (j < s2.length())
			mod2 = mod2 * (s2[j++] - 'A' + 1) % 47;
		
		if (mod1 == mod2)
			cout << "GO\n";
		else
			cout << "STAY\n";
	}

	return 0;
}
