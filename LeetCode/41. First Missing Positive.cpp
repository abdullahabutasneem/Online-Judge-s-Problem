class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bool ok=0;
        int n=nums.size(),ind=n+1;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                ok=1;
            }
            else if(nums[i]<=0 || nums[i]>n){
                nums[i]=1;
            }
        }

        if(!ok)return 1;
        for(int i=0;i<n;i++){
            int in = abs(nums[i])-1;
            if(nums[in]>0){
                nums[in] = -nums[in];
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                ind = i+1;
                break;
            }
        }
        
        return ind;
    }
};
