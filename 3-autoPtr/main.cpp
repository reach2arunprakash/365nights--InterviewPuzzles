//implement a auto_ptr class
//like the one in stl!
#include <iostream>
#include <vector>
#include <memory> 
#include <map>
using std::cout;
using std::endl;
using std::vector;
using std::map;
using std::string;

template <class T>
class auto_ptr
{
private:
     T* pointer;

public:
     explicit auto_ptr(T* p = 0):pointer(p)
	  {
	  }

     auto_ptr(auto_ptr& ptr)
	  {
	       pointer = ptr.release();
	  }
     template <class Y>
     auto_ptr(auto_ptr<Y>& ptr)
	  {
	       pointer = ptr.release();
	  }

     auto_ptr& operator=(auto_ptr& ptr)
	  {
	       pointer = ptr.release();
	  }

     template <class Y>
     auto_ptr& operator=(auto_ptr<Y> ptr)
	  {
	       pointer = ptr.release();
	  }

     T& operator*() const
	  {
	       return *pointer;
	  }

     T* operator->() const
	  {
	       return pointer;
	  }

     T* get() const
	  {
	       return pointer;
	  }

     T* release()
	  {
	       T* result = pointer;
	       pointer = 0;
	       return result;
	  }

     void reset(T* p = 0)
	  {
	       if(pointer)
		    delete pointer;
	       pointer = p;
	  }
     
     ~auto_ptr()
	  {
	       if(!pointer)
		    delete pointer;
	  }
};


typedef int ContainedType;


//test case
int main() {
 
     auto_ptr<vector<ContainedType> > open_vec(new vector<ContainedType>);
     
     open_vec->push_back(5);
     open_vec->push_back(3);
     open_vec->push_back(1);
 
     // Transfers control, but now the vector cannot be changed:
     auto_ptr<const vector<ContainedType> > closed_vec(open_vec); 
 
     // closed_vec->push_back(8); // Can no longer modify 
 
     // Safe during the lifetime of the autoptr:
     map<string, const ContainedType *> nmap;
 
     nmap["First"]  = & closed_vec->at(0);
     nmap["Second"] = & closed_vec->at(1);
     nmap["Third"]  = & closed_vec->at(2);
 
     for (map<string, const ContainedType *>::iterator it = nmap.begin(); it != nmap.end(); ++it) {
	  cout << it->first << " -> " << *(it->second) << std::endl;
     }
 
     return 0;
}
 
