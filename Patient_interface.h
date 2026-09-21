/**
 * @file Patient_interface.h
 * @author Mohamed Hesham
 * @email m.hesham2612@gmail.com
 * @linkedin https://www.linkedin.com/in/mohamed-hesham-a0809132b
 * @brief Header file containing data structures, enums, and function prototypes for the Clinic System.
 * @version 1.0
 * @date 2026-08-29
 */


#ifndef PATIENT_INTERFACE_H
#define PATIENT_INTERFACE_H

#define PASSWORD 1234  ///< Admin password for system access


/**
 * @brief Enum representing the gender of the patient.
 */
enum Gender
{
    Male,  ///< Patient is Male
    Female ///< Patient is Female
};

/**
 * @brief Structure representing a patient record in the linked list.
 */
struct Patient
{
    u8 Name[25];                ///< Patient name
    u32 ID;                     ///< Unique patient ID
    u32 Age;                    ///< Patient age
    enum Gender gender;         ///< Patient gender
    struct Patient *Next;       ///< Pointer to the next patient in the linked list
};


/**
 * @brief Structure representing reservation slots with the doctor.
 */
struct Slots
{
    u32 PatientId;      ///< ID of the patient who reserved the slot
    u8 reserve;         ///< Reservation status: 0 => available, 1 => reserved
};


/**
 * @brief Checks the admin password with a maximum of 3 attempts.
 * @return u8 Returns 1 if successful, 0 if failed 3 times.
 */
u8 Check_Password();

/**
 * @brief Adds a new patient to the linked list.
 * @param head Double pointer to the head of the patient linked list.
 */
void Add_Patient(struct Patient **head);

/**
 * @brief Searches for a patient by their ID.
 * @param id The ID of the patient to search for.
 * @param head Pointer to the head of the patient linked list.
 * @return struct Patient* Pointer to the patient if found, NULL otherwise.
 */
struct Patient *Search_patient(u8 id, struct Patient *head);

/**
 * @brief Edits an existing patient's record.
 * @param head Pointer to the head of the patient linked list.
 */
void Edit_Patient(struct Patient *head);

/**
 * @brief Displays the details of a specific patient.
 * @param patient Pointer to the patient structure to display.
 */
void Display_Patient(struct Patient *patient);

/**
 * @brief Deletes all patient records and frees memory.
 * @param head Double pointer to the head of the patient linked list.
 */
void Delete_Patient(struct Patient **head);

/**
 * @brief Initializes all reservation slots as available.
 * @param slot Array of slots to initialize.
 */
void Slot_Inti(struct Slots slot[]);

/**
 * @brief Displays all available reservation slots.
 * @param slot Array of slots.
 */
void Display_Slots_Avaliable(struct Slots slot[]);

/**
 * @brief Reserves a slot for a patient.
 * @param slot Array of slots.
 * @param head Pointer to the head of the patient linked list.
 */
void Reserve_Slot(struct Slots slot[], struct Patient *head);

/**
 * @brief Cancels an existing slot reservation for a patient.
 * @param slot Array of slots.
 * @param head Pointer to the head of the patient linked list.
 */
void Cancle_Slot(struct Slots slot[], struct Patient *head);

/**
 * @brief Displays the reservation details for a specific patient.
 * @param slot Array of slots.
 * @param head Pointer to the head of the patient linked list.
 */
void Display_Reservations(struct Slots slot[], struct Patient *head);
#endif