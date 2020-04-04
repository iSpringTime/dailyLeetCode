#include "OJ.h"
#include "common_dataStruct.h"
#include "list.h"
#include "queue.h"
#include "sort.h"

// #include<iostream>
// #include<algorithm>

#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "malloc.h"
#include "math.h"
#include "time.h"

void copyNums(int* input, int *output, int numSize)
{
    for (int i = 0;i < numSize;i++) {
        output[i] = input[i];
    }
}
int numsSizeOfLIS(int* nums, int numsSize){
    int *sortNums = NULL;
    int maxLength = 0;
    int maxSortLength = 0;
    int pos = 0;
    int i = 0;
    int j = 0;

    sortNums = (int*)malloc(sizeof(int)*numsSize);
    copyNums(nums, sortNums, numsSize);
    BubbleSort2(sortNums, numsSize);
    for (int i = 0;i < numsSize;i++) {
        printf("sortNums:%d.\n", sortNums[i]);
    }

    for (i = 0;i < numsSize; i++) {
        for (j = 0;j < numsSize;j++) {
            if (sortNums[i] == nums[j]) {
                pos = j;
                break;
            }
        }
        for (j = pos;j < numsSize;j++) {
            if (sortNums[pos] < nums[j]) {
                maxLength++;
            }
        }
        if (maxLength > maxSortLength) {
            maxSortLength = maxLength;
        }
        maxLength = 0;
    }
    free(sortNums);
    return maxSortLength;
}
#define max(x, y) (x) > (y)?(x):(y)

int lengthOfLIS(int* nums, int numsSize){
    int *dp = NULL;
    int cont = 0;

    dp = (int*)malloc(numsSize * sizeof(int));
    memset(dp, 1, numsSize);
    for (int i = 0;i < numsSize;i++) {
        printf("%d\n", dp[i]);
    }

    for (int i = 0;i < numsSize;i++) {
        for (int j = 0;j < i;j++) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    for (int j = 0;j < numsSize;j++) {
        cont = max(cont, dp[j]);
    }
    free(dp);
    return cont;
}
int main()
{
    int input[8] = {10,9,2,5,3,7,101,18};
    int result;
    result = lengthOfLIS(input, 8);
    printf("result:%d.", result);
}
