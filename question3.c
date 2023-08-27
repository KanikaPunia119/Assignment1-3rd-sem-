#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* longDivision(const char* number, int divisor)
{
    char* ans = (char*)malloc((strlen(number) + 1) * sizeof(char));
    int ansIdx = 0;

    int idx = 0;
    int temp = number[idx] - '0';
    while (temp < divisor)
        temp = temp * 10 + (number[++idx] - '0');

    while (number[idx] != '\0') {
        ans[ansIdx++] = (temp / divisor) + '0';

        temp = (temp % divisor) * 10 + number[++idx] - '0';
    }

    ans[ansIdx] = '\0';

    if (ans[0] == '\0') {
        char* result = (char*)malloc(2 * sizeof(char));
        result[0] = '0';
        result[1] = '\0';
        free(ans);
        return result;
    }

    return ans;
}


int main()
{
    char* number;
    char num[1000];
    int divisor;
    printf("enter number: ");
    scanf("%s",num);
    number=num;
    printf("enter divisor: ");
    scanf("%d",&divisor);
    char* result = longDivision(number, divisor);
    printf("%s\n", result);
    free(result);
    return 0;
}