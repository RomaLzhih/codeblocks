#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>

#include "stack.h"
using namespace std;
const int maxn = 1e5 + 5;  //车辆编号的最大值

/*************************STACK***********************/

typedef struct Node *ptrToNode;
typedef struct Node *Stack;
typedef int Element;

struct Node {
    Element data;
    ptrToNode next;
};

int length;

//创建栈
Stack stack_createStack() {
    length = 0;
    Stack S = (Stack)malloc(sizeof(struct Node));
    if (S == NULL) {
        printf("failed to createStack\n");
        return NULL;
    }
    S->next = NULL;
    return S;
}

//判断栈是否为空
int stack_isEmpty(Stack S) { return S->next == NULL; }

//出栈
void stack_pop(Stack S) {
    if (S == NULL) {
        printf("please create stack\n");
        return;
    }
    if (!isEmpty(S)) {
        ptrToNode ptr = S->next;
        S->next = ptr->next;
        free(ptr);
        length--;
    } else {
        printf("the stack is empty");
    }
}

//入栈
void stack_push(Stack S, Element e) {
    if (S != NULL) {
        ptrToNode ptr = (ptrToNode)malloc(sizeof(struct Node));
        ptr->data = e;
        ptr->next = S->next;
        S->next = ptr;
        length++;
    } else {
        printf("please create stack\n");
    }
}

//清空栈
void stack_makeEmpty(Stack S) {
    ptrToNode ptr;
    if (S == NULL) {
        printf("please creatr stack\n");
        return;
    }
    while (S->next != NULL) {
        ptr = S->next;
        S->next = ptr->next;
        free(ptr);
        length = 0;
    }
}

//返回栈顶元素
Element stack_top(Stack S) {
    if (S == NULL) {
        printf("please create stack\n");
        return -1;
    }
    if (!isEmpty(S)) return S->next->data;
    printf("the stack is empty\n");
    return 0;
}

//销毁栈
void destoryStack(Stack &S) {
    if (S != NULL) {
        makeEmpty(S);
        ptrToNode ptr = S;
        free(ptr);
        S = NULL;
        length = 0;
    }
}

Element stack_size(Stack S) {
    if (S == NULL) {
        printf("please create stack\n");
        return -1;
    }
    return length;
}
/*********************END STACK***********************/

Stack park, tmp_park;
queue<int> wait;
int n, price;
int T;                   // Time
int car_state[maxn][2];  //[i][0]代表该辆车进入停车场的时间
//[i][1]代表该辆车处在哪个位置，0为park，1为tmp，2为wait
//[i][2]代表这个车在停车场时，由于其他车的出去而离开停车场的时间

void car_in(int id, int time) {
    if (stack_size(park) < n) {
        car_state[id][0] = time;
        car_state[id][1] = 0;
        stack_push(park, id);
    } else {
        car_state[id][0] = -1;
        car_state[id][1] = 2;
        wait.push(id);
    }
    return;
}

void query(int id, int now) {
    cout << "NO. " << id << " is in: ";
    if (car_state[id][1] == 0) {
        cout << "Park area" << endl;
    } else if (car_state[id][1] == 1) {
        cout << "Waiting other car exit" << endl;
    } else {
        cout << "Waiting area" << endl;
    }
    cout << "NO. " << id << " needs to be charged: $";
    if (car_state[id][0] < 0) {
        cout << 0 << endl;
    } else {
        cout << (now - car_state[id][0] - car_state[id][2]) * price << endl;
    }
    return;
}

int car_leave(int id) {
    if (car_state[id][1] == 0) {  //在停车场
        while (stack_top(park) != id) {
            stack_push(tmp_park, stack_top(park));
            car_state[stack_top(park)][2] -= T++;
            stack_pop(park);
        }
        stack_pop(park);
        while (!stack_isEmpty(tmp_park)) {
            stack_push(park, stack_top(tmp_park));
            car_state[stack_top(tmp_park)][2] += T++;
            stack_pop(tmp_park);
        }
        stack_push(park, wait.front());  //等待区的车进去停车场
        wait.pop();
        car_state[stack_top(park)][0] = T;
    }

    if (car_state[id][1] == 2) {  //在等待区
        int first_car = wait.front();
        wait.push(wait.front());
        wait.pop();
        while (wait.front() != first_car) {
            if (wait.front() != id) {
                wait.push(wait.front());
                wait.pop();
            } else {
                wait.pop();
            }
        }
    }
}

int main() {
    int cmd;  // 1代表添加一辆新的车到等待区，2代表查询车辆现在的计费，3代表离开一辆车
    int id = 0, time = 0;
    while (scanf("%d", &cmd) != EOF) {
        switch (cmd) {
            case 1: {
                cout << "Please input the car id and its enter time: ";
                cin >> id >> time;
                T = time;
                car_in(id, time);
                cout << endl;
                break;
            }
            case 2: {
                cout << "Please input the car id needed to query and query "
                        "time: ";
                cin >> id >> time;
                query(id, time);
                cout << endl;
                break;
            }
            case 3: {
                cout << "Please input the car id needed to leave the queue: ";
                cin >> id;
                car_leave(id);
                break;
            }
            default: {
                cout << "Invalid command, please re-enter:";
                break;
            }
        }
    }
    return 0;
}