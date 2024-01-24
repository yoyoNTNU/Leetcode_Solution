//bit operation
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
    Solution(){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }

    int res=0;

    void countNum(TreeNode* root,int& record){
        if(!root){return;}
        int t=(1<<root->val);
        record^=t;
        if(!root->left && !root->right){
            res+=__builtin_popcount(record)<=1;
            record^=t;
            return;
        }
        countNum(root->left,record);
        countNum(root->right,record);
        record^=t;
        return;
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        int record=0;
        countNum(root,record);
        return res;
    }
};


//map

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

    void countNum(TreeNode* root,unordered_map<int,int>& mp){
        if(!root){return;}
        mp[root->val]++;
        if(!root->left && !root->right){
            bool hasOdd=false;
            for(auto it:mp){
                if(it.second%2==1){
                    if(hasOdd){
                        mp[root->val]--;
                        return;
                    }
                    hasOdd=true;
                }
            }
            res++;
            mp[root->val]--;
            return;
        }
        countNum(root->left,mp);
        countNum(root->right,mp);
        mp[root->val]--;
        return;
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int,int> mp;
        countNum(root,mp);
        return res;
    }
};
