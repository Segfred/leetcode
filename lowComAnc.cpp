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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
if(!reachable(root,p)||!reachable(root,q)) return nullptr;
if(!root||root==p||root==q) return root;
TreeNode* pleft=lowestCommonAncestor(root->left,p,q);
if(pleft&&pleft!=p&&pleft!=q) return pleft;
TreeNode* pright=lowestCommonAncestor(root->right,p,q);     
if(pright&&pright!=p&&pright!=q)  return pright;
if(pleft&&pright) return root;
return pleft? pleft:pright;//防止节点都在一边(比如左)，而又不是根节点的情况，比如5/6/7都在最左边，pleft=6
    }
private:
bool reachable(TreeNode* root, TreeNode* pnode){
if(!root) return false;
if(root==pnode) return true;
return (root->left,pnode)||(root->right,pnode);
}
};


