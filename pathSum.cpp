void findSum(struct node *head, int sum, vector<int> &buffer, int level, vector<vector<int>> &res)
{
    if (!head) return;
    int tmp = 0;
    buffer.push_back(head->data);
    for (int i = level; i >= 0; --i)
    {
        tmp += buffer[i];
        if (tmp ==sum) res.push_back(vector<int> (buffer.begin()+i,buffer.end()) );
    }
    findSum(head->lchild, sum, buffer, level + 1,res);
    findSum(head->rchild, sum, buffer, level + 1,res);
    buffer.pop_back();
}

vector<vector<int>> pathSum(node* root, int sum){
    vector<vector<int>> res{};
    vector<int> buffer{};
    findSum(root, sum, buffer, 0, res);
    return res;
}