#define _CRT_SECURE_NO_WARNINGS

// dp ���� �ʿ���

#include <stdio.h>

int dp[41];
char input[41];

int main()
{
    int i;

    scanf("%s", input);

    dp[0] = 1;
    for (i = 0; input[i]; i++) {
        input[i] -= '0';
        if (input[i]) {
            dp[i + 1] += dp[i];
            if (input[i] * 10 + input[i + 1] - '0' <= 34)
                dp[i + 2] += dp[i];
        }
    }

    printf("%d\n", dp[i]);

    return 0;
}


// ��ó: https://ksj14.tistory.com/entry/BaekJoon2591-����ī�� [:: ADVANCE ::]
// 1111111111111111111111111111111111111111

// i = 39, dp[i+2] = 119177164