#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    float price;
    int stock;
} Product;

Product products[MAX_PRODUCTS];
int productCount = 0;

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Product list is full!\n");
        return;
    }
    printf("Enter product name: ");
    scanf("%s", products[productCount].name);
    printf("Enter product price: ");
    scanf("%f", &products[productCount].price);
    printf("Enter product stock: ");
    scanf("%d", &products[productCount].stock);
    products[productCount].id = productCount + 1;
    productCount++;
    printf("Product added successfully!\n");
}

void viewProducts() {
    if (productCount == 0) {
        printf("No products available.\n");
        return;
    }
    printf("\nAvailable Products:\n");
    printf("ID\tName\t\tPrice\t\tStock\n");
    for (int i = 0; i < productCount; i++) {
        printf("%d\t%-10s\t%.2f\t\t%d\n", products[i].id, products[i].name, products[i].price, products[i].stock);
    }
}

void purchaseProduct() {
    int id, quantity;
    printf("Enter product ID to purchase: ");
    scanf("%d", &id);
    if (id <= 0 || id > productCount) {
        printf("Invalid product ID!\n");
        return;
    }
    printf("Enter quantity to purchase: ");
    scanf("%d", &quantity);

    if (products[id - 1].stock < quantity) {
        printf("Insufficient stock!\n");
    } else {
        products[id - 1].stock -= quantity;
        printf("Purchase successful! Total cost: $%.2f\n", products[id - 1].price * quantity);
    }
}

void menu() {
    printf("\nOnline Shopping System\n");
    printf("1. Add Product\n");
    printf("2. View Products\n");
    printf("3. Purchase Product\n");
    printf("4. Exit\n");
}

int main() {
    int choice;
    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                viewProducts();
                break;
            case 3:
                purchaseProduct();
                break;
            case 4:
                printf("Exiting the program. Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
