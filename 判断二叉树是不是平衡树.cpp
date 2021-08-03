/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution { // 从下到上后序遍历+剪枝
    int fun(TreeNode* cur){
        if(!cur) return 0;
        int left = fun(cur->left);
        if(left==-1) return -1; // 剪枝
        int right = fun(cur->right);
        if(right==-1) return -1; // 剪枝
        return abs(left-right) < 2 ? max(left, right) + 1 : -1;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;;
        return fun(root)!=-1;
    }
};
/*
fun 函数实现后序遍历+剪枝：
返回值：
- 当 cur 的左 / 右子树的深度差 ≤1 时：表明 当前子树仍为平衡树，返回当前子树的深度，即 左 / 右子树的深度最大值 +1（ max(left, right) + 1 ）， ；
- 当 左 / 右子树的深度差 >1 时 ：则返回 -1 （也可以是其他负值，主要用来标明 此子树不是平衡树 ，方便后续剪枝 ）。
终止条件：
- 当 cur 为空：说明越过叶节点，因此返回高度 0 ；
- 当左（右）子树深度为 −1 ：代表此树的 左（右）子树 不是平衡树，可行性剪枝，直接返回 −1 ；

isBalanced 函数实现判断：
返回值： 若 fun(root) != -1 ，则说明此树平衡，返回 true ； 否则返回 false 。
*/

class Solution { // 从上到下判断（先序遍历）
    int depth(TreeNode* cur){ // 计算cur深度
        if(!cur) return 0;
        return max(depth(cur->right), depth(cur->left)) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        return abs(depth(root->left) - depth(root->right)) <=1 && isBalanced(root->left) && isBalanced(root->right);
    }
};
/*
depth 函数计算当前节点cur的深度：
返回值： 通过后序遍历的方式实现深度计算。
终止条件： 空节点深度为0。

isBalanced 函数实现判断：
返回值： 先判断 当前子树 是不是平衡树，再判断 左右子树 是不是平衡树（先序遍历递归（根左右））。
终止条件： 空节点当然是平衡树。
*/
