#include<stdio.h>

typedef struct Product{
    int id;
    char name[100];
    char category[100];
    float price;
    int qty;
};

int main(){
     int n;
     printf("Enter the number of products: ");
     scanf("%d",&n);
     struct Product p[n];
     readProducts(p, n);
     displayProducts(p, n);
     sortproductsBycandp(p, n);
     displayProducts(p, n);
     return 0;
}

void readProducts(struct Product p[50],int n){
     char buffer[100];
     for(int i=0;i<n;i++){
        printf("Enter the product's name: \n");
        scanf("%s",  &p[i].name);
        printf("Enter the product's ID. : \n");
        scanf("%d",  &p[i].id);
        fgets(buffer, sizeof(buffer), stdin);
        printf("Enter the product's category:  \n");
        scanf("%s",  &p[i].category);
        printf("Enter the product's price:  \n");
        scanf("%f",  &p[i].price);
        printf("Enter the quantity of product:  \n");
        scanf("%d",  &p[i].qty);
     }

 }

void sortproductsBycandp(struct Product p[50], int count) {
    struct Product temp;
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(p[j].category, p[j + 1].category)>0) {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
            if(strcmp(p[j].category, p[j + 1].category)==0){
                if(p[j].price > p[j + 1].price){
                    temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
                }
            }
        }
    }
 }

void displayProducts(struct Product p[], int n){
     for(int i=0;i<n;i++){
        printf("Name: %s\n", p[i].name);
        printf("ID : %d\n", p[i].id);
        printf("Category: %s\n", p[i].category);
        printf("Price : %f\n", p[i].price);
        printf("Quantity : %d\n", p[i].qty);
     }

 }
