#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>

using namespace std;

int main()
{

//! To show difference between ordered and unordered set.

set <int> s;

s.insert(2);
s.insert(5);
s.insert(1);
s.insert(0);
s.insert(78);

// for(int ele : s)
// cout<<ele<<" ";
//* output --> will be sorted --> 0, 1, 2, 5, 78.



unordered_set <int> us;

us.insert(2);
us.insert(5);
us.insert(1);
us.insert(0);
us.insert(78);

// for(int ele : us)
// cout<<ele<<" ";
//* output --> will be in random order --> 2,5,0,78,1 .


map<int,int>mp;

mp[1]=30;
mp[2]=20;
mp[3]=10;

// for(auto x : mp)
// cout<<x.first<<" "<<x.second<<endl;
//! Arranged in ascending with respect to key from the key value pair. order is --> 1,30 -> 2,20 -> 3,10
//* Values are printer in accordance with the value of thier key values always 


map<string,int>ts;

ts["Raghav"] = 76;
ts["Harsh"]  = 10;
ts["Sanket"] = 52;

for(auto ele : ts)
cout<<ele.first<<" "<<ele.second<<endl;
//! Since keys here are Strings therfore they are sorted Lexicographically.


return 0;
}