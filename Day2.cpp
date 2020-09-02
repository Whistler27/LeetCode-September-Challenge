typedef long long int ll;
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n=nums.size();
        if(n<=1 || k<0 || t<0) return 0;
        
        vector<pair<ll,ll>> v;
        for(int i=0;i<n;i++){
            v.push_back({nums[i],i});
        }
        
        sort(v.begin(),v.end());
        int i=0,j=1;
        while(j<n){
            if(v[j].second==v[i].second){
                j++;
                continue;
            }
            if(v[j].first-v[i].first>t){
                i++;
            }
            else if(i==j || abs(v[j].second-v[i].second)>k){
                j++;
            }
            else return 1;
                
        }
        return 0;
        
    }
};