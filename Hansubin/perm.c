#include <stdio.h>

void swap(int arr[], int i, int j) {
    int temp;
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void perm(int arr[], int start, int end) { 
    if (start == end) { //숫자 n개 만들어지면 출력
        for (int k = 0; k <= end; k++) {
            printf("%d", arr[k]); //arr[0]부터 arr[n-1]까지 출력
        }
        printf(" ");
        return;
    }
//perma(arr,0,n-1)로 가정
    for (int k = start; k <= end; k++) { //start부터 end까지 반복
        swap(arr, start, k); //arr[start],arr[k]을 바꾼다.
        perm(arr, start + 1, end); //바꾼 순열 출력
        swap(arr, start, k); //arr 원상복구
    }
}

int main(void) {
    int n;
    printf("자연수를 입력하세요(음수 입력시 종료):");
    scanf("%d", &n);

    while (1) {
        if (n < 0)
            break;

        int arr[n];
        for (int y = 0; y < n; y++)
            arr[y] = y + 1; //n개의 arr 배열 만듦

        perm(arr, 0, n - 1);
        printf("\n");

        printf("자연수를 입력하세요(음수 입력시 종료):");
        scanf("%d", &n);
    }
    return 0;
}
