#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
   
    unordered_map<string, int> mp;

pair<string,int>p1;
p1.first = "Paras";
p1.second = 76;


pair<string,int>p2;
p2.first = "Monu";
p2.second = 36;


pair<string,int>p3;
p3.first = "Kadela";
p3.second = 11;


mp.insert(p1);
mp.insert(p2);
mp.insert(p3);


// for(auto p : mp)
// cout<<p.first<<" "<<p.second<<endl;
//! Random order is observed while printing of elements.

mp["Ram"] = 23;

mp.erase("Paras");

for(auto pair : mp)
cout<<pair.first<<" "<<pair.second<<endl;


cout<<mp.size()<<endl;






    return 0;
}