// class Solution
// {
// public:

//     //! Approach - 1 --> (WRONG APPROACH)
//     //* We used unordered maps to do so.
//     //! Wrong Approach --- Causes problem when our arr contains some negative values as our modulo operator will behave differently in such cases.
// class Solution {
// public:

//     bool canArrange(vector<int>& arr, int k) {
//         unordered_map<int, int> mp;

//         for (int i = 0; i < arr.size(); i++) {
//             int alpha = arr[i] % k;
//             mp[alpha]++;
//         }
//! checked for condition where arr[i] is already divisible by k on its own.

// if(mp[0] % 2!=0) return false;
// if(mp.find(0)!=mp.end()) mp.erase(0);

//! checking for other elements.

//         for (auto exe : mp)
//         {
//             int val = exe.first;
//             int freq = exe.second;

//          if (mp.find(k - val) == mp.end())
//                 return false;

//         }

//         return true;
//     }
// };

//! Approach - 2 --> Correct Approach.
//* We used unordered maps to do so.
//! Correct Approach --- Most important part is how it deals with negative values as well as zeros and the comparison of values along with their frequencies of occurrence in the unordered map.
//* Another important thing is since no of pairs should be  equal to n/2 that all the elements must be involved in making pairs therfore we dont need counter to check.

class Solution
{
public:
    bool canArrange(vector<int> &arr, int k)
    {
        unordered_map<int, int> mp;

        for (int i = 0; i < arr.size(); i++)
        {

            //! Most important step which takes care of even negative values too.

            int alpha = ((arr[i] % k) + k) % k;
            mp[alpha]++;
        }

        //! Another important step that takes care of zeros in map
        if (mp.find(0) != mp.end())
        {

            if (mp[0] % 2 != 0)
                return false;
            mp.erase(0);
        }

        //! Finally checking for presence of values along with necessary frequencies.

        for (auto exe : mp)
        {
            int val = exe.first;
            int freq = exe.second;

            if (mp.find(k - val) == mp.end())
                return false;
            if (mp[k - val] != freq)
                return false;
        }

        return true;
    }
};