# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void bbsort(int arr[], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
}

void f(int index, int arr[], int used[], int tmp[], int n) {
    if (index == n) {
        for (int i = 0; i < n; i++)
            printf("%d%c", tmp[i], (i == n - 1) ? ' ' : '\n');
    }
    else {
        for (int i = 0; i < n; i++) {
            if (used[i] == 0) {
                used[i] = 1;
                tmp[index] = arr[i];
                f(index + 1, arr, used, tmp, n);
                used[i] = 0;
            }
        }
    }
}

// ���N�@�h�hf����arr�]�m��used = 1, �M��b�̫�@��(index = n - 1) ��f�]�m����, �K�|print�@��
// , �M��N�̫�@��used�ܬ�0, �M�ᱵ�۩��^�]index = n - 2�ɪ�used = 0, �M��N�S�|�i�J(index = n - 1) ���l���D
// , �]��else ����for�j��|�� i++;
// �M��index = n - 2���槹�N�|�iindex = n - 3, �@������

int main() {
    int n;
    scanf("%d", &n);
    int arr[11], used[11] = { 0 }, tmp[11] = { 0 };
    for (int i = 0; i < n; i++) scanf("%d", &(arr[i]));

    bbsort(arr, n);

    f(0, arr, used, tmp, n);


    return 0;
}
