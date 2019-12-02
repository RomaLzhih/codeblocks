#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
const int maxn = 1e5 + 5;  //车辆编号的最大值
stack<int> park, tmp_park;
queue<int> wait;
int n, price;
int T;                   // Time
int car_state[maxn][2];  //[i][0]代表该辆车进入停车场的时间
//[i][1]代表该辆车处在哪个位置，0为park，1为tmp，2为wait
//[i][2]代表这个车在停车场时，由于其他车的出去而离开停车场的时间

void car_in(int id, int time) {
    if (park.size() < n) {
        car_state[id][0] = time;
        car_state[id][1] = 0;
        park.push(id);
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
        while (park.top() != id) {
            tmp_park.push(park.top());
            car_state[park.top()][2] -= T++;
            park.pop();
        }
        park.pop();
        while (!tmp_park.empty()) {
            park.push(tmp_park.top());
            car_state[tmp_park.top()][2] += T++;
            tmp_park.pop();
        }
        park.push(wait.front());  //等待区的车进去停车场
        wait.pop();
        car_state[park.top()][0] = T;
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