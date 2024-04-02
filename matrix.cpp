#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

void printOptimalParenthesis(vector<vector<int>>& s, int i, int j) {
    if (i == j)
        cout << "A" << i;
    else {
        cout << "(";
        printOptimalParenthesis(s, i, s[i][j]);
        printOptimalParenthesis(s, s[i][j] + 1, j);
        cout << ")";
    }
}

void matrixChainOrder(vector<int>& p) {
    int n = p.size() - 1;
    vector<vector<int>> m(n + 1, vector<int>(n + 1));
    vector<vector<int>> s(n + 1, vector<int>(n + 1));

    for (int l = 2; l < n + 1; l++) {
        for (int i = 1; i < n - l + 2; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    cout << "Optimal Parenthesization: ";
    printOptimalParenthesis(s, 1, n);
    cout << "\nMinimum number of multiplications is " << m[1][n] << "\n";
}

int main() {
    vector<int> arr = {5,4,6,2,3,1};
    matrixChainOrder(arr);
    return 0;
}