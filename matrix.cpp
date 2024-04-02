#include <iostream>
#include <limits.h>
#include <vector>

void printOptimalParenthesis(std::vector<std::vector<int>>& s, int i, int j) {
    if (i == j)
        std::cout << "A" << i;
    else {
        std::cout << "(";
        printOptimalParenthesis(s, i, s[i][j]);
        printOptimalParenthesis(s, s[i][j] + 1, j);
        std::cout << ")";
    }
}

void matrixChainOrder(std::vector<int>& p) {
    int n = p.size() - 1;
    std::vector<std::vector<int>> m(n + 1, std::vector<int>(n + 1));
    std::vector<std::vector<int>> s(n + 1, std::vector<int>(n + 1));

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

    std::cout << "Optimal Parenthesization: ";
    printOptimalParenthesis(s, 1, n);
    std::cout << "\nMinimum number of multiplications is " << m[1][n] << "\n";
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4};
    matrixChainOrder(arr);
    return 0;
}