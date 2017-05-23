#include<iostream>
using namespace std;
int main() {
    int a, b;
    bool isfirst = true;
    while (cin>>a>>b) //注意这里的！！！！
    {
        if (b == 0) continue;
        if (!isfirst)
            cout << " ";
        else
            isfirst = false;
        cout << a*b << " " << b - 1;
    }
    if (isfirst) {
        cout << "0 0";
    }
    return 0;
}
