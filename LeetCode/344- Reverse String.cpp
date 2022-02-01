//Approach 1:
string reverseString(string s) {
        int i = 0, j = s.size() - 1;
        while(i < j){
            swap(s[i++], s[j--]); 
        }
        
        return s;
    }

//Approach 2
void reverseString(vector<char>& s) {
        reverse(s.begin(), s.end());

    }
