class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==1)return strs[0];
        sort(strs.begin(), strs.end());
        if(strs[0]=="")return "";
        int n = strs.size();
        int m = strs[0].size();
        string ans="";
        
        for(int i=0;i<m;i++){
            if(strs[0][i]!=strs[n-1][i])break;
            ans+=strs[0][i];
        }
        if(ans.size()==0)return "";
        else return ans;
    }
};
