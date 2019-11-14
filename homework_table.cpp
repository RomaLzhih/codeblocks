/*
    整个c++文件在vscode2019下用gdb32编译器进行编译，无报错
    门子扬， 2016200103038，格拉斯哥学院
*/
#include <string.h>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

const int max_length = 1e6;  //表最长为1000000
typedef int ElementType;     //自定义int为Elementtype

//表的内容
struct Table {
    ElementType *elem;   //元素数组
    int length;          //当前表的长度
    int maximum_length;  //表的最长长度
} T;

//初始化表
bool init(Table &L, int input_length) {
    L.elem = new int[max_length];  //根据读入的数来初始化表的长度
    if (input_length > max_length) {  //如果超过最长长度则非法
        cout << "Initialize failed: Input length exceed maximum length, please "
                "restart the program."
             << endl;
        return false;
    }
    L.maximum_length = input_length;
    memset(L.elem, 0, sizeof(L));  //初始化表中的元素为0
    if (!L.elem) {                 //若elem元素不存在则初始化失败
        cout << "Initialize failed: Undefined container" << endl;
        return false;
    }
    L.length = 0;  //初始长度设置为0
    cout << "Please enter the basic element for the table. end with crtl + z: "
         << endl;
    ElementType val;
    while (scanf("%d", &val) != EOF) {
        L.elem[++L.length] = val;  //读取数字
    }
    return true;
}

//插入操作，pos为插入位置，val为插入的值
bool insert(Table &L, int pos, ElementType val) {
    if (pos < 1 ||
        pos > L.maximum_length) {  //若位置小于1或者位置超过最大长度则非法
        cout << "Insert failed: Insert position illegal" << endl;
        return false;
    }
    if (L.length + 1 > max_length) {  //如果插入之后的长度超过最长长度则失败
        cout << "Insert failed: List is full" << endl;
        return false;
    }
    for (int i = L.length + 1; i > pos; i--) {
        L.elem[i] = L.elem[i - 1];  //将长孺位置后面的元素依次后移
    }
    L.elem[pos] = val;  //插入元素
    L.length++;         //插入之后的长度增加1
    return true;
}

//寻找指定元素val的位置，考虑同一值的元素多次出现
void find_elem(Table &L, ElementType val) {
    bool flag = false;                     //初始认为该元素不存在
    vector<ElementType> v;                 //记录向量
    for (int i = 1; i <= L.length; i++) {  //遍历表进行查找
        if (L.elem[i] == val) {
            v.push_back(i);
            flag = true;
        }
    }
    if (flag) {  //若val存在
        cout << "Find " << val << " in:";
        for (int i = 0; i < v.size(); i++) {
            cout << " " << v[i];
        }
        cout << endl;
    } else {  //若不存在
        cout << "No such element found" << endl;
    }
}

//删除指定位置的元素
bool erase_value(Table &L, int pos) {
    if (pos < 1 || pos > L.length) {  //位置非法
        cout << "Delate failed: position illegal" << endl;
        return false;
    }  //将该位置后面的元素前移覆盖即可
    for (int i = pos; i < L.length; i++) {
        L.elem[i] = L.elem[i + 1];
    }
    cout << "Delate succeed." << endl;
    L.length--;  //缩短数组长度
    return true;
}

//打印表
void print_list(Table &L) {
    if (L.length == 0) {
        cout << "Table is empty" << endl;
    }
    for (int i = 1; i <= L.length; i++) {
        cout << L.elem[i] << " ";
    }
    cout << endl;
}

int main() {
    int len, pos;
    cout << "Welcome use the table test prigram~" << endl;
    cout << "Please enter the maximum table size: ";
    cin >> len;
    init(T, len);  //测试初始化

    cout << "Please specified where the element should be inserted and its "
            "value: ";
    ElementType val;
    cin >> pos >> val;
    if (insert(T, pos, val)) {  //测试插入
        cout << "Sucessed! The table now is: ";
        print_list(T);
    }

    cout << "Please enter the value which you want to know the position: ";
    cin >> val;
    find_elem(T, val);  //测试查找元素

    cout << "Please enter the position where you want to delate the element: ";
    cin >> pos;
    if (erase_value(T, pos)) {  //测试删除元素
        cout << "Sucessed! The table now is: ";
        print_list(T);
    }
    cout << "All the function is showed above, The final table is: ";
    print_list(T);  //测试打印整个表

    return 0;
}