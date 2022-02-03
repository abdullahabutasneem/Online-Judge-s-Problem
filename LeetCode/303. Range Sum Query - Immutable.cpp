class NumArray {
    public:
        vector<int>prefix;
        NumArray(vector<int>& nums) {
            prefix.push_back(0);
            for(int num:nums){
                prefix.push_back(prefix.back()+num);
            }
        }
        
        int sumRange(int i, int j) {
            return prefix[j+1]-prefix[i];
        }
        
    };
