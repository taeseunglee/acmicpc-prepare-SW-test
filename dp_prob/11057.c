#include <stdio.h>

#define DIV 10007
int dp[1001][10];

int main()
{
  int n;
  scanf("%d", &n);

  // dp[n][i] : 최고 자리가 n번째 자리이고 숫자가 i일 때, 오르막 개수
  for (int i = 0; i < 10; ++i)
    dp[1][i] = 1;

  for (int n_i = 1; n_i <= n; ++n_i)
    {
      dp[n_i][9] = 1; // 999.... n_i times

      for (int i = 8; i > -1; --i)
        {
          dp[n_i][i] = (dp[n_i][i+1] + dp[n_i-1][i]) % DIV;
        }
    }

  int result = 0;
  for (int i = 0; i < 10; ++i)
    {
      result += dp[n][i];
    }

  printf("%d\n", result % DIV);

  return 0;
}
