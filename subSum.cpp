//
//  main.cpp
//  subSum
//
//  Created by Zhao Tianqi on 2017/05/06.
//  Copyright © 2017年 Asmita. All rights reserved.
//

/*#include <iostream>
using namespace std;

int a[]{1,2,4,7};
int n=4,k=11;

bool dfs(int i,int sum){
    cout<<"dfs one time"<<",";
    if(i==n) return sum==k;
    if(dfs(i+1,sum))return 1;
    if(dfs(i+1,sum+a[i]))return 1;
    return 0;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    bool res=dfs(0, 0);
    cout << res<<endl;
    return 0;
}*/
#include <iostream>
#include <vector>
using namespace std;
int a[4]={1,2,4,7},k;
vector<int> ans;
bool found=false;
void dfs(int i,int sum)
{
    cout<<"dfs,"<<i;
    //if(found) return;
    if(i==4){
        if(sum==k)
        {
            found=true;
            for(int i=0;i!=ans.size();i++)cout<<ans[i]<<" ";
            cout<<endl;
            return ;
        }
        else
            return ;
    }
    dfs(i+1,sum);
    if(found) return;
    ans.push_back(a[i]);
    dfs(i+1,sum+a[i]);
    ans.pop_back();
    return ;
}
int main()
{
    k=2;
    dfs(0,0);
}
