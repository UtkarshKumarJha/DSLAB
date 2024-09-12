#include<stdio.h>

int main(){
    int arr[50],n,a,pos;
    printf("Enter the no. of elements\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    BubbleSort(arr, n);
    return 0;
}
void BubbleSort( int arr[50], int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("Element are: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
