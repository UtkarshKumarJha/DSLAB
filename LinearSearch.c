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
    for(int i=0;i<n;i++){
          if(arr[i]==a){
                pos=i;
                break;
          }
    }
    if(pos!=0){
        printf("Element found at index no.= %d!", pos+1);
    }else printf("Element not found!");
    return 0;


}
