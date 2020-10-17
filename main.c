#include <stdio.h>
#include <windows.h>

int llist[25565][4];

int  callback_list(const int list[]){
    int p = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                for (int l = 0; l < 4; ++l) {
                    if (i != j && i != k && i != l && j != k && j != l && k !=l){
                        llist[p][0] = list[i];
                        llist[p][1] = list[j];
                        llist[p][2] = list[k];
                        llist[p][3] = list[l];
                        p++;
                    }
                }
            }
        }
    }
    return p;
}

int main() {
    int number[4], amount;
    float sum = 0;
    char syn[4] = {'+', '-', '*', '/'};
    printf("请输入24点的四个数（用空格隔开）:\n");
    for (int i = 0; i < 4; ++i) {
        scanf("%d", number+i);
    }
    amount = callback_list(number);

    for (int l = 0; l < amount; ++l) {
        for (int j = 0; j < 4; ++j) {
            for (int i = 0; i < 4; ++i) {
                for (int k = 0; k < 4; ++k) {
                    sum = llist[l][0];
                    if (j == 0) {
                        sum += llist[l][1];
                    } else if (j == 1) {
                        sum -= llist[l][1];
                    } else if (j == 2) {
                        sum *= llist[l][1];
                    } else if (j == 3) {
                        sum /= llist[l][1];
                    }
                    if (i == 0) {
                        sum += llist[l][2];
                    } else if (i == 1) {
                        sum -= llist[l][2];
                    } else if (i == 2) {
                        sum *= llist[l][2];
                    } else if (i == 3) {
                        sum /= llist[l][2];
                    }
                    if (k == 0) {
                        sum += llist[l][3];
                    } else if (k == 1) {
                        sum -= llist[l][3];
                    } else if (k == 2) {
                        sum *= llist[l][3];
                    } else if (k == 3) {
                        sum /= llist[l][3];
                    }
                    if (sum == 24.0) {
                        printf("\n[(%d %c %d) %c %d] %c %d = 24\n", llist[l][0], syn[j], llist[l][1], syn[i], llist[l][2], syn[k],
                               llist[l][3]);
                    }
                }
            }
        }
    }

    printf("\nEnd\n\n");
    system("pause");
    return 0;
}