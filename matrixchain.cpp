#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

// Function to print optimal parenthesization from DP
void printOptimalParens(const vector<vector<int> >& s, int i, int j) {
    if (i == j)
        cout << "A" << i;
    else {
        cout << "(";
        printOptimalParens(s, i, s[i][j]);
        cout << " x ";
        printOptimalParens(s, s[i][j] + 1, j);
        cout << ")";
    }
}

int main() {
    int n;
    cout << "Enter number of matrices: ";
    cin >> n;

    vector<int> dimensions(n + 1);
    cout << "Enter dimensions (P0 to P" << n << "): ";
    for (int i = 0; i <= n; ++i)
        cin >> dimensions[i];

    // Initialize DP tables
    vector<vector<int> > m(n + 1, vector<int>(n + 1, 0));
    vector<vector<int> > s(n + 1, vector<int>(n + 1, 0));

    // DP logic to calculate the minimum multiplication cost
    for (int length = 2; length <= n; ++length) {
        for (int i = 1; i <= n - length + 1; ++i) {
            int j = i + length - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; ++k) {
                int cost = m[i][k] + m[k + 1][j] + dimensions[i - 1] * dimensions[k] * dimensions[j];
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }

    // Print the optimal parenthesization and cost
    cout << "\nOptimal parenthesization:\n";
    printOptimalParens(s, 1, n);
    cout << " = " << m[1][n] << endl;

    return 0;
}

