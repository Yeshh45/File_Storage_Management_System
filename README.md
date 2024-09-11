# File Storage Management System (C Application)

## Project Description

The **File Storage Management System** is an enterprise-level C application designed to handle large-scale file and directory operations efficiently. This system allows users to create, retrieve, and delete files while ensuring optimal storage space utilization and secure file handling. It supports real-time file updates, version control, and concurrent access by multiple users. The project leverages advanced data structures like binary trees and hash tables for efficient organization, and POSIX threads for managing multiple simultaneous file operations.

## Features

- **Create, Read, Delete Files**: Basic file management operations.
- **Concurrency**: Multiple users can access the system concurrently, thanks to POSIX Threads.
- **Optimized Data Structures**: Efficient storage using binary trees and hash tables.
- **Memory Management**: Careful use of dynamic memory allocation and error handling.
- **Thread Safety**: Mutex locks ensure safe concurrent access to shared resources.

## Tech Stack

- **Programming Language**: C
- **Data Structures**: Binary Trees, Hash Tables
- **Concurrency**: POSIX Threads
- **File I/O**: C Standard Library Functions (`fopen`, `fwrite`, `fread`, etc.)
- **System Calls**: Linux System Calls
- **Build Tools**: Makefile

## Project Structure

```bash
File_Storage_Management_System/
│
├── src/                # Source files
│   ├── file_storage.c  # Main code for the file storage system
│   ├── utils.c         # Utility functions (e.g., data structures)
│   ├── utils.h         # Header file for utility functions
│
├── Makefile            # For compiling the project
└── README.md           # Documentation for your project
```

## Installation and Setup

### Using Windows Subsystem for Linux (WSL)

This project can be run using **Windows Subsystem for Linux (WSL)**, which allows you to run a Linux environment directly on Windows. Follow the steps below to set up WSL, build, and run the project.

### Step 1: Install WSL and Set Up the Linux Environment

1. **Install WSL** (if not already installed):
   - Open **PowerShell** as Administrator and run:
     ```bash
     wsl --install
     ```
   - This command installs WSL and the default Linux distribution (typically Ubuntu).

2. **Open Ubuntu (WSL)**:
   - After installation, launch Ubuntu from the Start menu.

3. **Install Build Tools**:
   - Once you're in the WSL terminal, you need to install build-essential tools (including `gcc` and `make`):
     ```bash
     sudo apt update
     sudo apt install build-essential
     ```

### Step 2: Clone the Repository

To clone the repository and navigate to the project directory:

```bash
git clone https://github.com/Yeshh45/File_Storage_Management_System.git
cd File_Storage_Management_System
```

### Step 3: Build the Project Using `Makefile`

Now that you're in the project directory, build the project using the provided `Makefile`:

```bash
make
```

This will compile the source files and create an executable named `file_storage`.

### Step 4: Run the Application

After the project has been compiled, run the application with the following command:

```bash
./file_storage
```

If everything is set up correctly, the program will execute and display output based on file operations (e.g., creating, reading, and deleting files).

## Usage

### Creating a File

You can create a file by calling the `create_file` function in the program:

```c
create_file("example.txt", "This is a sample file.");
```

### Reading a File

To retrieve the content of an existing file, use the `read_file` function:

```c
read_file("example.txt");
```

### Deleting a File

To delete a file, call the `delete_file` function:

```c
delete_file("example.txt");
```

### Thread Safety

This system ensures that file operations are thread-safe, allowing multiple users to perform file operations concurrently through the use of POSIX threads.

## Future Enhancements

- **Version Control**: Add support for versioning of files.
- **Directory Management**: Expand the system to manage directories in addition to individual files.
- **Persistent Storage**: Implement persistent storage by saving files on disk.
- **File Encryption**: Secure file content using encryption methods for enhanced security.

## Contributing

Contributions are welcome! Please fork this repository and create a pull request to contribute new features, optimizations, or bug fixes.
