#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "STD.h"
#include "Patient_interface.h"

u8 Check_Password()
{
    u32 password, counter = 0;
    while (counter < 3)
    {
        printf("Enter the password: ");
        scanf("%d", &password);
        if (password == PASSWORD)
        {
            printf("Correct\n");
            return 1;
        }
        printf("Wrong, Try Again\n");
        counter++;
    }
    return 0;
}

void Add_Patient(struct Patient **head)
{
    u32 id;
    printf("Enter the ID: ");
    scanf("%d", &id);
    if (Search_patient(id, *head) != NULL)
    {
        printf("ID already exists\n");
        return;
    }
    struct Patient *temp = (struct Patient *)malloc(sizeof(struct Patient));
    temp->Next = NULL;
    temp->ID = id;
    printf("Enter the Name: ");
    scanf("%s", temp->Name);
    printf("Enter the Age: ");
    scanf("%d", &temp->Age);
    printf("Enter the Gender(0. Male, 1. Female): ");
    scanf("%d", (u8 *)&temp->gender);
    if (*head == NULL)
    {
        *head = temp;
        return;
    }
    struct Patient *last = *head;
    while ((last)->Next != NULL)
    {
        last = (last)->Next;
    }
    (last)->Next = temp;
}

struct Patient *Search_patient(u8 id, struct Patient *head)
{
    struct Patient *temp = head;
    while (temp != NULL)
    {
        if (temp->ID == id)
        {
            return temp;
        }
        temp = temp->Next;
    }
    return NULL;
}

void Edit_Patient(struct Patient *head)
{
    u32 id;
    printf("Enter the ID: ");
    scanf("%d", &id);
    struct Patient *patient = Search_patient(id, head);
    if (patient == NULL)
    {
        printf("ID Does not exists\n");
        return;
    }
    printf("Enter new name: ");
    scanf("%s", patient->Name);
    printf("Enter new age: ");
    scanf("%d", &patient->Age);
    printf("Enter new gender (0. Male, 1. Female): ");
    scanf("%d", (u32 *)&patient->gender);
    printf("Done.\n");
}

void Display_Patient(struct Patient *patient)
{
    printf("ID: %d\n", patient->ID);
    printf("Name: %s\n", patient->Name);
    printf("Age: %d\n", patient->Age);
    if (patient->gender == Male)
    {
        printf("Gender: Male\n");
    }
    else
    {
        printf("Gender: Female\n");
    }
}

void Delete_Patient(struct Patient **head)
{
    struct Patient *temp = *head;
    struct Patient *deleteptr = NULL;
    *head = NULL;
    while (temp != NULL)
    {
        deleteptr = temp;
        temp = temp->Next;
        free(deleteptr);
    }

    printf("Done\n");
}

void Slot_Inti(struct Slots slot[])
{
    for (u32 i = 0; i < 5; i++)
    {
        slot[i].reserve = 0;
    }
}

void Display_Slots_Avaliable(struct Slots slot[])
{
    printf("Avaliable Slots:\n");
    for (u32 i = 0; i < 5; i++)
    {
        if (slot[i].reserve == 0)
        {
            printf("%d. slot %d\n", i + 1, i + 1);
        }
    }
}

void Reserve_Slot(struct Slots slot[], struct Patient *head)
{
    u32 id, choice;
    printf("Enter the ID: ");
    scanf("%d", &id);
    if (Search_patient(id, head) == NULL)
    {
        printf("ID does not exist\n");
        return;
    }
    Display_Slots_Avaliable(slot);
    printf("Choose the Slot :");
    scanf("%d", &choice);
    if (choice < 1 || choice > 5)
    {
        printf("Invalid slot\n");
        return;
    }
    if (slot[choice - 1].reserve == 1)
    {
        printf("Slot already reserved\n");
        return;
    }
    slot[choice - 1].PatientId = id;
    slot[choice - 1].reserve = 1;
    printf("done\n");
}

void Cancle_Slot(struct Slots slot[], struct Patient *head)
{
    u32 id;
    printf("Enter the ID: ");
    scanf("%d", &id);
    if (Search_patient(id, head) == NULL)
    {
        printf("This ID does not exist\n");
        return;
    }
    for (u32 i = 0; i < 5; i++)
    {
        if (slot[i].reserve == 1 && slot[i].PatientId == id)
        {
            slot[i].reserve = 0;
            printf("Done\n");
            return;
        }
    }
    printf("This ID does not reserved any slot\n");
}

void Display_Reservations(struct Slots slot[], struct Patient *head)
{
    u32 id;
    printf("Enter the ID: ");
    scanf("%d", &id);
    if (Search_patient(id, head) == NULL)
    {
        printf("This ID does not exist\n");
        return;
    }
    for (u32 i = 0; i < 5; i++)
    {
        if (slot[i].reserve == 1 && slot[i].PatientId == id)
        {
            printf("Your Slot is slot %d\n", i + 1);
            return;
        }
    }
    printf("You do not have a Slot\n");
}