class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        pair<int ,int> res(INT_MAX,INT_MIN);
        sort(nums.begin(), nums.end());
        for (int i=0; i<nums.size(); i++)
        {
            for (int j=i+1, k=nums.size()-1; j<k; j++)
            {
                while(k-1>j && nums[i]+nums[j]+nums[k-1]>=target) k--;
                int sum=nums[i]+nums[j]+nums[k];
                res=min(res,make_pair(abs(sum-target),sum));
                if (k-1>j)
                {
                    int sum=nums[i]+nums[j]+nums[k-1];
                    res=min(res,make_pair(abs(target-sum),sum));
                }
            }
        }

        return res.second;
    }
};