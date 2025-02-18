#include <stdio.h>
struct hooman {
    char name[50];
    int age;
};
int main() {
    struct hooman h1;
    struct hooman *ptrH = &h1;

    printf("Enter name: ");
    scanf("%s", ptrH->name); // Using -> to access structure members via pointer
    printf("Enter age: ");
    scanf("%d", &ptrH->age);
    printf("Person's name: %s\n", ptrH->name);
    printf("Person's age: %d\n", ptrH->age);
    return 0;
}