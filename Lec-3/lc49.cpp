class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {

        vector<vector<string>> ans;
        //* We have declared an unordered_map with index value as string that will be our sorted string which will be the sorted output of other anagrams of same string 
        //! the value to the above key is vector of string which conatians all the possible anagrams of it.
        
        unordered_map<string, vector<string>> mp;

        //! Checking for string by sorting and then pushing them in map.

        for (string str : strs)
        {
            string lexo = str;
            sort(lexo.begin(), lexo.end());

            if (mp.find(lexo) == mp.end())
            {

                vector<string> v;
                v.push_back(str);
                mp[lexo] = v;
            }
            else
            {
                mp[lexo].push_back(str);
            }
        }
        for (auto s : mp)
        {
            vector<string> v = s.second;
            ans.push_back(v);
        }
        return ans;
    }
};