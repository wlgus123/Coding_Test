#include <string>
#include <vector>

using namespace std;

// 더하기 합
inline int getSumPlus(vector<int> p_list)
{
    int sum = 0;
    for (int num : p_list)
        sum += num;
    return sum;
}

// 곱하기 합
inline int getSumMulti(vector<int> p_list)
{
    int sum = 1;
    for (int num : p_list)
        sum *= num;
    return sum;
}

int solution(vector<int> num_list) {
    if (num_list.size() > 10)
    {
        return getSumPlus(num_list);
    }
    else if (num_list.size() <= 10)
    {
        return getSumMulti(num_list);
    }

    return -1;
}