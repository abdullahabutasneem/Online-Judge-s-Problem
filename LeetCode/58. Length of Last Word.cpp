class Solution {
public:
    int lengthOfLastWord(string s) {
        vector<string>str;
        string temp="";
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                if(temp!=""){
                    str.push_back(temp);
                    temp="";
                }
                continue;
            }
            else  temp+=s[i];
        }
        if(temp!="")str.push_back(temp);
        int n = str.size();
        return str[n-1].size();
    }
};
