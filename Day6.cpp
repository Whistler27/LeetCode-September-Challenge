class Solution {
public:
    
    int fun(vector<vector<int>>& A,vector<vector<int>>& B){
        int n=A.size();
        int ans=0;
        for(int x=0;x<n;x++){
            for(int y=0;y<n;y++){
                int cur=0;
                for(int i=y;i<n;i++){
                    for(int j=x;j<n;j++){
                        if(A[i][j]==1 && B[i-y][j-x]==1) cur++;
                    }
                }
                ans=max(ans,cur);
            }
        }
        return ans;
    }
    
    
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n=A.size();
        if(n==0) return 0;
       
        return max(fun(A,B),fun(B,A)); 
        
    }
};