# Clinic Management System in C

A modular C-based application for managing clinic operations, patient records, and doctor appointments through a CLI interface.

## Features
- **Authentication**: Admin mode secured with password protection (3 attempts limit).
- **Patient Management**: Add, edit, search, and delete patient records dynamically using Linked Lists.
- **Reservation System**: Reserve, cancel, and display available daily time slots (5 slots/day).
- **Dual Mode**: Separate interfaces for Admin (full access) and User (read-only access).
- **Modular Architecture**: Layered structure using custom data types (`STD.h`) and driver interfaces.

## File Structure
- `main.c`: Program entry point and menu navigation.
- `Patient_program.c`: Implementation of patient management and reservation logic.
- `Patient_interface.h`: Function prototypes and data structures (`Patient`, `Slots`).
- `STD.h`: Standard data type definitions.
