# 🏨 Hostel Management System (C Program)

A simple console-based **Hostel Management System** developed in C using file handling.  
This project performs basic **CRUD operations (Create, Read, Search, Delete)** for managing hostel student records.

---

## 📌 Project Description

This system allows the user to:

- Add new student records
- View all student records
- Search for a student by ID
- Delete a student record
- Store data permanently using file handling

All records are stored in a binary file named `hostel.txt`.

---

## 🛠️ Technologies Used

- **Language:** C  

### Concepts Used

- Structures
- File Handling (Binary Files)
- Functions
- Switch Case
- Looping (while loop)

---

## 📂 Project Structure

Hostel-Management-System/
│
├── hostel_management.c
├── hostel.txt (auto-generated after adding records)
└── README.md

---

## ⚙️ Features Implemented

### 1️⃣ Add Student

**Takes input:**
- Student ID
- Name
- Room Number
- Fees

Stores data in `hostel.txt` using binary file mode.

---

### 2️⃣ View Students

Displays all stored student records in tabular format.

---

### 3️⃣ Search Student

- Searches a student record using Student ID
- Displays student details if found

---

### 4️⃣ Delete Student

- Deletes a student record by ID
- Uses a temporary file (`temp.txt`) to remove the selected record

---

## 💾 Data Storage

- Records are stored in binary format
- File used: `hostel.txt`
- Temporary file used during deletion: `temp.txt`
