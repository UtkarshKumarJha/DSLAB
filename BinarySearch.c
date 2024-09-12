#include<stdio.h>

int main(){
    int arr[50],n,a,pos;
    printf("Enter the no. of elements\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the element to be searched\n");
    scanf("%d",&a);
    pos = BinarySearch(arr, n,0,a);
    printf("Element is found at index n o. =%d",pos+1);
}

int BinarySearch(int arr[50],int high,int low, int a){
    int mid = (high + low)/2;
    if(arr[mid]>a){
        return BinarySearch(arr, mid,low,a);
    }
    if(arr[mid]<a){
        return BinarySearch(arr,high,mid,a);
    }
    if(arr[mid]==a){
        return mid;
    }
}
