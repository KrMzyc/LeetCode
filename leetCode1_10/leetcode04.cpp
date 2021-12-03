class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(),m = nums2.size(),sum = n + m;
        if(sum % 2 == 0)
        {
            int left = getKthSmallest(nums1,0,nums2,0,sum / 2);
            int right = getKthSmallest(nums1,0,nums2,0,sum / 2 + 1);
            return (left + right) / 2.0;
        }else
            return getKthSmallest(nums1,0,nums2,0,sum / 2 + 1);
    }
    int getKthSmallest(vector<int> &nums1,int i,vector<int> &nums2,int j,int k)
    {
        if(nums1.size() - i > nums2.size() - j) return getKthSmallest(nums2,j,nums1,i,k);
        if(i == nums1.size()) return nums2[j + k - 1];
        if(k == 1) return min(nums1[i],nums2[j]);
        int si = min(i + k / 2,(int)nums1.size()),sj = j + k / 2;
        if(nums1[si - 1] > nums2[sj - 1])
            return getKthSmallest(nums1,i,nums2,j + k / 2,k - k / 2);
        else
            return getKthSmallest(nums1,si,nums2,j,k - (si - i));
    }
};