#include <vector>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;

string encode(const vector<string>& sv)
{
	stringstream ss;
	ss << setw(4) << setfill('0') << sv.size();
	for (int i = 0; i < sv.size(); ++i)
	{
		ss<<setw(4)<<setfill('0')<<sv[i].size();
		ss<<sv[i];
	}
	return ss.str();
}
vector<string> decode(string s)
{
	int size = atoi(s.substr(0,4).c_str());
	int pos = 4;
	vector<string>  vs;
	for (int i = 0; i < size; ++i)
	{	
		int subsize = atoi(s.substr(pos,4).c_str());
		pos+=4;
		vs.push_back(s.substr(pos,subsize));
		pos+=subsize;
	}
	return vs;
}
int main()
{
	vector<string> sv;
	sv.push_back("fasdfasdf");
	sv.push_back("ghahfsdafes");
	cout << encode(sv) << endl;
	vector<string> decoded = decode(encode(sv));
	for (int i = 0 ; i < decoded.size(); ++i)
		cout << decoded[i] << endl;
	return 0;
}
