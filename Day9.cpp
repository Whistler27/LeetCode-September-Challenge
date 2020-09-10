class Solution {
public:
    int compareVersion(string version1, string version2) {
        
        vector<string> a,b;
        string cur="";
        for(int i=0;i<version1.size();i++){
            if(version1[i]!='.') cur+=version1[i];
            else{
                a.push_back(cur);
                cur="";
            }
        }
        
        if(cur.size()) a.push_back(cur);
        
        cur="";
        for(int i=0;i<version2.size();i++){
            if(version2[i]!='.') cur+=version2[i];
            else{
                b.push_back(cur);
                cur="";
            }
        }
        
        if(cur.size()) b.push_back(cur);
        
        for(int i=0;i<max(a.size(),b.size());i++){
            string s=i<a.size()?a[i]:"0";
            string t=i<b.size()?b[i]:"0";
            
            int si=stoi(s);
            int ti=stoi(t);
            
            if(si>ti) return 1;
            else if(si<ti) return -1;
            
        }
        
        return 0;
        
    }
};