#include <stdio.h>

#define MAX_SIZE 1000

int n;
int arr[MAX_SIZE];
int dp[MAX_SIZE];

void __init__(void);
void __process__();
void __print_out__();

int main()
{
  __init__();
  __process__();
  __print_out__();

  return 0;
}

void __init__(void)
{
  scanf("%d", &n);

  for (int i = 0; i < n; ++i)
    {
      scanf("%d", &arr[i]);
      dp[i] = arr[i];
    }
}

void __process__()
{
  // left_index, right_index
  for (int r_i = 1; r_i < n; ++r_i)
    {
      for (int l_i = 0; l_i < r_i; ++l_i)
        {
          if (arr[l_i] < arr[r_i] && dp[r_i] < dp[l_i]+arr[r_i])
            dp[r_i] = dp[l_i]+arr[r_i];
        }
    }
}

void __print_out__()
{
  int max_num = dp[0];

  for (int i = 1; i < n; ++i)
    {
      if (max_num < dp[i])
        max_num = dp[i];
    }

  printf("%d\n", max_num);
}
