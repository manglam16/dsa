#include <bits/stdc++.h>
using namespace std;

void solve(string ip, string op, std::vector<string> &v) {
    if (ip.size() == 0) {
        v.push_back(op);
        return;
    }
    string op1 = op;
    string op2 = op + ip[0];
    ip.erase(ip.begin() + 0);
    solve(ip, op1, v);
    solve(ip, op2, v);
}

int main() {
    string ip = "abc";
    std::vector<string> v;
    string op = "";
    solve(ip, op, v);
    for (auto i : v) {
        cout << i << endl;
    }
}