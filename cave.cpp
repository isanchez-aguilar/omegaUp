#include "cave.h"


// Main
//	int tryCombination(int N, int S[])
//	void answer(int N, int S[], int D[])

int _door;
int _s[5002];
int _d[5002];
int _status;
bool _switch[5002];
int _currentStatus;

void exploreCave(int n)
{
	for (int i = 0; i < n; ++i)
	{
		_door = tryCombination(n, _s);

		if (_door == -1 or _door > i)
			_status = 0;
		else
			_status = 1;

		int l = 0;
		int r = n - 1;

		while (l != r)
		{
			int m = (l + r) >> 1;

			for (int j = l; j <= m; ++j)
			{
				if (not _switch[j])
					_s[j] = 1 - _s[j];
			}

			_door = tryCombination(n, _s);

			for (int j = l; j <= m; ++j)
			{
				if (not _switch[j])
					_s[j] = 1 - _s[j];
			}

			if (_door == -1 or _door > i)
				_currentStatus = 0;
			else
				_currentStatus = 1;

			if (_currentStatus == _status)
				l = m + 1;
			else
				r = m;
		}

		_d[l] = i;
		_s[l] = _status;
		_switch[l] = true;
	}

	answer(n, _s, _d);

	return;
}