class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string output = "";
        int n = nums.size();
        for(int i = 0; i < n ;i++)
        {

            if(nums[i][i] == '1')
                output += '0';
            else
                output += '1';

        }
        return output;
    }
};
