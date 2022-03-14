class Solution {
public:
    vector<int>computeLCP(string pat){
        int n = pat.size();
        vector<int>lcp(n);
        int len=0, i=1;
        lcp[0]=0;
        while(i<n){
            if(pat[len]==pat[i]){
                len++;
                lcp[i]=len;
                i++;
            }
            else{
                if(len!=0){
                    len = lcp[len-1];
                }
                else{
                    lcp[i]=0;
                    i++;
                }
            }
        }
        return lcp;
    }
    
    int kmp(string text, string pat){
        vector<int>lcp = computeLCP(pat);
        int n=text.size(), m=pat.size();
        int i=0,j=0;
        while(i<n){
            if(text[i]==pat[j]){
                i++;j++;
            }
            if(j==m){
                return i-m;
            }
            else if(i<n and text[i]!=pat[j]){
                if(j!=0){
                    j = lcp[j-1];
                }
                else i++;
            }
        }
        return -1;
    }
    
    int strStr(string text, string pattern) {
        if((text=="" and pattern=="") or pattern=="")return 0;
        if(text=="")return -1;
        int ans = kmp(text, pattern);
        return ans;
    }
};
