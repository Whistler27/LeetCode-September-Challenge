class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n=s.size();
        vector<string> req;
        string cur;
        for(int i=0;i<n;i++){
            if(s[i]!=' '){
                cur+=s[i];
            }
            else{
                req.push_back(cur);
                cur="";
            }
        }
        if(cur.size()>0) req.push_back(cur);
        map<string,char> mp;
        map<char,string> mp2;
        int m=pattern.size();
        if(req.size()!=pattern.size()) return 0;
        
        for(int i=0;i<m;i++){
            if(mp.find(req[i])!=mp.end()){
                if(mp[req[i]]!=pattern[i]) return 0;
                
            }
            else mp[req[i]]=pattern[i];
            if(mp2.find(pattern[i])!=mp2.end()){
                if(mp2[pattern[i]]!=req[i]) return 0;
            }    
            else mp2[pattern[i]]=req[i];
        }
        
        return 1;
    }
};