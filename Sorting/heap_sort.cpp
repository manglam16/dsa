/*
to convert an array into a heap(max-heap or min-heap) takes O(n) time.
heap is a complete tree which follows heap property.
insertion and deletion takes O(logn) time.
heapify function takes log(n) complexity.
heap sort - removes top element from heap and again heapify it. do it until the array is empty.
*/

#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &v, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && v[largest] < v[l]) largest = l;
    if (r < n && v[largest] < v[r]) largest = r;
    if (largest != i) {
        swap(v[i], v[largest]);
        heapify(v, n, largest);
    }
}


void heapSort(vector<int> &v, int n) {
    // iski complexity o(n)
    for (int i = n / 2; i >= 0; i--) {
        heapify(v, n, i);
    }

    //iski complexity O(nlog(n))
    for (int i = n - 1; i >= 1; i--) {
        swap(v[0], v[i]);
        heapify(v, i, 0);
    }
}


int main()
{
    vector<int> v = {2, 1, 5, 3, 9, 0};
    heapSort(v, v.size());
    for (auto it : v) cout << it << " ";
}