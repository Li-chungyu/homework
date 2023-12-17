int main() {
    int arr[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    int *ptr=&arr[0][0];  // ptr是一個指標，指向包含4個整數的一維陣列
  // 將指標指向陣列的第一行

    // 使用指標算術存取陣列元素
    printf("Element at row 2, column 1: %d\n", *(ptr+4));

    return 0;
}