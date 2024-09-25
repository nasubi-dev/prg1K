#include <stdio.h>

void showBin2(int c) {
    for (int i = 31; i >= 0; i--) {
        int bit = (c >> i) & 1;
        printf("%d", bit);
    }
    printf("\n");
}

int main() {
    showBin2(5 / 2);
    showBin2(5);
    showBin2(5 * 2);
    showBin2(20);
    showBin2(64);
    return 0;
}
