/*
*	User: Isanchez_Aguilar
*	Problem: omegaUp SUMO
*/
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

class DisjointSet
{
public:
	int n;
	vector<int> rank;
	vector<int> parent;

	DisjointSet(int _n):n(_n), rank(_n), parent(_n)
	{
		for (int i = 0; i < n; ++i)
		{
			rank[i] = 0;
			parent[i] = i;
		}
	}

	inline int findParent(int element)
	{
		if (parent[element] == element)
			return element;

		return (parent[element] = findParent(parent[element]));
	}

	inline bool isSameSet(int element1, int element2){ return(findParent(element1) == findParent(element2)); }
	
	inline void unionSet(int element1, int element2)
	{
		if (not isSameSet(element1, element2))
		{
			int x = findParent(element1);
			int y = findParent(element2);

			if (rank[x] < rank[y])
			{
				parent[x] = y; 
			}
			else
			{
				parent[y] = x;
				
				if (rank[x] == rank[y])
					++rank[x];
			}
		}
	}
};

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int m;
	cin >> n >> m;
	
	ii fight[m];
	DisjointSet sumo(n);
	
	for (int i = 0; i < m; ++i)
	{
		int a;
		int b;

		cin >> a >> b;
		fight[i] = ii(a - 1, b - 1);
	}

	vector<int> adj(n, -1);

	for (int i = 0; i < m; ++i)
	{
		if (sumo.isSameSet(fight[i].first, fight[i].second))
		{
			cout << i + 1 << "\n";
			break;
		}

		int parentX = sumo.findParent(fight[i].first);
		int parentY = sumo.findParent(fight[i].second);

		if (adj[parentX] != -1)
			sumo.unionSet(adj[parentX], parentY);
		
		if (adj[parentY] != -1)
			sumo.unionSet(adj[parentY], parentX);

		adj[parentX] = parentY;
		adj[parentY] = parentX;
	}

	return 0;
}