//searching element in an array
#include <stdio.h>

//linear search algorithm
int linearSearch(int a[], int l, int key){
    int pos;
    for(int i=0; i<l; i++){
        if(key == a[i]){
            pos = i+1;
            break;
        }
        else
            pos = -1;        
    }
    return pos;
}
     
int main(){           
    int arr[10];
    int searchKey, length, position, flag;
    printf("Enter no. of elements of array: ");
    scanf("%d",&length);

    for(int i=0; i<length; i++){
        printf("Enter element %d: ", i+1);
        scanf("%d",&arr[i]);
    }

    printf("Enter search item: ");
    scanf("%d",&searchKey);

    position = linearSearch(arr, length, searchKey);
    if(position != -1)
        printf("%d is present at position %d of given array\n", searchKey, position);
    else
        printf("%d is absent in given array\n", searchKey);
    return 0;
}
