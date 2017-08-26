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
    int diameterOfBinaryTree(TreeNode* root) {
int maxh=0;
postHeight(root,maxh);
return maxh;        
    }

private:
int postHeight(TreeNode* pnode, int &maxh){
if(!pnode) return 0;//叶子节点算高度1
if(!umap[pnode].empty()) return umap[pnode][0];//avoid map.count(pnode) which iterates through the whole umap
maxh=max(maxh,postHeight(pnode->left,maxh)+postHeight(pnode->right,maxh));//因此没有加2，定义问题
int res=max(postHeight(pnode->left,maxh), postHeight(pnode->right,maxh))+1;
umap[pnode].emplace_back(res);
return res;
}
unordered_map<TreeNode*, vector<int>> umap;//这里放vector纯粹为了省时间复杂度，实际上只需要放一个元素即可
};
