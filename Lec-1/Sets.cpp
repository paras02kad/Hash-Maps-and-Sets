#include <iostream> 
#include <unordered_set>

using namespace std;


//! Basic STL functions of unordered_sets.

int main()
{

unordered_set<int>s;

s.insert(1);
s.insert(2);
s.insert(3);
s.insert(4);
s.insert(5);
s.insert(5);

//! we use forEach loop to access elements of set.
//* will only store unique elements.

for(int ele : s)
cout<<ele<<" ";

cout<<endl;

s.erase(2);
cout<<s.size()<<endl;//! 4

//! to find an element in the given set.

//* If target exists
if(s.find(2)!=s.end())
{
cout<<"Exists"<<endl;
}
else cout<<"Not Present"<<endl;




return 0;
}