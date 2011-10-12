#include <iostream>
#include <vector>
#include <map>
#include <assert.h>
using namespace std;



struct Pair
{
     int x;
     int y;
};

typedef vector< vector<char> > GRID;
typedef vector< vector<bool> > VVB;
typedef vector< vector< vector< Pair > > > VVV;



struct Key
{
     int n;
     VVB status;
     bool operator < ( const Key & _Key) const
	  {
	       return status < _Key.status || n < _Key.n;
	  }
};


typedef map< Key , int> MAP;

void preProcess(const GRID & g, int i, int j, VVV& ava)
{
     if(g[i][j] != '.')
	  return;
     int x, y;
     //down check
     x = i, y = j;
     while(x < g.size() && g[x][y] != '#')
     {
	  Pair p;
	  p.x = x;
	  p.y = y;
	  ava[i][j].push_back(p);	  
	  --x;
     }
     
     //left check
     x = i, y = j;
     while(y < g[0].size() && g[x][y] != '#')
     {
	  Pair p;
	  p.x = x;
	  p.y = y;
	  ava[i][j].push_back(p);	  
	  --y;
     }

     //up left check
     x = i, y = j;
     while(x >= 0 && y >= 0 && x < g.size() && y < g[0].size() && g[x][y] != '#')
     {
	  Pair p;
	  p.x = x;
	  p.y = y;
	  ava[i][j].push_back(p);	  
	  --x, --y;
     }
     
     //up right check
     x = i, y = j;
     while(x >= 0 && y >= 0 && x < g.size() && y < g[0].size() && g[x][y] != '#')
     {
	  Pair p;
	  p.x = x;
	  p.y = y;
	  ava[i][j].push_back(p);
	  --x, ++y;
     }
     
     //down check
     x = i, y = j;
     while(x < g.size() && g[x][y] != '#')
     {
	  Pair p;
	  p.x = x;
	  p.y = y;
	  ava[i][j].push_back(p);	  
	  ++x;
     }
     
     //right check
     x = i, y = j;
     while(y < g[0].size() && g[x][y] != '#')
     {
	  Pair p;
	  p.x = x;
	  p.y = y;
	  ava[i][j].push_back(p);	  
	  ++y;
     }

     //down left check
     x = i, y = j;
     while(x >= 0 && y >= 0 && x < g.size() && y < g[0].size() && g[x][y] != '#')
     {
	  Pair p;
	  p.x = x;
	  p.y = y;
	  ava[i][j].push_back(p);	  
	  ++x, --y;
     }
     
     //down right check
     x = i, y = j;
     while(x >= 0 && y >= 0 && x < g.size() && y < g[0].size() && g[x][y] != '#')
     {
	  Pair p;
	  p.x = x;
	  p.y = y;
	  ava[i][j].push_back(p);
	  ++x, ++y;
     }
}

bool validate(GRID g, int x, int y, const VVV& ava)
{
     if (g[x][y] != '.')
	  return false;
     for (int i = 0; i < ava[x][y].size(); ++i)
     {
	  Pair p;
	  p = ava[x][y][i];
	  if (g[p.x][p.y] != '.' )
	       return false;
     }
     return true;
}

void resetPos(const GRID & g, int i, int j, VVB& pos)
{
     int x, y;
     //down check
     x = i, y = j;
     while(x < g.size() && g[x][y] != '#')
     {
	  pos[x][y]=false;	  
	  --x;
     }
     
     //left check
     x = i, y = j;
     while(y < g[0].size() && g[x][y] != '#')
     {
	  pos[x][y]=false;	  	  
	  --y;
     }

     //up left check
     x = i, y = j;
     while(x >= 0 && y >= 0 && x < g.size() && y < g[0].size() && g[x][y] != '#')
     {
	  pos[x][y]=false;	  	  
	  --x, --y;
     }
     
     //up right check
     x = i, y = j;
     while(x >= 0 && y >= 0 && x < g.size() && y < g[0].size() && g[x][y] != '#')
     {

	  pos[x][y]=false;	  	  
	  --x, ++y;
     }
     
     //down check
     x = i, y = j;
     while(x < g.size() && g[x][y] != '#')
     {

	  pos[x][y]=false;	  
	  ++x;
     }
     
     //right check
     x = i, y = j;
     while(y < g[0].size() && g[x][y] != '#')
     {

	  pos[x][y]=false;	  	  
	  ++y;
     }

     //down left check
     x = i, y = j;
     while(x >= 0 && y >= 0 && x < g.size() && y < g[0].size() && g[x][y] != '#')
     {

	  pos[x][y]=false;	  	  
	  ++x, --y;
     }
     
     //down right check
     x = i, y = j;
     while(x >= 0 && y >= 0 && x < g.size() && y < g[0].size() && g[x][y] != '#')
     {

	  pos[x][y]=false;	  
	  ++x, ++y;
     }     
}

