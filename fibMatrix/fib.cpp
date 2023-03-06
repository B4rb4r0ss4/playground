#include <bits/stdc++.h>
using namespace std;
#define UwU cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
typedef long long ll;

struct Matrix {
    int n = 2, m =2;
    ll val[2][2] = {{0, 0},{0, 0}};

    Matrix operator*(const Matrix& other) {
        Matrix r;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < other.m; j++) {
                for (int k = 0; k < m; k++) {
                    r.val[i][j] += val[i][k] * other.val[k][j];
                }
            }
        }
        return r;
    }

    Matrix iden(int n) {
        Matrix r;
        for (int i = 0; i < n; i++) {
            r.val[i][i] = 1;
        }
        return r;
    }

    Matrix pow(int p) {
        if (p == 0) {
            return iden(n);
        }
        else if (p % 2 == 0) {
            Matrix h = pow(p / 2);
            return h * h;
        }
        else {
            return *this * pow(p - 1);
        }
    }
};

ll fib(int n) {
    Matrix mat;
    mat.val[0][0] = mat.val[0][1] = mat.val[1][0] = 1;
    mat.val[1][1] = 0;
    Matrix p = mat.pow(n - 1);
    return p.val[0][0];
}

int main() {
    UwU; 
    int n; cin>>n;
    cout<<fib(n);
}

