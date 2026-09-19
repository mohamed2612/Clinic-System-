#include <stdio.h>
#include <string.h>
#include "STD.h"
#include "Patient_interface.h"

int main()
{
    u32 mode, choice;
    struct Patient *head = NULL;
    struct Slots slot[5];
    Slot_Inti(slot);

    while (1)
    {
        printf("=========Clinic System=========\n");
        printf("1. Admin\n");
        printf("2. User\n");
        printf("3. Exit the Program\n");
        printf("Enter the Mode: ");
        scanf("%d", &mode);

        switch (mode)
        {
        case 1:
            if (Check_Password() == 0)
            {
                printf("You failed 3 times\n");
                break;
            }

            while (1)
            {
                printf("=========Admin Mode=========\n");
                printf("1. Add New Patient\n");
                printf("2. Edit Patient recod\n");
                printf("3. Reserve a slot with the doctor\n");
                printf("4. Cancel reservation\n");
                printf("5. Back\n");
                printf("Enter the Choice: ");
                scanf("%d", &choice);

                switch (choice)
                {
                case 1:
                    Add_Patient(&head);
                    break;

                case 2:
                    Edit_Patient(head);
                    break;

                case 3:
                    printf("Slot 1: 2pm to 2:30pm\n");
                    printf("Slot 2: 2:30pm to 3pm\n");
                    printf("Slot 3: 3pm to 3:30pm\n");
                    printf("Slot 4: 3:30pm to 4pm\n");
                    printf("Slot 5: 4pm to 4:30pm\n");
                    Reserve_Slot(slot, head);
                    break;

                case 4:
                    Cancle_Slot(slot, head);
                    break;

                case 5:
                    break;

                default:
                    printf("Invalid Choice\n");
                    break;
                }

                if (choice == 5)
                    break;
            }
            break;

        case 2:
            while (1)
            {
                printf("=========User Mode=========\n");
                printf("1. View Patient\n");
                printf("2. View today\'s reservations\n");
                printf("3. Back\n");
                printf("Enter the Choice: ");
                scanf("%d", &choice);
                switch (choice)
                {
                case 1:
                {
                    u32 id;
                    printf("Enter the ID: ");
                    scanf("%d", &id);
                    struct Patient *patient = Search_patient(id, head);
                    if (patient == NULL)
                    {
                        printf("ID does not exist\n");
                    }
                    else
                    {
                        Display_Patient(patient);
                    }
                    break;
                }

                case 2:
                {
                    printf("Slot 1: 2pm to 2:30pm\n");
                    printf("Slot 2: 2:30pm to 3pm\n");
                    printf("Slot 3: 3pm to 3:30pm\n");
                    printf("Slot 4: 3:30pm to 4pm\n");
                    printf("Slot 5: 4pm to 4:30pm\n");
                    Display_Reservations(slot, head);
                    break;
                }

                case 3:
                    break;
                }

                if (choice == 3)
                    break;
            }
            break;

        case 3:
            printf("Bye\n");
            Delete_Patient(&head);
            return 0;

        default:
            printf("Invalid Choise\n");
            break;
        }
    }

    return 0;
}