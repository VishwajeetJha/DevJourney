//Practical 3(C): Develop a program to generate the result based on marks of 6 subjects. (if else if ladder).
#include <stdio.h>

void main(){

    int marks[6], total = 0;
    float percentage;
    printf("Enter marks of 6 subjects (out of 100): \n");
    for (int i = 0; i < 6; i++) {
        scanf("%d", &marks[i]);
        total += marks[i];
    }

    percentage = (total / 600.0) * 100;

    printf("\nTotal Marks: %d\n", total);
    printf("Percentage: %.2f%%\n", percentage);

    if (percentage >= 90)
        printf("Grade: A+\n");
    else if (percentage >= 80)
        printf("Grade: A\n");
    else if (percentage >= 70)
        printf("Grade: B+\n");
    else if (percentage >= 60)
        printf("Grade: B\n");
    else if (percentage >= 50)
        printf("Grade: C\n");
    else if (percentage >= 40)
        printf("Grade: D\n");
    else
        printf("Grade: F\n");
}

/*OUTPUT:-
Enter marks of 6 subjects (out of 100): 
89 90 99 80 74 85

Total Marks: 517
Percentage: 86.17%
Grade: A*/