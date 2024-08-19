#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product {
    int p_id;
    char p_name[50];
    int p_qty;
    float p_price;
    float p_total_price;
    struct Product *next;
};

void insertProduct(struct Product **head_ref, int id, char name[], int qty, float price);
void displayProducts(struct Product *head);
void findProduct(struct Product *head, int choice);
void deleteProduct(struct Product **head_ref, int choice, int id, char name[]);

int main() {
    int num_products;
    printf("How many products you want to purchase: ");
    scanf("%d", &num_products);

    struct Product *head = NULL;

    for (int i = 0; i < num_products; i++) {
        int id, qty;
        char name[50];
        float price;
        
        printf("Enter product_id, product_name, product_qty, product_price: ");
        scanf("%d %s %d %f", &id, name, &qty, &price);

        insertProduct(&head, id, name, qty, price);
    }

    printf("=========== Purchased Output Product Information =============\n");
    displayProducts(head);

    char choice;
    printf("Do you want to find individual product information (y/n)?: ");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        int find_choice;
        printf("How do you want to find product information by ID or by Name: 1 for ID and 2 for Name: ");
        scanf("%d", &find_choice);
        findProduct(head, find_choice);
    }

    printf("Do you want to delete product record (y/n): ");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        int delete_choice;
        printf("How do you want to delete record by ID or By name? 1 for by ID and 2 for by Name: ");
        scanf("%d", &delete_choice);
        deleteProduct(&head, delete_choice, 0, "");
        printf("============= Updated Record ============\n");
        displayProducts(head);
    }

    struct Product *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

void insertProduct(struct Product **head_ref, int id, char name[], int qty, float price) {
    struct Product *new_product = (struct Product *)malloc(sizeof(struct Product));
    new_product->p_id = id;
    strcpy(new_product->p_name, name);
    new_product->p_qty = qty;
    new_product->p_price = price;
    new_product->p_total_price = qty * price;
    new_product->next = *head_ref;
    *head_ref = new_product;
}

void displayProducts(struct Product *head) {
    struct Product *temp = head;
    while (temp != NULL) {
        printf("%d %s %d %.2f %.2f\n", temp->p_id, temp->p_name, temp->p_qty, temp->p_price, temp->p_total_price);
        temp = temp->next;
    }
}

void findProduct(struct Product *head, int choice) {
    int id;
    char name[50];

    if (choice == 1) {
        printf("Enter product Id: ");
        scanf("%d", &id);
    } else if (choice == 2) {
        printf("Enter product Name: ");
        scanf("%s", name);
    }

    struct Product *temp = head;
    while (temp != NULL) {
        if ((choice == 1 && temp->p_id == id) || (choice == 2 && strcmp(temp->p_name, name) == 0)) {
            printf("%d %s %d %.2f %.2f\n", temp->p_id, temp->p_name, temp->p_qty, temp->p_price, temp->p_total_price);
            break;
        }
        temp = temp->next;
    }
}

void deleteProduct(struct Product **head_ref, int choice, int id, char name[]) {
    struct Product *temp = *head_ref;
    struct Product *prev = NULL;

    if (choice == 1) {
        printf("Enter Product ID: ");
        scanf("%d", &id);
    } else if (choice == 2) {
        printf("Enter Product Name: ");
        scanf("%s", name);
    }

    if (temp != NULL && ((choice == 1 && temp->p_id == id) || (choice == 2 && strcmp(temp->p_name, name) == 0))) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && ((choice == 1 && temp->p_id != id) || (choice == 2 && strcmp(temp->p_name, name) != 0))) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Product not found.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}