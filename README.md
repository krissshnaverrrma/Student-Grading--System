# C Student Grading System

A robust, console-based utility implemented in C for managing and tracking student records, grades, and academic performance. This project serves as an excellent demonstration of intermediate C concepts, including dynamic data organization using Arrays of Structs, modular programming across multiple files, and essential data persistence using File I/O.

## 🚀 Live Preview

![Student-Grading-System.](/assets/grading_system_preview.jpg)

***

## ✨ Features

* **Data Persistence:** Student records are saved to and loaded from a local file (`students.dat`) upon startup and exit, ensuring data integrity and retention between program sessions.
* **Structured Records:** Utilizes the C `struct` data type to cleanly organize student data, including ID, name, and individual subject grades.
* **Automated Metrics:** Automatically calculates the total marks and average grade for each student record upon creation.
* **Modular Design:** The system is built across three primary source files (`main.c`, `student_data.c`, and `file_handler.c`) and a centralized header (`student.h`) for maintainability and professional structure.
* **Search Functionality:** Provides a simple function to search and retrieve a student's performance details using their unique Student ID.

## 📁 Project Structure

The project adheres to a professional C file hierarchy for clean compilation and maintenance:

Student-Grading-System/ ├── bin/ # Compiled executable and object files (excluded by .gitignore) ├── assets/ # Directory for screenshots and documentation images ├── include/ │ └── student.h # Header: Struct definitions and function prototypes ├── src/ │ ├── main.c # Main program loop and user interface (UI) │ ├── student_data.c # Implementation of logic (add, calculate, display, search) │ └── file_handler.c # Implementation of File I/O (save and load) ├── Makefile # Script for compilation using GCC └── README.md # Project documentation


## 🛠️ Build and Run Instructions

This project requires the **GCC (GNU Compiler Collection)** and the `make` utility to be installed on your system.

1.  **Clone the Repository:**
    ```bash
    git clone [YOUR_REPOSITORY_URL_HERE]
    cd Student_Grading_System
    ```

2.  **Compile the Code:**
    Use the provided `Makefile` to compile all source files and link them into the executable:

    ```bash
    make all
    ```
    *(The executable `grading_system` will be placed in the `bin/` directory.)*

3.  **Execute the Program:**
    Start the application:

    ```bash
    ./bin/grading_system
    ```

4.  **Clean Up:** To remove the compiled binaries and object files:
    ```bash
    make clean
    ```