#include <stdio.h>

int dp[1000001];

int main() {
    int n;
    scanf("%d", &n);

    int limit = n+1;

    for (int i = 1; i < limit; ++i) {
        int temp = dp[i]+1;
        if (2*i < limit && (!dp[2*i] || dp[2*i] > temp)) dp[2*i] = temp;
        if (3*i < limit && (!dp[3*i] || dp[3*i] > temp)) dp[3*i] = temp;
        if (i+1 < limit && (!dp[i+1] || dp[i+1] > temp)) dp[i+1] = temp;
    }

    /* checking dp values
    for (int i = 1; i < limit; ++i) {
        printf("dp[%d] : %d\n", i, dp[i]);
    }
    */
    printf("%d\n", dp[n]);

    return 0;
}
