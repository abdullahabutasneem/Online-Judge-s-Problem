class Solution {
public:
    bool isValid(string s) {
        stack<char>stk;
        int n=s.size();
        bool ok=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(' or s[i]=='{' or s[i]=='[')stk.push(s[i]);
            else if(s[i]==')' and !stk.empty() and stk.top()=='(' )stk.pop();
            else if(s[i]=='}' and !stk.empty() and stk.top()=='{')stk.pop();
            else if(s[i]==']' and !stk.empty() and stk.top()=='[')stk.pop();
            else{
                ok=1;break;
            }
        }
        if(ok or stk.size()>0)return false;
        else return true;
    }
};
