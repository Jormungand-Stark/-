/**
 - Definition for a binary tree node.
 - struct TreeNode {
 -     int val;
 -     TreeNode *left;
 -     TreeNode *right;
 -     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 - };
 */
class Solution { // 后序遍历
public:
    int maxDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

class Solution { // 层序遍历
public:
    int maxDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        queue<TreeNode*> que;
        que.push(root);
        int res = 0;
        while(!que.empty()){
            queue<TreeNode*> tmp;
            while(!que.empty()){
                TreeNode* node = que.front();
                que.pop();
                if(node->left) tmp.push(node->left);
                if(node->right) tmp.push(node->right);
            }
            que = tmp;
            res++;
        }
        return res;
    }
};
