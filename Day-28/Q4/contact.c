#include <stdio.h>
#include <string.h>

struct Contact
{
    char name[50];
    char phone[15];
    char email[50];
};

int main()
{
    struct Contact contact[100];
    int n = 0, choice, i, found;
    char searchName[50];

    while (1)
    {
        printf("\n===== CONTACT MANAGEMENT SYSTEM =====\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        getchar(); // Clear input buffer

        switch (choice)
        {
        case 1:
            printf("Enter Name: ");
            fgets(contact[n].name, sizeof(contact[n].name), stdin);
            contact[n].name[strcspn(contact[n].name, "\n")] = '\0';

            printf("Enter Phone Number: ");
            fgets(contact[n].phone, sizeof(contact[n].phone), stdin);
            contact[n].phone[strcspn(contact[n].phone, "\n")] = '\0';

            printf("Enter Email: ");
            fgets(contact[n].email, sizeof(contact[n].email), stdin);
            contact[n].email[strcspn(contact[n].email, "\n")] = '\0';

            n++;
            printf("Contact added successfully!\n");
            break;

        case 2:
            if (n == 0)
            {
                printf("No contacts available.\n");
            }
            else
            {
                printf("\n----- CONTACT LIST -----\n");
                for (i = 0; i < n; i++)
                {
                    printf("\nContact %d\n", i + 1);
                    printf("Name  : %s\n", contact[i].name);
                    printf("Phone : %s\n", contact[i].phone);
                    printf("Email : %s\n", contact[i].email);
                }
            }
            break;

        case 3:
            printf("Enter Name to Search: ");
            fgets(searchName, sizeof(searchName), stdin);
            searchName[strcspn(searchName, "\n")] = '\0';

            found = 0;

            for (i = 0; i < n; i++)
            {
                if (strcmp(contact[i].name, searchName) == 0)
                {
                    printf("\nContact Found!\n");
                    printf("Name  : %s\n", contact[i].name);
                    printf("Phone : %s\n", contact[i].phone);
                    printf("Email : %s\n", contact[i].email);
                    found = 1;
                    break;
                }
            }

            if (!found)
                printf("Contact not found.\n");

            break;

        case 4:
            printf("Enter Name to Delete: ");
            fgets(searchName, sizeof(searchName), stdin);
            searchName[strcspn(searchName, "\n")] = '\0';

            found = 0;

            for (i = 0; i < n; i++)
            {
                if (strcmp(contact[i].name, searchName) == 0)
                {
                    int j;
                    for (j = i; j < n - 1; j++)
                    {
                        contact[j] = contact[j + 1];
                    }
                    n--;
                    found = 1;
                    printf("Contact deleted successfully!\n");
                    break;
                }
            }

            if (!found)
                printf("Contact not found.\n");

            break;

        case 5:
            printf("Thank you for using the Contact Management System.\n");
            return 0;

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}