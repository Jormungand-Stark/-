/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    int res, k;
    void midsearch(TreeNode* root){
        if(root==nullptr) return;
        midsearch(root->right);
        if(k==0) return;
        if(--k==0) res = root->val;
        midsearch(root->left);
    }
public:
    int kthLargest(TreeNode* root, int k) {
        this->k = k;
        midsearch(root);
        return res;
    }
};
