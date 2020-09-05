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
    vector<int> t1;
    void allele(TreeNode* root){
        vector<int> ans;
        if(root==NULL) return;
        t1.push_back(root->val);
        allele(root->left);
        allele(root->right);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        t1.clear();
        allele(root1);
        vector<int> ans=t1;
        t1.clear();
        allele(root2);
        for(int i=0;i<t1.size();i++) ans.push_back(t1[i]);
        sort(ans.begin(),ans.end());
        return ans;
    }
};