#include <iostream>
#include <vector>

using namespace std;

int getLcsWithKchanges(string &A, string &B, int k) {
    int m = A.length(), n = B.length();
    if (m == 0 || n == 0) return 0;

    vector<vector<vector<int>>> lcs(m+1, vector<vector<int>>(n+1, vector<int>(k+1, 0)));
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            for (int c = 1; c <= k; c++) {
                int premax = max(lcs[i-1][j][c], lcs[i][j-1][c]);
                if (A.at(i-1) == B.at(j-1)) {
                    lcs[i][j][c] = max(premax, lcs[i-1][j-1][c] + 1);
                } else {
                    lcs[i][j][c] = max(premax, lcs[i-1][j-1][c-1] + 1);
                }
            }
    return lcs[m][n][k];
}

#define MAX  20
int getLcs(int dp[MAX][MAX][MAX], string &A, string &B, int i, int j, int k) {
    if (k < 0) return -1e7;
    if (i < 0 || j < 0) return 0;

    int &ans = dp[i][j][k];
    if (ans != -1) {
        return ans;
    }

    ans = max(getLcs(dp, A, B, i, j-1, k), getLcs(dp, A, B, i-1, j, k));

    if (A[i] == B[j])
        ans = max(ans, getLcs(dp, A, B, i-1, j-1, k) + 1);
    else 
    ans = max(ans, getLcs(dp, A, B, i-1, j-1, k-1) + 1);

    return ans;
}

int main() {
    string A = "1224";
    string B = "3234";
    int k = 2;
    cout << getLcsWithKchanges(A, B, k) << endl;
    int dp[MAX][MAX][MAX];
    memset(dp, -1, sizeof(dp));
    cout << getLcs(dp, A, B, A.length()-1, B.length()-1, k) << endl;
    return 0;
}
