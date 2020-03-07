#define MAX 3000000

#include<stdio.h>
struct range
{
    int first;
    int second;
} range_;

int main(){

    int n, q;
    int sumRangeFirst, sumRangeSecond;
    long long int sum;
    long long int tmpSum;
    long long int numArray;
    long long int prefixSumArray[MAX];
    struct range rangeArray[MAX];

    while (scanf("%d%d", &n, &q)!=EOF){
        scanf("%lld", &numArray);
        prefixSumArray[0] = numArray;

        for (int i=1; i < n; ++i){
            scanf("%lld", &numArray);
            prefixSumArray[i] = prefixSumArray[i-1] + numArray;
        }

        for (int i = 0; i < q; ++i)
            scanf("%d%d", &rangeArray[i].first, &rangeArray[i].second);
        
        // find max range
        // 1. if first < second : sum up first
        // ( range array start 1) to second(include)
        // 2. if first > second : sum up to the last
        // then back to 1 and sum up to second
        // 3. if first == second : sum up only [first]
        // note: rangeArray start from 1.
        sum = 0;    // init.
        for (int i=0; i<q; ++i){
            tmpSum = 0;// init.
            if(rangeArray[i].first == rangeArray[i].second)
                tmpSum = prefixSumArray[rangeArray[i].first-1] - prefixSumArray[rangeArray[i].first-1-1];
            else if (rangeArray[i].first < rangeArray[i].second){
                tmpSum = prefixSumArray[rangeArray[i].second-1] - prefixSumArray[rangeArray[i].first-1-1];
            }else if (rangeArray[i].first > rangeArray[i].second){
                tmpSum = prefixSumArray[n-1] - prefixSumArray[rangeArray[i].first-1-1] + prefixSumArray[rangeArray[i].second-1];
            }
            if (sum < tmpSum){
                sum = tmpSum;
                sumRangeFirst = rangeArray[i].first;
                sumRangeSecond = rangeArray[i].second;
            }
        }
        printf("Max_range: (%d,%d); Value: %lld\n", sumRangeFirst, sumRangeSecond, sum);
    }


    return 0;
}