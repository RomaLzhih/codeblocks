/*
    整个c++文件在vscode2019下用gdb32编译器进行编译，无报错
    门子扬， 2016200103038，格拉斯哥学院
*/
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
struct Node {  //链表节点结构
    int id;
    Node *next;
};

Node *head = new Node(), *tail = new Node();

void init(int num) {  //链表初始化，num为一共有多少个人
    head->next = tail;
    tail->next = head;
    for (int i = 1; i <= num; i++) {
        Node *p = new Node();  //新建临时节点
        p->id = i;
        p->next = head;
        tail->next = p;
        tail = tail->next;  //反复后推指针
    }
    Node *p = head;
    for (int i = 1; i <= num; i++) {
        //由于按照上述方法新建之后对头会有两个空白元素，重新遍历去除那两个元素
        p->id = i;
        if (i != num)
            p = p->next;
        else
            p->next = head;  //循环链表，将队尾指针指向队头
    }
}

void print(int num) {  //打印操作，方便调试
    Node *p = head;
    cout << endl;
    for (int i = 1; i <= num; i++) {
        cout << p->id << " ";
        p = p->next;
    }
    return;
}

//求解过程，v为结果储存数组，ans为幸存者的编号，num为总量，k为指定的死亡数组
void solve(vector<int> &v, int &ans, int num, int k) {
    int count = 1;  //计数器
    int tot = 0;
    Node *p = head;
    while (1) {
        if (p->id == 0) {  //标记的人（已经死亡）直接跳过
            p = p->next;
        } else {
            if (count == k) {  //正好第k个人
                count = 1;
                tot++;
                if (num - tot == 0) {  //总数达到上限，即剩下了最后一个人
                    ans = p->id;
                    break;
                }
                v.push_back(p->id);  //储存幸存者的编号
                p->id = 0;
            } else {
                count++;  //计数器累加
            }
            p = p->next;
        }
    }
}

int main() {
    int num, k;
    cout << "Please input the people number and evil id: ";
    scanf("%d%d", &num, &k);
    vector<int> killed_order;  //死亡顺序
    int survival = 0;          //幸存者编号
    init(num);
    solve(killed_order, survival, num, k);
    cout << "Killed order is:";
    for (int i = 0; i < killed_order.size(); i++) {  //输出死去的人的顺序
        cout << " " << killed_order[i];
    }
    cout << endl;
    cout << "Survival man ID is: " << survival << endl;  //输出死亡的人名单
    return 0;
}