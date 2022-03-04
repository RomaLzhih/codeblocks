/*
    整个c++文件在vscode2019下用gdb32编译器进行编译，无报错
    门子扬， 2016200103038，格拉斯哥学院
*/
#include <stdlib.h>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

typedef int ElementType;

//节点
struct Node {
    ElementType value;  //节点的值
    Node *prev, *next;  //指向前一个结点的指针和指向后一个节点的指针
};
Node *head, *tail;  //头节点指针和后向指针

//初始话整个链表
bool init(int num) {
    head = new Node();   //分配空间给头指针
    tail = new Node();   //分配空间给尾指针
    if (head == NULL) {  //无法分配空间，报错
        cout << "Initialize failed, space distribute error" << endl;
        exit(-1);  //直接退出程序
    }
    head->next = tail;
    tail->prev = head;
    ElementType val;
    cout << "Please specfied the value, end with crtl+z: " << endl;
    while (scanf("%d", &val) != EOF) {
        Node *q = new Node();  //临时节点
        q->value = val;        //赋值
        tail->next = q;        //将前一个节点的下一个指向q
        q->prev = tail;
        q->next = NULL;
        tail = q;  //替换尾指针
    }
    return true;
}

//插入操作，在指定的位置pos插入值val
bool insert(int pos, ElementType val) {
    Node *q = new Node();
    Node *p = head->next;
    for (int i = 0; i < pos - 1; i++) {
        p = p->next;  //不停的下移指针直到指定位置
    }
    q->value = val;
    q->next = p->next;
    p->next = q;  // 插入元素
    return true;
}

//删除所有值为val的元素
void erase_value(ElementType val) {
    bool flag = false;
    Node *p = head;
    p = p->next->next;
    while (p != NULL) {  //遍历链表寻找元素
        if (p->value == val) {
            p->prev->next =
                p->next;  //将p的上一个节点的后向指针指向p的下一个节点
            p->next->prev =
                p->prev;  //将p的下一个节点的前驱指针指想p的前一个结点
            Node *tmp = p->next;
            delete (p);  //释放空间
            flag = true;
            p = tmp;  //重新定义p的位置
        } else {
            p = p->next;
        }
    }
    if (flag) {
        cout << "Delate successed! Now the list is: ";
    } else {  //不存在这样的元素
        cout << "No such element found" << endl;
    }
}

//查找指定值的元素的位置，考虑重复出现的情况
void find_value(ElementType val) {
    bool flag = false;
    int count = 0;  //计数器
    vector<int> v;
    Node *q = head->next->next;
    while (q != NULL) {  //直到找到，否则一直累加
        ++count;
        if (q->value == val) {
            v.push_back(count);
            flag = true;
        }
        q = q->next;
    }
    if (flag) {  //找到了，输出所有位置
        cout << "Find " << val << " in:";
        for (int i = 0; i < v.size(); i++) {
            cout << " " << v[i];
        }
        cout << endl;
    } else {  //不存在该元素
        cout << "No such element found" << endl;
    }
}

//打印链表
void print_list() {
    Node *q = head->next->next;
    if (q == NULL) {
        cout << "list is empty" << endl;
    }
    while (q != NULL) {
        cout << q->value << " ";
        q = q->next;
    }
    cout << endl;
}

int main() {
    int len, pos;
    ElementType val;
    cout << "Welcome use the list test prigram~" << endl;
    cout << "Please enter the maximum table size: ";
    cin >> len;
    if (init(len)) {  //测试初始化
        cout << "Initialize successed! Now the list is: ";
        print_list();
    }

    cout << "Please enter the value you want to delate: ";
    cin >> val;
    erase_value(val);  //测试删除元素
    print_list();

    cout << "Please specified where the element should be inserted and its "
            "value: ";

    cin >> pos >> val;
    if (insert(pos, val)) {  //测试插入
        cout << "Sucessed! The table now is: ";
        print_list();
    }

    cout << "Please enter the value which you want to know the position: ";
    cin >> val;
    find_value(val);  //测试查找元素

    cout << "All the function is showed above, The final table is: ";
    print_list();

    return 0;
}