int countQueen(GRID g, int n, int x, int y, const VVV& ava, VVB pos, MAP& hash)
{
     if (n == 0)
	  return 1;
     int count = 0;     
     if (g[x][y] != '.')
     {
	  y ++;
	  if (y == g[0].size())
	  {
	       y = 0;
	       x ++;
	  }
	  if(x == g.size())
	       return count;	  
	  count += countQueen(g, n, x, y, ava, pos, hash);
	  count %= 1000000007;
	  return count;
     }

     Key key;
     key.status = pos;
     key.n = n;
     MAP::iterator iter = hash.find(key);
     if(iter != hash.end())
     {
	  assert(key.n == iter->first.n);
	  return iter->second;
     }
     
     if(pos[x][y])
     {
	  if(validate(g, x, y, ava))
	  {
	       GRID cp(g);
	       VVB cpb(pos);	       
	       cp[x][y] = 'q';
	       resetPos(g, x, y, cpb);
	       int r = countQueen(cp, n - 1, x, y, ava, cpb, hash);
	       	       
	       count += r; //countQueen(cp, n - 1, x, y, ava, cpb, hash);
	       count %= 1000000007;

	  }
     }
     pos[x][y] = false;
     bool record = (g[x][y] == '.');

     y ++;
     if (y == g[0].size())
     {
	  y = 0;
	  x ++;
     }
     if(x == g.size())
	  return count;
     count += countQueen(g, n, x, y, ava, pos, hash);
     count %= 1000000007;
     if (record)
	  hash[key] = count;
     
     return count;
}
/*
VVB trait(pos);
     
for (int i = startx; i < g.size(); ++i)
{
     int j;
     if (i == startx)
	  j = starty;
     else
	  j = 0;
     for (; j < g[0].size(); ++j )
     {
	  if(!pos[i][j])
	       continue;
	  if (validate(g, i, j, ava))
	  {
	       GRID cp(g);
	       VVB cpb(pos);
	       cp[i][j] = 'q';
	       resetPos(g, i, j, cpb);
		    
	       Key key;
	       key.status = cpb;
	       key.n = n - 1;
	       MAP::iterator iter = hash.find(key);
	       if(iter!= hash.end())
	       {
		    count += iter->second;
	       }
	       else
	       {
		    count += countQueen(cp, n - 1, i, j, ava, cpb, hash);

	       }
	  }
	  else
	  {
	       trait[i][j] = false;		    
	       Key key;
	       key.status = trait;
	       key.n = n;
	       int r = countQueen(g, n, i, j, ava, pos, hash);
	       hash[key] = r;
	       return r;
	  }
     }
}
return count;
}
*/


int getSolution(int n, int m)
{
     GRID g;
     VVV ava;
     VVB pos;
     MAP hash;
     g.resize(n);
     ava.resize(n);
     pos.resize(n);
     for (int i = 0; i < n; ++i)
     {
	  ava[i].resize(m);
	  g[i].resize(m);
	  pos[i].resize(m);
     }

     int dots = 0;
     int count = 0;
     for (int i = 0; i < n; ++i)
	  for (int j = 0; j < m; ++j)
	  {
	       char c;
	       cin >> g[i][j];
	       if (g[i][j] == '.')
		    dots++;
	       pos[i][j] = (g[i][j] == '.');
	  }
     for (int i = 0; i < n; ++i)
	  for (int j = 0; j < m; ++j)
	       preProcess(g, i, j,ava);
     for (int i = 1; i <= dots; ++i)
     {
	  int r = countQueen(g, i, 0, 0, ava, pos, hash);
	  if (r == 0)
	       break;
	  count += r;
	  count %= 1000000007;
     }
     return count;
}


int main()
{
     int t;
     cin >> t;
     while(t--)
     {
	  int n;
	  int m;
	  cin >> n >> m;
	  cout << getSolution(n, m) << endl;
     }
}
