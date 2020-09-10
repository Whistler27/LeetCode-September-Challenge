class Solution {
public:
    string getHint(string secret, string guess) {
        int a=0,b=0;
        unordered_map<char,int> cnt;
        unordered_map<char,vector<int>> mp;
        for(int i=0;i<secret.size();i++){
            mp[secret[i]].push_back(i);
        }
        
        for(char c='0';c<='9';c++){
            cnt[c]=mp[c].size();
        }
        
        for(int i=0;i<secret.size();i++){
            if(guess[i]==secret[i]) a++,cnt[guess[i]]--;
        }
        
        for(int i=0;i<guess.size();i++){
            if(guess[i]==secret[i]) continue;
           
            if(cnt[guess[i]]>0) b++,cnt[guess[i]]--;
        }
        
        string ans;
        ans+=to_string(a);
        ans+='A';
        ans+=to_string(b);
        ans+='B';
        return ans;
        
    }
};