#include<stdio.h>

void delete_beg(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
}

void delete_pos(int arr[], int size, int pos) {
    if(pos<=0 && pos>size-1){
        printf("INVALID POSITION\n");
    }
    else{
        for (int i = pos - 1; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
    }
}

void delete_end(int arr[], int size) {
    // You need to decrease the size to remove the last element
    size--;
}

int main() {
    int arr[5] = {12, 34, 12, 56, 78};
    int size = 5;
    int choice = 0;
    
    while (choice != 1) {
        int operation;
        printf("BEGIN - 1\n");
        printf("FROM POSITION - 2\n");
        printf("END - 3\n");
        scanf("%d", &operation);
        
        if (operation == 1) {
            delete_beg(arr, size);
            size--;
        } else if (operation == 2) {
            int pos;
            printf("Enter the position: ");
            scanf("%d", &pos);
            delete_pos(arr, size, pos);
            size--;
        } else if (operation == 3) {
            delete_end(arr, size);
            size--;
        }
        
        printf("Enter 1 to discontinue and any other number to continue: ");
        scanf("%d", &choice);
    }

    printf("Array after deletion:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
