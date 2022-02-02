//Approach 1

vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_map<int,int>mp;
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(int i=1;i<=n;i++){
            if(mp[i]==0)ans.push_back(i);
        }
        return ans;
    }

//Approach 2

vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            int x = abs(nums[i])-1;
            if(nums[x]>0)nums[x]=-nums[x];
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(nums[i]>0)ans.push_back(i+1);
        }
        return ans;
    }
