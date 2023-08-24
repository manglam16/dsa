#include <bits/stdc++.h>
using namespace std;

void solve(string ip, string op, std::vector<string> &v,int n) {
    if(n==ip.size()){
        v.push_back(op);
        return;
    }
    string op1 = op;
    string op2 = op;
    op2[n] = op2[n]-'a'+'A';
    solve(ip,op1,v,n+1);
    solve(ip,op2,v,n+1);
}

int main() {
    string ip = "abc";
    int n = ip.size();
    std::vector<string> v;
    string op = "abc";
    solve(ip, op, v,0);
    for (auto i : v) {
        cout << i << endl;
    }
}