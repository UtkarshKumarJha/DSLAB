#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int main(){
    char str[50], str2[50],str3[50];
    printf("Enter the string:\n");
    scanf("%s",str);
    int k = stringlength(str);
    printf("The length of string is: %d\n", k);
    printf("Enter another string:\n");
    scanf("%s",str2);
    int l = stringlength(str2);
    concatation(&str,&str2,k,l);
    compareString(str,str2);

}
int stringlength(char str[50]){
    int count = 0;
    int i=0;

    while(str[i]!='\0'){
        count++;
        i++;
    }
    return count;
}

void concatation(char str[50], char str2[50],int k,int l){
    int i;
    for(i=0;i<l;i++){
        str[k+i] = str2[i];

    }
    str[l+k]='\0';
    printf("The string after concatanation is: %s\n", str);
}

void compareString(char str[50], char str2[50]) {
    int i = 0;
    int flag = 0;

    while (str[i] != '\0' && str2[i] != '\0') {
        if (str[i] != str2[i]) {
            flag = 1;
            break;
        }
        i++;
    }
    if (flag == 0) {
        if (str[i] != str2[i]) {
            flag = 1;
        }
    }
    if (flag == 1) {
        printf("The strings are unequal\n");
    } else {
        printf("The strings are equal\n");
    }
}



