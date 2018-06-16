/*
*	User: Isanchez_Aguilar
*	Problem: omegaUp Longest Common Subsequence
*/
#include <bits/stdc++.h>

using namespace std;

#define score(a, b) (a==b?1:0)

inline int LCS(const string s1, const string s2)
{
	int m = s1.length();
	int n = s2.length();
	int memo[m+1][n+1];

	for (int i = 0; i <= m; ++i)
	{
		for (int j = 0; j <= n; ++j)
		{
			if (not i or not j)
				memo[i][j] = 0;
 			
 			else
 			{
 				memo[i][j] = memo[i - 1][j - 1] + score(s1[i - 1], s2[j - 1]);
 				memo[i][j] = max(memo[i][j], memo[i - 1][j]);
 				memo[i][j] = max(memo[i][j], memo[i][j - 1]);
 			}
		}
	}

	return memo[m][n];
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s1;
	string s2;

	cin >> s1 >> s2;

	cout << LCS(s1, s2) << endl;

	return 0;
}