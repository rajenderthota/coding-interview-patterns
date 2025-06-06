#include <vector>
#include <algorithm>

int largestSquareInAMatrix(std::vector<std::vector<int>>& matrix) {
    if (matrix.empty()) {
        return 0;
    }
    int m = matrix.size();
    int n = matrix[0].size();
    std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
    int maxLen = 0;
    // Base case: If a cell in row 0 is 1, the largest square ending there has a 
    // length of 1.
    for (int j = 0; j < n; j++) {
        if (matrix[0][j] == 1) {
            dp[0][j] = 1;
            maxLen = 1;
        }
    }
    // Base case: If a cell in column 0 is 1, the largest square ending there has 
    // a length of 1.
    for (int i = 0; i < m; i++) {
        if (matrix[i][0] == 1) {
            dp[i][0] = 1;
            maxLen = 1;
        }
    }
    // Populate the rest of the DP table.
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] == 1) {
                // The length of the largest square ending here is determined by 
                // the smallest square ending at the neighboring cells (left, 
                // top-left, top), plus 1 to include this cell.
                dp[i][j] = 1 + std::min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]});
            }
            maxLen = std::max(maxLen, dp[i][j]);
        }
    }
    return maxLen * maxLen;
}