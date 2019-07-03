#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef unsigned int Long;

struct Event
{
	Long x1;
	Long y1;
	Long x2;
	Long y2;
	char type; // -1 left point, 0 vertical segment and 1 right point.

	Event(Long _x1, Long _y1, Long _x2, Long _y2, char _type)
	{
		x1 = _x1;
		y1 = _y1;
		x2 = _x2;
		y2 = _y2;
		type = _type;
	}

	inline bool operator<(const Event& e)
	{
		return x1 == e.x1?type < e.type:x1 < e.x1;
	}
};

const size_t size = 10000002;
Long sum[size];

inline void addValue(size_t index, const Long& value)
{
	++index;

	while (index <= size)
	{
		sum[index] += value;
		index += (index & -index);
	}

	return;
}

inline Long getSum(size_t index)
{
	++index;
	Long total = 0;

	while (index > 0)
	{
		total += sum[index];
		index -= (index & -index);
	}

	return total;
}

inline Long getSum(size_t left, size_t right)
{
	Long sum = getSum(right);

	if (left <= 0)
		return sum;

	return sum - getSum(left - 1);
}

size_t n;
Long px1;
Long py1;
Long px2;
Long py2;
size_t i;
Long intersections = 0;
vector<Event> segments;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (i = 0; i < n; ++i)
	{
		cin >> px1 >> py1 >> px2 >> py2;

		++px1;
		++py1;
		++px2;
		++py2;

		if (px1 == px2)
		{
			if (py1 < py2)
				segments.push_back(Event(px1, py1, px2, py2, 0));
			else
				segments.push_back(Event(px2, py2, px1, py1, 0));
		}
		else if (px1 < px2)
		{
			segments.push_back(Event(px1, py1, px1, py1, -1));
			segments.push_back(Event(px2, py1, px2, py1, 1));

		}
		else
		{
			segments.push_back(Event(px2, py1, px2, py1, -1));
			segments.push_back(Event(px1, py1, px1, py1, 1));
		}

	}


	if (segments.size() > 1)
	{
		sort(segments.begin(), segments.end());
		

		for (i = 0; i < segments.size(); ++i)
		{
			if (segments[i].type == -1)
				addValue(segments[i].y1, 1);
			else if (segments[i].type == 0)
				intersections += getSum(segments[i].y1, segments[i].y2);
			else
				addValue(segments[i].y1, -1);
		}
	}

	cout << intersections << "\n";
	
	return 0;
}