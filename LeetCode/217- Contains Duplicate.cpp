//Using Set => 30% faster time complexity (44ms)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>s;
        for(int i = 0; i < nums.size(); i++) s.insert(nums[i]);
        if(nums.size() != s.size()) return true;
        return false;   
    }
};


//Using Unordered map => 45% faster time complexity (36ms)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>m;
        for(int i = 0; i < nums.size(); i++) m[nums[i]]++;
        for(auto i : m) if(i.second >= 2) return true;
        return false;
    }
};


//Using Unordered map => 70% faster time complexity (28ms)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>m;
        for(int i = 0; i < nums.size(); i++){
            if(m.find(nums[i]) == m.end()) m[nums[i]]++;
            else return true;
        }
        return false;
  }
};


//After Sorting Array => 99% faster time complexity (12ms)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-1; i++) if(nums[i] == nums[i+1]) return true;
        return false;
    }
};
