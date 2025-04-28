// 181928 이어 붙인 수
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// num_list_len은 배열 num_list의 길이입니다.
int solution(int num_list[], size_t num_list_len) {
    int evenSum = 0, oddSum = 0;
    int evenPlace = 1, oddPlace = 1;
    for(int i = num_list_len - 1; i >= 0; i--)
    {
        if(num_list[i] % 2 == 0) 
        {
            evenSum += num_list[i] * evenPlace;
            evenPlace *= 10;
        }
        else 
        {
            oddSum += num_list[i] * oddPlace;
            oddPlace *= 10;
        }
    }
    
    return evenSum + oddSum;
}