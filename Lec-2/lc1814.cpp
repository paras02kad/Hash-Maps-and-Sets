class Solution
{
public:
    int rev(int num)
    {
        int data = 0;

        while (num > 0)
        {
            data = (data * 10) + (num % 10);
            num /= 10;
        }
        return data;
    }

    int countNicePairs(vector<int> &nums)
    {
        unordered_map<int, int> mp;

        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            nums[i] = nums[i] - rev(nums[i]);
        }

        int counter = 0;

        for (int i = 0; i < n; i++)
        {

            if (mp.find(nums[i]) != mp.end())
            {
                counter = counter % 1000000007;
                counter += mp[nums[i]];
            }
            mp[nums[i]]++;
        }

        return counter % 1000000007;
    }
};