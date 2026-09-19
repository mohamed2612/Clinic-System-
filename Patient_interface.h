#ifndef PATIENT_INTERFACE_H
#define PATIENT_INTERFACE_H

#define PASSWORD 1234

enum Gender
{
    Male,
    Female
};

struct Patient
{
    u8 Name[25];
    u32 ID;
    u32 Age;
    enum Gender gender;
    struct Patient *Next;
};

struct Slots
{
    u32 PatientId;
    u8 reserve; // 0 => avaliable      1 => reserved
};

u8 Check_Password();

void Add_Patient(struct Patient **head);
struct Patient *Search_patient(u8 id, struct Patient *head);
void Edit_Patient(struct Patient *head);
void Display_Patient(struct Patient *patient);
void Delete_Patient(struct Patient **head);

void Slot_Inti(struct Slots slot[]);
void Display_Slots_Avaliable(struct Slots slot[]);
void Reserve_Slot(struct Slots slot[], struct Patient *head);
void Cancle_Slot(struct Slots slot[], struct Patient *head);
void Display_Reservations(struct Slots slot[], struct Patient *head);
#endif