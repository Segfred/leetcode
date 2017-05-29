/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
ostringstream os;
helpser(root,os);
return os.str();        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
istringstream is(data);
return helpdeser(is);        
    }
private:
void helpser(TreeNode* root, ostringstream &out){
if(!root) {out<<"# ";return;}
out<<root->val<<' ';
helpser(root->left,out);
helpser(root->right,out);
}

TreeNode* helpdeser(istringstream &in){
string str;
in>>str;
if(str=="#") return nullptr;
TreeNode* pnode=new TreeNode(stoi(str));
pnode->left=helpdeser(in);
pnode->right=helpdeser(in);
return pnode;
}
};