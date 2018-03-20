#include <stdio.h>

#define DIV 10007
int dp[1001];

int main()
{
  int n;
  scanf("%d", &n);

  dp[0] = 1;
  dp[1] = 1;
  for (int i = 2; i <= n; ++i) {
    dp[i] = (dp[i-1] + dp[i-2]) % DIV;
  }

  printf("%d\n", dp[n]);

  return 0;
}
