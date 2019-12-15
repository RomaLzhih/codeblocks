#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 10;  //车辆编号的最大值

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
    if (!stack_isEmpty(S)) {
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
    if (!stack_isEmpty(S)) return S->next->data;
    printf("the stack is empty\n");
    return 0;
}

Element stack_size(Stack S) {
    if (S == NULL) {
        printf("please create stack\n");
        return -1;
    }
    return length;
}
/*********************END STACK***********************/

/***********************QUEUE*************************/
//定义节点
typedef struct node {
    int data;
    struct node *next;
} node;

//定义队列（保存队首和队尾指针）
typedef struct queue_link {
    node *front;
    node *rear;
} que;

//初始化队列
que *InitQueue() {
    que *q = (que *)malloc(sizeof(que));
    q->front = q->rear = NULL;
    return q;
}

//判断队列是否为空
int EmptyQueue(que *q) { return q->front == NULL; }

//入队
void InQueue(que *q, int data) {
    node *n = (node *)malloc(sizeof(node));
    if (n == NULL)  //内存分配失败
        return;
    n->data = data;
    n->next = NULL;  //尾插法，插入元素指向空
    if (q->rear == NULL) {
        q->front = n;
        q->rear = n;
    } else {
        q->rear->next = n;  //让n成为当前的尾部节点下一节点
        q->rear = n;        //尾部指针指向n
    }
}

//出队(删除队首元素)
void DeQueue(que *q) {
    node *n = q->front;
    if (q->front == NULL)  //判断队列是否为空
        return;
    if (q->front == q->rear)  //是否只有一个元素
    {
        q->front = NULL;
        q->rear = NULL;
    } else {
        q->front = q->front->next;
        free(n);
    }
}

//打印队列
void DisplayQueue(que *q) {
    node *n = (node *)malloc(sizeof(node));
    n = q->front;
    if (n == NULL) {
        return;  //队列为空
    }
    while (n != NULL) {
        printf("%d ", n->data);
        n = n->next;
    }
    printf("\n");
}
/**********************END QUEUE*************************/

Stack park, tmp_park;
que *wait;
int n, price;
int T;                   // Time
int car_state[maxn][3];  //[i][0]代表该辆车进入停车场的时间
//[i][1]代表该辆车处在哪个位置，0为park，1为tmp，2为wait
//[i][2]代表这个车在停车场时，由于其他车的出去而离开停车场的时间

//有车进入
void car_in(int id, int time) {
    if (stack_size(park) < n) {
        car_state[id][0] = time;
        car_state[id][1] = 0;
        stack_push(park, id);
    } else {
        car_state[id][0] = -1;
        car_state[id][1] = 2;
        InQueue(wait, id);
    }
    return;
}

//查询操作
void query(int id, int now) {
    cout << "Car NO. " << id << " is in: ";
    if (car_state[id][1] == 0) {
        cout << "Park area" << endl;
    } else if (car_state[id][1] == 1) {
        cout << "Waiting other car exit" << endl;
    } else {
        cout << "Waiting area" << endl;
    }

    cout << "it spent " << car_state[id][2]
         << " unit time due to other car leave the park." << endl;

    cout << "Car NO. " << id << " needs to be charged: $";
    if (car_state[id][0] < 0) {
        cout << 0 << endl;
    } else {
        cout << (now - car_state[id][0] - car_state[id][2]) * price << endl;
    }
    return;
}

//车离开
//每辆车进出都要花费单位1的时间
int car_leave(int id, int time) {
    T = time;
    if (car_state[id][1] == 0) {  //在停车场
        while (stack_top(park) != id) {
            stack_push(tmp_park, stack_top(park));
            car_state[stack_top(park)][2] -= T++;
            stack_pop(park);
        }

        cout << "Car NO. " << stack_top(park)
             << " will leave the park area, need to be charged: "
             << (T - car_state[id][0] - car_state[id][2]) * price << endl;

        stack_pop(park);

        while (!stack_isEmpty(tmp_park)) {
            stack_push(park, stack_top(tmp_park));
            car_state[stack_top(tmp_park)][2] += T++;
            stack_pop(tmp_park);
        }
        if (!EmptyQueue(wait)) {  //等待区的车进去停车场
            stack_push(park, wait->front->data);
        }
        DeQueue(wait);
        car_state[stack_top(park)][0] = T;
        cout << stack_size(park) << endl;
        DisplayQueue(wait);
    }

    if (car_state[id][1] == 2) {  //在等待区
        int first_car = wait->front->data;
        InQueue(wait, wait->front->data);
        DeQueue(wait);
        while (wait->front->data != first_car) {
            if (wait->front->data != id) {
                InQueue(wait, wait->front->data);
                DeQueue(wait);
            } else {
                DeQueue(wait);
            }
        }
    }
}

int main() {
    n = 3, price = 1;
    int cmd;  // 1代表添加一辆新的车到等待区，2代表查询车辆现在的计费，3代表离开一辆车
    int id = 0, time = 0;
    park = stack_createStack();
    tmp_park = stack_createStack();
    wait = InitQueue();
    cin >> id >> time;
    T = time;
    car_in(id, time);
    cin >> id >> time;
    car_in(id, time);
    cin >> id >> time;
    car_in(id, time);
    cin >> id >> time;
    car_in(id, time);
    cin >> id >> time;
    car_in(id, time);

    cin >> id >> time;
    car_leave(id, time);
    query(2, 8);
    query(4, 8);
    query(3, 8);
    cout << endl;
    return 0;
}