class Solution
{
public:
    /*
    ! Approach - 1 (Good but wont work if the given nums array have negative values)
    * TC = o(n + n*log(n)) == O(n*log(n))
    * SC = o(1)
    */
    bool binarySearch(vector<int> &nums, int t, int at)
    {
        int i = 0;
        int j = at;

        while (i <= j)
        {
            int mid = i + ((j - i) / 2);

            if (nums[mid] == t)
                return true;

            else if (nums[mid] > t)
                j = mid - 1;
            else if (nums[mid] < t)
                i = mid + 1;
        }
        return false;
    }

    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        int answer = 0;

        //! TC = O(n)

        for (int i = 1; i < n; i++)
        {
            nums[i] += nums[i - 1];
        }

        //! TC = O(n*log(n))

        for (int i = 0; i < n; i++)
        {
            if (k > nums[i])
                continue;
            else if (k == nums[i])
                answer++;
            else if (k < nums[i])
            {
                if (binarySearch(nums, nums[i] - k, i - 1))
                    answer++;
            }
        }
        return answer;
    }
};

/*
! Approach - 2 (Good but still wont work if the given nums array have negative values)
* TC = o(n + n) == O(n)
* SC = o(n)
*/

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {

        int n = nums.size();
        int answer = 0;
        unordered_set<int> s;

        //! TC = O(n)

        for (int i = 1; i < n; i++)
        {
            nums[i] += nums[i - 1];
        }

        //! TC = O(n)

        for (int i = 0; i < n; i++)
        {
            if (k > nums[i])
            {
                s.insert(nums[i]);
            }

            else if (k == nums[i])
            {
                answer++;
                s.insert(nums[i]);
            }

            else if (k < nums[i])
            {
                if (s.find(nums[i] - k) != s.end())
                    answer++;
            }
        }
        return answer;
    }
};

/*
! Approach - 3 (Good but still wont work if the given nums array have negative values)
* TC = o(n + n) == O(n)
* SC = o(n)
*/

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {

        int n = nums.size();
        int answer = 0;
        unordered_set<int> s;

        //! TC = O(n)

        for (int i = 1; i < n; i++)
        {
            nums[i] += nums[i - 1];
        }

        //! TC = O(n)

        for (int i = 0; i < n; i++)
        {
            //! we made some changes here in the conditions other than "k == nums[i]" and made them mandatory for each iteration.
            if (k == nums[i])
                answer++;
            int rem = nums[i] - k;
            if (s.find(rem) != s.end())
                answer++;
            s.insert(nums[i]);
        }
        return answer;
    }
};

/*
! Approach - 4 (Correct Method --- Shows perfect use of maps over sets)
* TC = o(n + n) == O(n)
* SC = o(n)
*/

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {

        int n = nums.size();
        int answer = 0;
        //! Following map keeps record of elements along with their Frequencies which our sets fails to do
        unordered_map<int, int> mp;

        //! TC = O(n)

        for (int i = 1; i < n; i++)
        {
            nums[i] += nums[i - 1];
        }

        //! TC = O(n)

        for (int i = 0; i < n; i++)
        {
            if (k == nums[i])
                answer++;

            int rem = nums[i] - k;

            if (mp.find(rem) != mp.end())
                answer += mp[rem];
                
            mp[nums[i]]++;
        }
        return answer;
    }
};
