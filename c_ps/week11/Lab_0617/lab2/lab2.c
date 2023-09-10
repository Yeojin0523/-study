// 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int* memo;
int H(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    if (memo[n] != 0) {
        return memo[n];
    } // �޸������̼� -> ������ ��� ���� �����ϰ� 1�� return
    // �ƴϴ� �ϸ� return �ٸ� ��
    int result = 0;
    for (int i = 0; i < n; i++) {
        result += H(i) * H(n - 1 - i);
    }

    memo[n] = result;
    return result;
}

int main(void) {
    int n;
    printf("0���� ū ����: ");
    scanf("%d", &n);

    memo = (int*)malloc((n + 1) * sizeof(int));
    if (memo == NULL) {
        printf("�޸� �Ҵ� ����\n");
        return 1;
    }

    for (int i = 0; i <= n; i++) {
        memo[i] = 0;
    }

    printf("����� %d\n", H(n));

    free(memo);
    return 0;
}