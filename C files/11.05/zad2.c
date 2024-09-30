#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    float price;
    char number[10];
} Product;

typedef struct {
    char address[100];
    char productNumber[10];
} Client;

Product products[100];
int productCount=0 ;

Client order[100];
int orderCount = 0;



void addProduct (char* name, float price, char* number) {
    Product product;
    strcpy(product.name, name);
    product.price = price;
    strcpy(product.number, number);
    productCount++;
    products[productCount] = product;

    for (int i = 0; i < orderCount; i++) {
        if (order[i].productNumber == number) {
            printf("Client %s ordered %s\n", order[i].address, name);

            for (int j = i; j < orderCount - 1; j++) {
                order[j] = order[j + 1];
            }
            orderCount--;
            i--;
        }
    }
}

void newOrder(char* address, char* number) {
    int found = 0;
    for (int i=0; i<orderCount; i++){
        if (strcmp(products[i].number, number)) {
            found = 1;
            printf("Client %s, ordered %s\n",address, products[i].name);
            break;
        }
    }
    if (found !=0){
        Client neworder;
        strcpy(neworder.address, address);
        strcpy(neworder.productNumber, number);
        order[orderCount++] = neworder;
    }
}

int main() {
    char command[10];
    while (1) {
        scanf("%s", command);

        if (strcmp(command, "Product") == 0) {
            char name[100];
            float price;
            int number;
            scanf("%s", name);
            fflush(stdin);
            scanf("%f", &price);
            fflush(stdin);
            scanf("%s", number);
            addProduct(name, price, number);
        } else if (strcmp(command, "Order") == 0) {
            char address[100];
            int productNumber;
            scanf("%s", address);
            fflush(stdin);
            scanf("%s", productNumber);
            newOrder(address, productNumber);
        } else if (strcmp(command, "END") == 0) {
            break;
        }
    }

    return 0;
}







