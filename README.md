# 📒 Address Book CLI Application

A command-line based **Address Book Application** written in C, designed to store, manage, and search contact information efficiently.

---

## 📌 Features

- Add new contacts with name, phone number, and email ID
- Edit existing contact details
- Delete contacts by name, number, or email
- Sort contacts by name, number, or email (ascending/descending)
- Search contacts with substring matching
- File persistence for saving/loading contacts
- Input validation and uniqueness enforcement

---

## 🗂️ Project Structure

```
AddressBook-NewDesign/
├── contact.c         # Functions for creating, editing, deleting, and validating contacts
├── contact.h         # Header for contact structure and declarations
├── file.c            # Handles file operations (load/save contacts)
├── file.h            # Header for file handling functions
├── populate.c        # (Optional) Functions to populate sample data
├── populate.h        # Header for populate utilities
├── main.c            # Entry point of the application
├── contacts.txt      # Stores contact data in plain text
└── a.out             # Compiled binary (can be deleted before pushing to GitHub)
```

---

## 🛠️ Installation & Compilation

### 🔧 Prerequisites
Ensure you have GCC installed on your system. On Linux:

```bash
sudo apt update
sudo apt install build-essential
```

### ⚙️ Compile

```bash
gcc main.c contact.c file.c populate.c -o addressbook
```

### ▶️ Run

```bash
./addressbook
```

---

## 🧪 Sample Output

```txt
Search by:
1. Name.
2. Mobile Number.
3. Email ID.
Enter the option : 1
Enter the Name : John
---1 Match Found---
John   9876543210   john@example.com
```

---

## 🚀 Future Enhancements

- GUI-based version (e.g., using C++ with Qt)
- Encryption for contact storage
- Integration with databases (SQLite, MySQL)

---

## 👤 Author

Developed by an Engineering Student as part of a course project 💡  
Feel free to fork, modify, and enhance!

---

## 📄 License

This project is open-source and available under the [MIT License](LICENSE).
