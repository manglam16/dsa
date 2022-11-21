#include <bits/stdc++.h>
using namespace std;

void solve(int zero,int one, int n, string op, vector<string> &ans){
    if(op.size()==n){
        ans.push_back(op);
        return;
    }
    if(zero==one){
        string op1 = op;
        op1.push_back('1');
        solve(zero,one+1,n,op1,ans);
    }
    if(one>zero){
        string op1 = op;
        string op2 = op;
        op1.push_back('1');
        op2.push_back('0');
        solve(zero,one+1,n,op1,ans);
        solve(zero+1,one,n,op2,ans);
    }
}

int main() {
    int n;
    cin>>n;
    string op = "";
    vector<string> ans;
    solve(0,0,n,op,ans);
    for(auto i : ans){
        cout<<i<<endl;
    }
}