#include<stdio.h>
#include<string.h>

int str_len(char str1[]){

int i=0;

while(str1[i]!='\0'){
        i++;
        }
    return i;
}

int concatenate(char str1[],char str2[]){

int i=0,j=0;

while(str1[i]!='\0'){
        i++;}

while(str2[j]!='\0'){
      str1[i]=str2[j];
      i++;
      j++;}
    str1[i]='\0';
return str1;
}

int Compare(char str1[],char str2[]){

int i=0;

while(str1[i]!='\0'&&str2[i]!=0){
   if(str1[i]<str2[i]){
       return -1;
       }
    else if(str1[i]>str2[i]){
       return 1;}
       i++;
       }


if(str1[i]!='\0'&&str2[i]!='\0'){
        return 0;
}
else if(str1=='\0'){
    return -1;
}
else{
    return 1;
}
}

int Insert(char str[],char sub[],int index){

 int i,j;
 int len=str_len(str);
 int sub_len= str_len(sub);

 for(i=len-1;i>=index;i--){
    str[i+sub_len]=str[i];
 }

 for(i=index,j=0;j<sub_len;i++,j++){
    str[i]=sub[j];

 str[len+sub_len]='\0';
 return str;
}}

int main(){

char s1[100],s2[100],sub[100];
int index;

printf("give the first string:\n");
gets (s1);
printf("give the second string:\n");
gets (s2);
printf("give the substring:\n");
gets (sub);
int result=Compare(s1,s2);
printf("give the index: \n");
scanf("%d",&index);

printf("the length of the string is %d\n",str_len(s1));

printf("concatenating string 2 to string 1:%s\n",concatenate(s1,s2));

if(result==0){
    printf("both strings are equal\n");
}
if(result==1){
    printf("first string is greater\n");
}
else{
    printf("second string is greater\n");
}

printf("inserting the string:%s\n ",Insert(s1,sub,index));


}


