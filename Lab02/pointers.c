 #include <stdio.h> 
 
 int main(){ 
    int x = 0, y = 0, *px, *py; 
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    // printf("%d\n", x);
    // printf("%d\n", y);
    // printf("%d\n", arr[0]);
    // printf("Addresses:\n");
    // printf("%p\n", &x);
    // printf("%p\n", &y);

    // px = &x;
    // py = &y;

    // printf("%d & %p\n", *px, &px);
    // printf("%d & %p\n", *py, &py);

    // int *p = &arr[0];

    // for(int i = 0; i < 10; i++){
    //     printf("%d, ", *(p+i));
    // }
    // printf("\n");

    int *ptr = arr;
    int *ptr2 = &arr[0];
    printf("%p %p\n", ptr, ptr2);

    return 0; 
} 
 