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
public:
    bool isValidBST(TreeNode* root) {
TreeNode* pre=nullptr;//int pre=INT_MIN是错误的，会造成和第一个节点进行比较
bool result=true;
inOrder(root, result, pre);
return result;        
    }
private:

void inOrder(TreeNode* pnode, bool &res, TreeNode* &pre){//必须要用引用，否则返回的时候和原来的pre进行比较了
if(!pnode) return;
inOrder(pnode->left,res,pre);
if(!res) return;//pruning, return once res is false
if(pre&&pnode->val<=pre->val) {res=false;return;}//对第一个遍历到的节点不设置最小值，因此初始值赋为空
pre=pnode;
inOrder(pnode->right,res,pre);
}
};
