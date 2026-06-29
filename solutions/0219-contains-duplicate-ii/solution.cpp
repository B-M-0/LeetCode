#include <algorithm>
#include <unordered_set>
class Solution {
public:
    int min(int a,int b)
    {
        return a < b? a : b;
    }
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> s;
        for(int i = 0; i < min (k+1,nums.size()) ; i++)
        {
            if (s.count(nums[i]) == 0)
                s.insert(nums[i]);
            else
                return true;
        }
        for (int i =k+1; i < nums.size();i++ )
        {
            s.erase(nums[i-(k+1)]);
            if(s.find(nums[i]) == 0)
                s.insert(nums[i]);
            else
                return true;
        }
        return false;
    }
};
