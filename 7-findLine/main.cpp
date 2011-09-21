#include <iostream>
#include <limits>
#include <cmath>
#include <vector>
#include <map>
using namespace std;

inline bool equals(float a, float b)
{
	return fabs(a - b) < numeric_limits<float>::epsilon();
}

struct POINT
{
    float x;
	float y;
};

struct LINE
{
	float b;
	float s;
};

LINE findLine(const vector<POINT>& vp)
{
	vector<POINT>::const_iterator i;
	vector<POINT>::const_iterator j;
	int max = 0;
	LINE maxLine = {0.0f, 0.0f};
	for (i = vp.begin(); i != vp.end(); ++i)
	{
		map<float, int> count;
		for (j = i + 1; j != vp.end(); ++j)
		{
			float s = (j->y - i->y) / (j->x - i->x);
			if(count.find(s) == count.end())
			{
				count[s] = 1;
			}
			else
			{
				++count[s];
			}
		}
		map<float, int>::iterator it;
		for (it = count.begin(); it != count.end(); ++it)
		{
			if(it->second > max)
			{
				maxLine.s = it->first;
				maxLine.b = (i->y - i->x * maxLine.s);
				max = it->second;
			}
		}
	}
	return maxLine;
}

int main()
{
	POINT a[] = {{5,5},{4,4},{3,3},{2,2},{1,1},{1,2}};
	vector<POINT> vp(a, a + 6);

	LINE l = findLine(vp);

	cout << l.b << " " << l.s << endl;
	
	return 0;
}
