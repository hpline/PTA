#include <iostream>
#include <vector>
using namespace std;

void PrintPreOrder(vector<int> &pre, int n1, int n2, 
                   vector<int> &in,  int m1, int m2)
{
    if(n1 >= n2 || m1 >= m2) return ;
    int root = pre[n2-1];
    cout << ' ' << root;
    int i = m1;
    for(; i < m2; i++) {
        if(in[i] == root) break;
    }
    int diff = i - m1;
    if(diff) PrintPreOrder(pre, n1, n1+diff, in, m1, i);
    PrintPreOrder(pre, n1+diff, n2-1, in, i+1, m2);
}

int main()
{
    int N;
    cin >> N;
    vector<int> postorder;
    postorder.reserve(N);
    vector<int> inorder;
    inorder.reserve(N);
    for(int i = 0; i < N; i++) cin >> postorder[i];
    for(int i = 0; i < N; i++) cin >> inorder[i];
    cout << "Preorder:";
    PrintPreOrder(postorder, 0, N, inorder, 0, N);
    return 0;
}