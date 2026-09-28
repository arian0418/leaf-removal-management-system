# Leaf Removal Management System

A C++ console application for managing leaf removal service projects and employees.

## Features

- Add and list employees
- Automatically assign employee IDs
- Add service projects with customer and address information
- Assign an existing employee to each project
- Update project area and pricing
- Delete projects
- Calculate total service fees
- Validate employee, project, area, and fee data
- Prevent duplicate project IDs
- Display formatted project and employee tables

## Project Structure

```
leaf-removal-management-system/
├── include/
│   ├── LeafRemovalEmployee.h
│   └── LeafRemovalProject.h
├── src/
│   ├── LeafRemovalEmployee.cpp
│   ├── LeafRemovalProject.cpp
│   └── main.cpp
├── .gitignore
└── README.md
```

## Build

```bash
g++ -std=c++17 -Iinclude src/main.cpp src/LeafRemovalProject.cpp src/LeafRemovalEmployee.cpp -o leaf-removal
```

Run on macOS/Linux with `./leaf-removal` or on Windows with `leaf-removal.exe`.

## Concepts Demonstrated

Programming with objects, classes and encapsulation, header/source separation, static class members, vectors, object relationships, CRUD operations, input validation, and formatted console output.

## About

This project models a small service business where employees can be assigned to customer projects. Each project stores its area and fee per square yard and calculates the total service charge.
