class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
//for(int i=0;i<4;i++) if(A[i]>=6) return "";
        
        string ans="";
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                for(int k=0;k<4;k++){
                    if(i==j || j==k || k==i) continue;
                    int last=6-i-j-k;
                    string hh=to_string(A[i])+to_string(A[j]);
                    string mm=to_string(A[k])+to_string(A[last]);
                    string time=hh+":"+mm;
                    if(hh<"24" && mm<="59"){
                        if(time>=ans) ans=time;
                    }
                    
                }
            }
        }
        
        return ans;
        
    }
};