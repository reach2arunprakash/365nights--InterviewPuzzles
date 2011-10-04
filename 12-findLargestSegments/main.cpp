#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct Segment
{
    int start;
	int end;
};

bool compare(Segment s1, Segment s2)
{
	return s1.end < s2.end;
}

int findMax(vector<Segment>& v)
{
	sort(v.begin(), v.end(), compare);
	int lastStart = -1;
	int count = 0;
	vector<Segment>::iterator i;
	for (i = v.begin(); i != v.end(); ++i)
		if (i->start >= lastStart)
		{
			++lastStart;
			lastStart = i->end;
			++count;
		}
	return count;
}

int main(int argc, char *argv[])
{
    vector<Segment> v;
	Segment s;
	s.start = 10;
	s.end = 12;
	v.push_back(s);	
	s.start = 5;
	s.end = 7;
	v.push_back(s);		
	s.start = 6;
	s.end = 11;
	v.push_back(s);		
	s.start = 15;
	s.end = 19;
	v.push_back(s);
	cout << findMax(v) << endl;
	
    return 0;
}

