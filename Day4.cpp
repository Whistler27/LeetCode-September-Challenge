class Solution {
public:
    vector<int> partitionLabels(string S) {
        int n=S.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            char c=S[i];
            int p=-1;
            unordered_map<char,int> mp;
            for(int j=n-1;j>=i;j--){
                if(S[j]==S[i]){
                    p=j;
                    break;
                }
                if(mp.find(S[j])!=mp.end()) mp[S[j]]=max(mp[S[j]],j);
                else mp[S[j]]=j;
            }
            int k=p;
            for(int j=i;j<=p;j++){
                if(mp.find(S[j])!=mp.end()) p=max(p,mp[S[j]]),k=p;
            }
            //cout << k <<endl;
            cout << i << " " << k << endl;
            ans.push_back(k-i+1);
            i=k;
            
        }
        return ans;
    }
};