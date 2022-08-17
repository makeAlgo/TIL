#include <stdio.h>

int arr[50][50];

int main() {
    int n, m, cnt = 0;
    scanf("%d %d", &n, &m);
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            scanf("%1d", &arr[i][j]);
    }
 
    int num;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &num);
 
            if (arr[i][j] != num) arr[i][j] = 1;
            else arr[i][j] = 0;
        }
    }

    if (n < 3 || m < 3) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j]) {
                    printf("-1\n");
                    return 0;
                }
            }
        }
        printf("0\n");
    }
    else { 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j]) {
                    if (i < n - 2 && j < m - 2) {
                        for (int x = i; x < i + 3; x++) {
                            for (int y = j; y < j + 3; y++) {
                                arr[x][y] = !arr[x][y];
                            }
                        }
                        cnt++;
                    }
                    else {
                        printf("-1\n");
                        return 0;
                    }
                }
            }
        }
        printf("%d\n", cnt);
    }

    return 0;
}