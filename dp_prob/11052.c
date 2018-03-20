#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int dp[1001];

int main()
{
  int n;
  scanf("%d", &n);

  int *p = calloc(n+1, sizeof(int));
  for (int p_i = 1; p_i <= n; ++p_i)
    {
      scanf("%d", &p[p_i]);
    }

  for (int n_i = 1; n_i <= n; ++n_i)
    {
      dp[n_i] = p[n_i]; // dp[n_i] = dp[0] + p[n_i]

      for (int sub_i = 1; sub_i < n_i; ++sub_i)
        {
          dp[n_i] = MAX(dp[n_i], dp[sub_i]+p[n_i-sub_i]);
        }
    }

  printf("%d\n", dp[n]);

  return 0;
}
