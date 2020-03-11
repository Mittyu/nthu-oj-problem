#include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    int year, sum, yearCount, leap;
    while(n--){
        sum = yearCount = 0;
        scanf("%d", &year);
        leap = year % 400 == 0 ||(year % 4 == 0 && year % 100 != 0);

        do{
            if ((year + yearCount) % 400 == 0 ||((year + yearCount) % 4 == 0 && (year + yearCount) % 100 != 0))
                sum += 2;
            else
                sum += 1;
            yearCount++;
        } while(sum % 7 != 0 || (leap != ((year + yearCount) % 400 == 0 ||((year + yearCount) % 4 == 0 && (year + yearCount) % 100 != 0))));
        printf("%d\n", year + yearCount);
    }

    return 0;
}