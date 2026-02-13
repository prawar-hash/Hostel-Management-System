#include <stdio.h>
#include <stdlib.h>

struct student {
    int id;
    char name[50];
    int room;
    float fees;
};

void addStudent();
void viewStudents();
void searchStudent();
void deleteStudent();

int main() {
    int choice;

    while (1) {
        printf("\n===== HOSTEL MANAGEMENT SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                viewStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

void addStudent() {
    FILE *fp;
    struct student s;
    fp = fopen("hostel.txt", "ab");

    printf("Enter Student ID: ");
    scanf("%d", &s.id);
    printf("Enter Name: ");
    scanf("%s", s.name);
    printf("Enter Room Number: ");
    scanf("%d", &s.room);
    printf("Enter Fees: ");
    scanf("%f", &s.fees);

    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);
    printf("Student added successfully!\n");
}

void viewStudents() {
    FILE *fp;
    struct student s;
    fp = fopen("hostel.txt", "rb");

    if (fp == NULL) {
        printf("No records found!\n");
        return;
    }

    printf("\nID\tName\tRoom\tFees\n");
    while (fread(&s, sizeof(s), 1, fp)) {
        printf("%d\t%s\t%d\t%.2f\n", s.id, s.name, s.room, s.fees);
    }
    fclose(fp);
}

void searchStudent() {
    FILE *fp;
    struct student s;
    int id, found = 0;

    fp = fopen("hostel.txt", "rb");
    printf("Enter Student ID to search: ");
    scanf("%d", &id);

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.id == id) {
            printf("Record Found!\n");
            printf("Name: %s\nRoom: %d\nFees: %.2f\n",
                   s.name, s.room, s.fees);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Student not found!\n");

    fclose(fp);
}

void deleteStudent() {
    FILE *fp, *temp;
    struct student s;
    int id;

    fp = fopen("hostel.txt", "rb");
    temp = fopen("temp.txt", "wb");

    printf("Enter Student ID to delete: ");
    scanf("%d", &id);

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.id != id) {
            fwrite(&s, sizeof(s), 1, temp);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("hostel.txt");
    rename("temp.txt", "hostel.txt");

    printf("Student record deleted successfully!\n");
}
