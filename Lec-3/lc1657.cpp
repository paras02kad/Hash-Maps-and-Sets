
class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        if (word1.length() != word2.length())
            return false;

        unordered_map<char,int> mp1,mp2;

        for (int i = 0; i < word1.length(); i++)
        {
            mp1[word1[i]]++;
            mp2[word2[i]]++;
        }

        for (auto xp : mp1)
        {
            char ch = xp.first;
            if (mp2.find(ch) == mp2.end())
                return false;
        }

        unordered_map<int, int> um1, um2;

        for (auto x : mp1)
        {
            int freq = x.second;
            um1[freq]++;
        }

        for (auto x : mp2)
        {
            int freq = x.second;
            um2[freq]++;
        }

        for (auto exe : um1)
        {
            int data = exe.first;
            int val = exe.second;

            if (um2.find(data) == um2.end())
                return false;
            else if (um2[data] != val)
                return false;
        }
        return true;
    }
};