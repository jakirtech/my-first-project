#include <stdio.h>
#include <string.h>

#define MAX 100

// Structure
struct Student {
    char name[50];
    int roll;
    float phy, chem, math;
};

// Function to add students
void addStudents(struct Student s[], int *n) {
    int count;
    printf("\nEnter number of students: ");
    scanf("%d", &count);

    for (int i = 0; i < count; i++) {
        printf("\nStudent %d\n", *n + 1);

        printf("Enter Name: ");
        scanf(" %[^\n]", s[*n].name);

        printf("Enter Roll No: ");
        scanf("%d", &s[*n].roll);

        printf("Enter Physics Marks: ");
        scanf("%f", &s[*n].phy);

        printf("Enter Chemistry Marks: ");
        scanf("%f", &s[*n].chem);

        printf("Enter Maths Marks: ");
        scanf("%f", &s[*n].math);

        (*n)++;
    }
}

// Display students
void displayStudents(struct Student s[], int n) {
    if (n == 0) {
        printf("\nNo data available!\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        printf("\nStudent %d\n", i + 1);
        printf("Name: %s\n", s[i].name);
        printf("Roll: %d\n", s[i].roll);
        printf("Physics: %.2f\n", s[i].phy);
        printf("Chemistry: %.2f\n", s[i].chem);
        printf("Maths: %.2f\n", s[i].math);
    }
}

// Main function
int main() {
    struct Student s[MAX];
    int n = 0;
    int choice;

    while (1) {
        printf("\n===== MENU =====\n");
        printf("1. Add Students\n");
        printf("2. Display Students\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudents(s, &n);
                break;

            case 2:
                displayStudents(s, n);
                break;

            case 3:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}