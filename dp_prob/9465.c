#include <stdio.h>

int stk[100001][2];
int dp[100001][2];

int max_of_three(int a, int b, int c)
{
  int temp = a > b ? a : b;
  return (temp > c ? temp : c);
}

int main()
{
  int T;
  scanf("%d", &T);

  for (int t_i = 0; t_i < T; ++t_i)
    {
      int n;
      scanf("%d", &n);

      for (int n_i = 0; n_i < n; ++n_i)
        scanf("%d", &stk[n_i][0]);
      for (int n_i = 0; n_i < n; ++n_i)
        scanf("%d", &stk[n_i][1]);

      for (int i = 0; i < 2; ++i)
        {
          dp[0][i] = stk[0][i];
          dp[1][i] = stk[1][i] + stk[0][i^1];
        }

      for (int d_i = 2; d_i < n; ++d_i)
        {
          dp[d_i][0] = max_of_three(dp[d_i-1][1], dp[d_i-2][0], dp[d_i-2][1])
            + stk[d_i][0];
          dp[d_i][1] = max_of_three(dp[d_i-1][0], dp[d_i-2][0], dp[d_i-2][1])
            + stk[d_i][1];
        }
      printf("%d\n", dp[n-1][0] > dp[n-1][1] ? dp[n-1][0] : dp[n-1][1]);
    }


  return 0;
}
