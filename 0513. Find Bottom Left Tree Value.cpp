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
    int res=0;
    int mostHeight=-1;

    void helper(TreeNode* root, int curDeep){
        if(!root) return ;
        if(curDeep>mostHeight){
            res=root->val;
            mostHeight=curDeep;
        }
        helper(root->left,curDeep+1);
        helper(root->right,curDeep+1);
    }

    int findBottomLeftValue(TreeNode* root) {
        helper(root,1);
        return res;
    }
};
