
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> fnrslt;
        vector<int> pivot(k,0);
        int i=0;
        while(i>=0)
        {
            pivot[i]++;
            if(pivot[i]>n) --i;//backtrack when suppass, retreat one by one step
            else if(i==k-1) fnrslt.push_back(pivot);
            else
            {
                pivot[i+1]=pivot[i];
                ++i;
            }
        }
        return fnrslt;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    shared_ptr<Solution> psol (new Solution);// direct initialization
    vector<vector<int>> rslt= psol->combine(5, 3);
    for(auto &elem:rslt)
    {
        for(auto &subeme:elem)
            cout<<subeme<<",";
        cout<<endl;
            
    }
    return 0;
}
