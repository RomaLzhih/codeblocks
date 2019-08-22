#include <string.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
int digit[11];
string s;

int main() {
    int N;
    scanf("%d", &N);
    while (N--) {
        cin >> s;
        int o = 1;
        string mid = to_string(o);
        memset(digit, 0, sizeof(digit));
        while (mid != s) {
            for (int i = 0; i < mid.size(); i++) digit[mid[i] - '0']++;
            mid = to_string((++o));
        }
        for (int i = 0; i < mid.size(); i++) digit[mid[i] - '0']++;
        mid = to_string((++o));

        printf("%d", digit[0]);
        for (int i = 1; i < 10; i++) printf(" %d", digit[i]);
        puts("");
    }
    return 0;
}