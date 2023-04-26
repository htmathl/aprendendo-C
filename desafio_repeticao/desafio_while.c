#include <stdio.h>

int main() {
    int count = 1;
    while (count <= 100) {
        printf("%d\n", count);
        count ++;
    }
    
    int sum = 0;
    for(int i = 1; i <= 100; i++) sum += i;
    printf("%d\n", sum);
}