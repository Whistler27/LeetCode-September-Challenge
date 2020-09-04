class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        string str=s.substr(1)+s.substr(0,n-1);
        int val=str.find(s);
        
        if(val>=0) return 1;
        return 0;
        
    }
};