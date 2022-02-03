class Solution {
public:
    
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int highest = 0, ans=INT_MIN,mx_point = INT_MIN;
        for(int i=0;i<n;i++){
            highest += nums[i];
            if(highest<nums[i]){
                highest = nums[i];
            }
            if(mx_point<highest){
                mx_point = highest;
            }
        }
        ans = max(ans, mx_point);
        return ans;
    }
};
