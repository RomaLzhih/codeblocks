/*
    整个c++文件在vscode2019下用gdb32编译器进行编译，无报错
    门子扬, 2016200103038, 格拉斯哥学院
*/
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
using namespace std;

const int maxn = 20;
int ID = 1;                            //节点总数
int n;                                 //字符串的长度
int fa[maxn], lson[maxn], rson[maxn];  //每个节点的父节点
char series[maxn];                     //每个节点的编码
map<char, string> ch_code;             //字符的编码
map<char, int> ch_id;                  //字符的id
map<int, char> id_ch;                  // id对应的字符

struct node {  //节点
    int id, w;
    node(int a, int b) : id(a), w(b) {}
    bool operator<(const node &rhs) const {
        return w == rhs.w ? id > rhs.id : w > rhs.w;
    }
};
priority_queue<node> q;  //模拟树的优先队列

int main() {
    //读入数据集的大小
    scanf("%d", &n);

    //数据的读入
    for (int i = 1; i <= n; i++) {
        getchar();
        char ch;
        int weight;
        scanf("%c %d", &ch, &weight);
        ch_id[ch] = ID;
        id_ch[ID] = ch;
        lson[ID] = rson[ID] = -1;
        ID++;
        ch_code[ch] = "";
        q.push(node(ch_id[ch], weight));
    }
    cout << endl;

    //建树
    while (q.size() > 1) {
        node l = q.top();
        q.pop();
        node r = q.top();
        q.pop();
        node m(ID++, (l.w + r.w));
        fa[l.id] = fa[r.id] = m.id;
        lson[m.id] = l.id;
        rson[m.id] = r.id;
        printf("The father of %d and %d is new node: %d\n", l.id, r.id, m.id);
        series[l.id] = '0';  //标记左儿子
        series[r.id] = '1';  //标记右儿子
        q.push(m);
    }
    node top = q.top();  //顶部元素单独配置
    fa[top.id] = -1;
    cout << endl;

    //寻找字母对应的代码
    for (map<char, int>::iterator it = ch_id.begin(); it != ch_id.end(); it++) {
        char ch = it->first;
        int t = it->second;
        while (fa[t] != -1) {
            ch_code[ch].push_back(series[t]);
            t = fa[t];
        }
        reverse(ch_code[ch].begin(), ch_code[ch].end());
    }

    //输出字母对应的编码
    for (map<char, string>::iterator it = ch_code.begin(); it != ch_code.end();
         it++) {
        cout << it->first << ": " << it->second << endl;
    }

    //解码
    cout << "---------------Tree build finished-------------" << endl << endl;
    cout << "Please input the series: ";
    string s;
    cin >> s;
    cout << endl << "String is: ";
    int p = top.id;
    for (int i = 0; i < s.size(); i++) {
        p = (s[i] == '0' ? lson[p] : rson[p]);  //根据编码决定搜索方向
        if (lson[p] == -1) {
            printf("%c", id_ch[p]);
            p = top.id;
        }
    }
    return 0;
}