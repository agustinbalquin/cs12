#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (a % b == 0){
        return b;
    }
    int x = a % b;
    return gcd(b, x);
    
    
}

bool diophantine(int a, int b, int c, int &x, int &y) {
    int u = 0;
    int v = 0;
    if (c  % gcd(a,b) != 0){
        return false;
    }
    if (a % b == 0) {
        x = 0;
        y = c / b;
        return true;
    }

    //ax + by = c
    int q = (a / b);
    int r = a % b;
    
    
    diophantine(b, r, c, u, v);
    x = v;
    y = u - q*x; 
    return true;
}



int main() {

    int a, b, c, x, y;

    cout << "Enter a b c" << endl;
    cin >> a >> b >> c;
    cout << endl;

    cout << "Result: ";
    if (diophantine(a, b, c, x, y)) {
        cout << x << " " << y << endl;
    } else {
        cout << "No solution!" << endl;
    }

    return 0;
}