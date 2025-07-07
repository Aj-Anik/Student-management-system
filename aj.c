#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    char name[100];
    char id[10];
    char sec[5];
    int number;
    double cgpa;
    int sem;
};

struct Student a[100];

int nos;

int main()
{
    FILE *f = fopen("data.txt", "r");

    if (f == NULL)
    {
        FILE *nf = fopen("data.txt", "w");
        if (nf != NULL)
            fclose(nf);
    }
    else
    {
        fclose(f);
    }

    while (1)
    {
        int type;
        printf("  ******************************\n\n");
        printf("    Student Management System\n\n");
        printf("  ******************************\n\n");
        printf("1.show all student information.\n");
        printf("2.add a student.\n");
        printf("3.delete a student.\n");
        printf("4.Update student info.\n");
        printf("5.exit.\n");

        scanf("%d", &type);
        if (type == 5)
        {
            system("cls");
            printf("Exiting ..........");
            break;
        }
            
        if (type > 5 || type < 1)
            continue;

        // ----------------------- show all student info -----------------------
        if (type == 1)
        {
            FILE *data = fopen("data.txt", "r");
            if (data == 0)
            {
                printf("Error opening the file...\n");
            }
            else
            {
                int i = 0;
                // ############## scaning the data form the file ##############
                while (fscanf(data, "%s", a[i].id) == 1)
                {
                    fscanf(data, " %[^\n]", a[i].name);
                    fscanf(data, "%s", a[i].sec);
                    fscanf(data, "%d", &a[i].number);
                    fscanf(data, "%lf", &a[i].cgpa);
                    fscanf(data, "%d", &a[i].sem);
                    i++;
                }
                nos = i;
            }
            fclose(data);

            // ############## sorting the data form the file ##############

            for (int i = 0; i < nos; i++)
            {
                for (int j = i + 1; j < nos; j++)
                {
                    if (a[i].sem < a[j].sem)
                    {
                        struct Student temp;

                        temp = a[i];
                        a[i] = a[j];
                        a[j] = temp;
                    }
                }
            }

            // ############## writing the data form the file ##############

            printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
            if (nos == 0)
            {
                printf("no student found\n\n");
                printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            }
            else
            {
                system("cls");
                for (int i = 0; i < nos; i++)
                {
                    printf(" Student ID: %s\n", a[i].id);
                    printf(" Student Name: %s\n", a[i].name);
                    printf(" Student Section: %s\n", a[i].sec);
                    printf(" Student Phone nuber: %d\n", a[i].number);
                    printf(" Student CG: %.2lf\n", a[i].cgpa);
                    printf(" Student Semister: %d\n\n", a[i].sem);
                }
                printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            }
        }

        // ----------------------- Add a student to the file -----------------------

        else if (type == 2)
        {
            FILE *data = fopen("data.txt", "r");
            if (data == 0)
            {
                printf("Error opening the file...\n");
            }
            else
            {
                int i = 0;
                // ############## scaning the data form the file ##############
                while (fscanf(data, "%s", a[i].id) == 1)
                {
                    fscanf(data, " %[^\n]", a[i].name);
                    fscanf(data, "%s", a[i].sec);
                    fscanf(data, "%d", &a[i].number);
                    fscanf(data, "%lf", &a[i].cgpa);
                    fscanf(data, "%d", &a[i].sem);
                    i++;
                }
                nos = i;
            }
            fclose(data);

            // ############## Taking new student info ##############
            system("cls");
            struct Student temp;

            printf("Enter the id: \n");
            scanf("%s", temp.id);
            printf("Enter the name: \n");
            scanf(" %[^\n]", temp.name);
            printf("Enter the section: \n");
            scanf("%s", temp.sec);
            printf("Enter the phone number: \n");
            scanf("%d", &temp.number);
            printf("Enter the cgpa: \n");
            scanf("%lf", &temp.cgpa);
            printf("Enter the semister: \n");
            scanf("%d", &temp.sem);
            
            system("cls");
            printf("Sucessfully Added\n\n\n");
            a[nos] = temp;
            nos++;

            // ############## writing the new data file ##############

            data = fopen("data.txt", "w");

            for (int i = 0; i < nos; i++)
            {
                fprintf(data, "%s\n", a[i].id);
                fprintf(data, "%s\n", a[i].name);
                fprintf(data, "%s\n", a[i].sec);
                fprintf(data, "%d\n", a[i].number);
                fprintf(data, "%.2lf\n", a[i].cgpa);
                fprintf(data, "%d\n", a[i].sem);
            }
            fclose(data);
        }

        // ----------------------- delete a student info -----------------------

        else if (type == 3)
        {
            FILE *data = fopen("data.txt", "r");
            if (data == 0)
            {
                printf("Error opening the file...\n");
            }
            else
            {
                int i = 0;
                // ############## scaning the data form the file ##############
                while (fscanf(data, "%s", a[i].id) == 1)
                {
                    fscanf(data, " %[^\n]", a[i].name);
                    fscanf(data, "%s", a[i].sec);
                    fscanf(data, "%d", &a[i].number);
                    fscanf(data, "%lf", &a[i].cgpa);
                    fscanf(data, "%d", &a[i].sem);
                    i++;
                }
                nos = i;
            }
            fclose(data);

            // ############## taking required id ##############
            char id[10];
            int loc = -1; // location index can be 0
            printf("Enter students ID: ");
            scanf("%s", id);

            // ############## finding the id in the stored ids ##############

        for (int i = 0; i < nos; i++)
        {
            if (strcmp(a[i].id, id) == 0)
            {
                loc = i;
                break;
            }
        }
        // ############## rearranging the ids in the new positions ##############
        if (loc == -1)
        {
            printf("ID not found\n");
        }
        else
        {
            for (int i = loc; i < nos - 1; i++)
            {
                a[i] = a[i + 1];
            }
            nos--;
            // ############## writing the new data file ##############
            FILE *dataw = fopen("data.txt", "w");
            if (dataw == NULL)
            {
                printf("Error opening the file for writing...\n");
            }
            else
            {
                for (int i = 0; i < nos; i++)
                {
                    fprintf(dataw, "%s\n", a[i].id);
                    fprintf(dataw, "%s\n", a[i].name);
                    fprintf(dataw, "%s\n", a[i].sec);
                    fprintf(dataw, "%d\n", a[i].number);
                    fprintf(dataw, "%.2lf\n", a[i].cgpa);
                    fprintf(dataw, "%d\n", a[i].sem);
                }
                fclose(dataw);
            }
            printf("..........................\n");
            printf("Successfully Deleted\n");
            printf("..........................\n");
        }
        }

        // ----------------------- Update student info -----------------------

        else if (type == 4)
        {
            system("cls");
            FILE *data = fopen("data.txt", "r");
            if (data == 0)
            {
                printf("Error opening the file...\n");
            }
            else
            {
                int i = 0;
                // ############## scaning the data form the file ##############
                while (fscanf(data, "%s", a[i].id) == 1)
                {
                    fscanf(data, " %[^\n]", a[i].name);
                    fscanf(data, "%s", a[i].sec);
                    fscanf(data, "%d", &a[i].number);
                    fscanf(data, "%lf", &a[i].cgpa);
                    fscanf(data, "%d", &a[i].sem);
                    i++;
                }
                nos = i;
            }
            fclose(data);

            /// 2.update info in the array

            char id[100];
            system("cls");
            printf("Enter ID: ");
            scanf("%s", id);

            // find the location
            int loc = -1;
            for (int i = 0; i < nos; i++)
            {
                if (strcmp(a[i].id, id) == 0)
                {
                    loc = i;
                    break;
                }
            }
            if (loc == -1)
            {
                printf("ID not found\n\n\n\n");
                continue;
            }

            printf("1. Update Student Name\n");
            printf("2. Update Student Semester\n");
            printf("3. Update Student section\n");
            printf("4. Update Student CGPA\n");
            printf("5. Update Student phone number\n");
            printf("6. Update Student attendence\n");

            int choice;

            scanf("%d", &choice);

            if (choice == 1)
            {
                char name[100];
                printf("Enter new name: ");
                scanf("\n%[^\n]", name);
                strcpy(a[loc].name, name);
            }

            else if (choice == 2)
            {
                int sem;
                printf("Enter Semester: ");
                scanf("%d", &sem);
                a[loc].sem = sem;
            }
            else if (choice == 3)
            {
                char sec[5];
                printf("Enter Section: ");
                scanf("%s", sec);
                strcpy(a[loc].sec, sec);
            }
            else if (choice == 4)
            {
                double cg;
                printf("Enter CGPA: ");
                scanf("%lf", &cg);
                a[loc].cgpa = cg;
            }

            else if (choice == 5)
            {
                int num;
                printf("Enter New number: ");
                scanf("%d", &num);
                a[loc].number = num;
            }
            else if (choice == 6)
            {
                printf("Enter attended days: ");
                double att;
                scanf("%lf", &att);
                printf("Enter total days: ");
                double total;
                scanf("%lf", &total);
            }
            system("cls");

            /// 3. Write Student array content to the file
            data = fopen("data.txt", "w");
            if (data == 0)
            {
                printf("Error opening the file...\n");
            }
            else
            {
                for (int i = 0; i < nos; i++)
                {
                    fprintf(data, "%s\n", a[i].id);
                    fprintf(data, "%s\n", a[i].name);
                    fprintf(data, "%s\n", a[i].sec);
                    fprintf(data, "%d\n", a[i].number);
                    fprintf(data, "%.2lf\n", a[i].cgpa);
                    fprintf(data, "%d\n", a[i].sem);
                }
            }
            fclose(data);
            printf("Sucessfully Updated\n\n\n\n");
        }
    }

    return 0;
}
