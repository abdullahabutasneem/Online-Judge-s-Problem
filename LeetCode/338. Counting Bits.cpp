//Approach 1 (built in popcount)

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0; i<=n;i++){
            int x = __builtin_popcount(i);
            ans.push_back(x);
        }
        return ans;
    }
};

//Approach 2 ( Brian Kernighan’s Algorithm)

class Solution {
public:
    int count(int n){
        int cnt=0;
        while(n){
            n = n & (n-1);
            n>>1;
            cnt++;
        }
        return cnt;
    }
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0; i<=n;i++){
            int x = count(i);
            ans.push_back(x);
        }
        return ans;
    }
};
