class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        int n = arr.size();

        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[arr[i]]++;
        }
        unordered_set<int> s;
        for (auto q : mp)
        {
            int fre = q.second;
            if (s.find(fre) != s.end())
            {
                return false;
            }
            else
            {
                s.insert(fre);
            }
        }
        return true;
    }
};