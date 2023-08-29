#include <bits/stdc++.h>
using namespace std;
/*
merge sort O(nlog(n))
*/


void merge(int i, int mid, int j, vector<int> &v) {
    vector<int> temp;
    int ii = i;
    int jj = mid + 1;
    while (ii <= mid && jj <= j) {
        if (v[ii] < v[jj]) {
            temp.push_back(v[ii]);
            ii++;
        } else {
            temp.push_back(v[jj]);
            jj++;
        }
    }

    while (ii <= mid) {
        temp.push_back(v[ii]);
        ii++;
    }
    while (jj <= j) {
        temp.push_back(v[jj]);
        jj++;
    }

    for (int idx = i; idx <= j; idx++) {
        v[idx] = temp[idx - i];
    }

}

void mergeSort(int i, int j, vector<int> &v) {
    if (i == j) return;
    int mid = (i + j) / 2;
    mergeSort(i, mid, v);
    mergeSort(mid + 1, j, v);
    merge(i, mid, j, v);
}


int main()
{
    vector<int> v = {2, 1, 5, 3, 9, 0};
    int n = v.size();
    mergeSort(0, n - 1, v);
    for (auto it : v) cout << it << " ";
}