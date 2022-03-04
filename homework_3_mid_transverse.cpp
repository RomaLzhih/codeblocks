/*
    整个c++文件在vscode2019下用gdb32编译器进行编译，无报错
    门子扬, 2016200103038, 格拉斯哥学院
*/
#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 100;
int lson[maxn];
int rson[maxn];
// n组数，给定n个节点的左右儿子，若是叶子节点儿子为-1

//中序遍历
void MID_TRANSVERSE(int root) {
    if (lson[root] != -1) MID_TRANSVERSE(lson[root]);
    printf("%d ", root);
    if (rson[root] != -1) MID_TRANSVERSE(rson[root]);
    return;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {  //读入
        int m, l, r;
        scanf("%d%d%d", &m, &l, &r);
        lson[m] = l;
        rson[m] = r;
    }
    int root;
    scanf("%d", &root);

    cout << "The Mid Transverse is: ";
    MID_TRANSVERSE(root);

    return 0;
}