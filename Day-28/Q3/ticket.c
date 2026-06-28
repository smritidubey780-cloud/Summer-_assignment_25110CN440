#include <stdio.h>
#include <string.h>

struct Ticket
{
    int ticketNo;
    char name[50];
    char destination[50];
    int seatNo;
    int booked;
};

int main()
{
    struct Ticket t;
    int choice;

    t.booked = 0;

    while (1)
    {
        printf("\n===== TICKET BOOKING SYSTEM =====\n");
        printf("1. Book Ticket\n");
        printf("2. View Ticket\n");
        printf("3. Cancel Ticket\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (t.booked)
            {
                printf("A ticket is already booked.\n");
            }
            else
            {
                printf("Enter Ticket Number: ");
                scanf("%d", &t.ticketNo);

                getchar(); // Clear input buffer

                printf("Enter Passenger Name: ");
                fgets(t.name, sizeof(t.name), stdin);
                t.name[strcspn(t.name, "\n")] = '\0';

                printf("Enter Destination: ");
                fgets(t.destination, sizeof(t.destination), stdin);
                t.destination[strcspn(t.destination, "\n")] = '\0';

                printf("Enter Seat Number: ");
                scanf("%d", &t.seatNo);

                t.booked = 1;

                printf("Ticket booked successfully!\n");
            }
            break;

        case 2:
            if (!t.booked)
            {
                printf("No ticket booked.\n");
            }
            else
            {
                printf("\n===== TICKET DETAILS =====\n");
                printf("Ticket Number : %d\n", t.ticketNo);
                printf("Passenger Name: %s\n", t.name);
                printf("Destination   : %s\n", t.destination);
                printf("Seat Number   : %d\n", t.seatNo);
                printf("Status        : Booked\n");
            }
            break;

        case 3:
            if (!t.booked)
            {
                printf("No ticket to cancel.\n");
            }
            else
            {
                t.booked = 0;
                printf("Ticket cancelled successfully.\n");
            }
            break;

        case 4:
            printf("Thank you for using the Ticket Booking System.\n");
            return 0;

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}