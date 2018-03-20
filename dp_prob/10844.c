#include<stdio.h>
#define mod 1000000000
long long int dp[101][10];

int main(){
    int length; scanf("%d", &length);

    for(int i = 1 ;  i < 10 ; i++)
      dp[1][i] = 1;

    for(int curr_index = 2 ;curr_index <= length ; curr_index++)
      {
        int last_num = 1;
        for(; last_num < 9 ; last_num ++)
          {
            dp[curr_index][last_num] += dp[curr_index - 1][last_num - 1];
            dp[curr_index][last_num] += dp[curr_index - 1][last_num + 1];

            dp[curr_index][last_num] %= mod;
            dp[curr_index][last_num] %= mod;
          }

        dp[curr_index][0] += dp[curr_index - 1][1];
        dp[curr_index][0] %= mod;

        dp[curr_index][9] += dp[curr_index - 1][8];
        dp[curr_index][9] %= mod;
      }

    long long int result = 0;
    for(int i = 0; i < 10; i++) result += dp[length][i];

    printf("%lld\n",result%mod);

    return 0;
}


