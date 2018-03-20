#include <stdio.h>

long long int dp[100];

int main()
{
  int n;
  scanf("%d", &n);

  dp[1] = 1;
  dp[2] = 1;

  for (int d_i = 3; d_i <= n; ++d_i)
    {
      // dp[d_i-1] : XX..XX0
      // dp[d_i-2] : XX..X01
      dp[d_i] = dp[d_i-1]+dp[d_i-2];
    }

  printf("%lld\n", dp[n]);

  return 0;
}
