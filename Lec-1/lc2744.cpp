class Solution
{
public:
    int maximumNumberOfStringPairs(vector<string> &words)
    {
        int s = words.size();
        int count = 0;
        unordered_set<string> q;

        for (int i = 0; i < s; i++)
        {
            q.insert(words[i]);
        }

        for (int i = 0; i < s; i++)
        {
            string l = words[i];

            reverse(l.begin(), l.end());

            if (words[i] == l)
            {
                continue;
            }

            else

                if (q.find(l) != q.end())
            {
                q.erase(words[i]);
                count++;
            }
        }
        return count;
    }
};