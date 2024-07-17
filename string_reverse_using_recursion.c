#include<stdio.h>
#include<string.h>

void stringrev(char str[], int i, int j) {
    if (i > j)
        return;
    
    char a = str[i];
    str[i] = str[j];
    str[j] = a;
    i++;
    j--;
    // Update i and j for the next recursive call
    stringrev(str, i, j);
}

int main() {
    char str[] = "SHANTANU";
    int len = strlen(str);
    
    printf("Original string: %s\n", str);

    stringrev(str, 0, len - 1);
    
    printf("Reversed string: %s\n", str);
    return 0;
}