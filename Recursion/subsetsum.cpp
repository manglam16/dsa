#include<bits/stdc++.h>
using namespace std;

int ans;

int print(vector<int> ip,vector<int> op,int k,int sum)
{
    if (ip.size() == 0) {
        if (sum <= k) {
            cout<<sum<<endl;
            return 1;
        }else return 0;
    }
    vector<int> op1 = op;
    vector<int> op2 = op;
    op1.push_back(ip[0]);
    int temp = op1.back();
    ip.erase(ip.begin());
    int l = print(ip,op1,k,sum+temp);
    int r = print(ip,op2,k,sum);
    return l+r;
}


int main(){
    vector<int> ip = {3,5,6,7};
    int k = 9;
    vector<int> op;
    cout<<print(ip,op,k,0);

}