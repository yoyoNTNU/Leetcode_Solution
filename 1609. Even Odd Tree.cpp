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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int level=0;
        while(!q.empty()){
            int last_max=INT_MAX;
            int last_min=INT_MIN;
            int size=q.size();

            while(size--){

                TreeNode* f=q.front();q.pop();

                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);

                if(level%2){
                    if(f->val%2 || f->val >= last_max)return false;
                    last_max=f->val;
                }
                else{
                    if(!(f->val%2) || f->val <= last_min)return false;
                    last_min=f->val;
                }
            }
            level++;
        }
        return true;
    }
};
