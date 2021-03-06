struct Node{
    string val;
    Node* next[26];
    Node():val(""){memset(next,0,sizeof(next));}
};
class Trie{
public:
    Trie():root(new Node{}){}
    ~Trie(){if(root) delete root;}
    void insert(string str){
        if(str.empty()) return;
        int idx;
        Node* pcur=root;
        for(char &c:str){
            idx=c-'a';
            if(!pcur->next[idx]) pcur->next[idx]=new Node{};
            pcur=pcur->next[idx];
        }
        pcur->val=str;
    }
    
    Node* root;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if(words.empty()||board.empty()||board[0].empty()) return {};
        //shared_ptr<Trie> ptree{new Trie{}};
        Trie* ptree{new Trie{}};
        const int m=(int)board.size(), n=(int)board[0].size();
        vector<string> res{};
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(string &ele:words) ptree->insert(ele);
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(ptree->root->next[board[i][j]-'a'])//是根节点的子节点，不是树本身，这里判断指针非空，只是存在前缀
                dfs(ptree->root->next[board[i][j]-'a'],visited,i,j,board,words,res);
            }//首字母必须要在树中，否则一定不可能
        }
        return res;//别忘了返回值
    }//end findWords
private:
    void dfs(Node* ptree,vector<vector<bool>> &visited,int x,int y,vector<vector<char>>& board, vector<string>& words, vector<string> &res){//dfs第一个参数是node*,非Trie*
        if(!ptree->val.empty()) {res.emplace_back(ptree->val);ptree->val.clear();}//这里判断值非空，单词存在。找到一个之后删除，去重
        visited[x][y]=true;//上一步不能直接后退，只是找到了一个前缀可能还有别的，比如run,running都要找出来，后退的话永远找不到running
        const int m=(int)board.size(), n=(int)board[0].size();
        int dir[4][2]{{-1,0},{1,0},{0,1},{0,-1}};
        for(int k=0;k<4;++k){
            int nx=x+dir[k][0], ny=y+dir[k][1];
            if(nx>=0&&nx<m&&ny>=0&&ny<n&&!visited[nx][ny]&&ptree->next[board[nx][ny]-'a']) 
                dfs(ptree->next[board[nx][ny]-'a'],visited,nx,ny,board,words,res);
        }
        visited[x][y]=false;//每个人都只管好自己的事情就够了，return之前先还原现场
        
    }
    
};
