#include <stdio.h>

int dp[11];

int main()
{
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 4;

  for (int i = 4; i < 11; ++i)
    dp[i] = dp[i-1] + dp[i-2] + dp[i-3];

  int T;
  scanf("%d", &T);

  for (int t_i = 0; t_i < T; ++t_i)
    {
      int n;
      scanf("%d", &n);
      printf("%d\n", dp[n]);
    }

  return 0;
}
