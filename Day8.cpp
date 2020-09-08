/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    vector<string> str;
    
    int bin(string s){
        int n=s.size();
        int ans=0;
        for(int i=n-1;i>=0;i--){
            int cur=s[i]-'0';
            ans+=cur*(1<<(n-1-i));
        }
        return ans;
    }
    
    void sum(TreeNode* root,string s){
        if(root==nullptr) return;
    
        if(root->left==NULL && root->right==NULL){
            char c=root->val+'0';
            s+=c;
            
            str.push_back(s);
        }    
        char c=root->val+'0';
        s+=c;
        sum(root->left,s);
        sum(root->right,s);
        
    }
    
    int sumRootToLeaf(TreeNode* root) {
        if(root==nullptr) return 0;
        str.clear();
        int ans=0;
        string s="";
        sum(root,s);
        for(int i=0;i<str.size();i++){
           ans+=bin(str[i]);
        }
        return ans;
        
    }
};