class Solution
{
public:
    vector<int> findEvenNumbers(vector<int> &arr)
    {
        vector<int> ans;
        unordered_map<int, int> mp;

        for (int ele : arr)
        {
            mp[ele]++;
        }

        for (int i = 100; i <= 999; i += 2)
        {
            int num = i;

            int x = num % 10;
            num = num / 10;

            int y = num % 10;
            num = num / 10;

            int z = num;

            if (mp.find(x) != mp.end())
            {
                mp[x]--;
                if (mp[x] == 0)
                {
                    mp.erase(x);
                }

                if (mp.find(y) != mp.end())
                {
                    mp[y]--;
                    if (mp[y] == 0)
                    {
                        mp.erase(y);
                    }

                    if (mp.find(z) != mp.end())
                    {
                        ans.push_back(i);
                    }
                    mp[y]++;
                }
                mp[x]++;
            }
        }
        return ans;
    }
};
