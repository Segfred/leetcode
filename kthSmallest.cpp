struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* ret=nullptr;
        kthNode(root,k,ret);
        return ret->val;
    }
private:
    void kthNode(TreeNode* root, int &k, TreeNode *&ret){
        if(!root) return;
        kthNode(root->left,k,ret);
        if(--k==0) {
            ret=root;
            return;}
        
        kthNode(root->right,k,ret);
    }
    
    };