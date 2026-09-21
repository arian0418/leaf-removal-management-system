#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

#include "LeafRemovalEmployee.h"
#include "LeafRemovalProject.h"

int employeeIndex(const std::vector<LeafRemovalEmployee>& employees, int id) {
    for (std::size_t i = 0; i < employees.size(); ++i)
        if (employees[i].getEmployeeID() == id) return static_cast<int>(i);
    return -1;
}

int projectIndex(const std::vector<LeafRemovalProject>& projects, int id) {
    for (std::size_t i = 0; i < projects.size(); ++i)
        if (projects[i].getProjectID() == id) return static_cast<int>(i);
    return -1;
}

void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int readInt(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) return value;
        std::cout << "Invalid number. Try again.\n";
        clearInput();
    }
}

double readDouble(const std::string& prompt) {
    double value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) return value;
        std::cout << "Invalid number. Try again.\n";
        clearInput();
    }
}

void listEmployees(const std::vector<LeafRemovalEmployee>& employees) {
    if (employees.empty()) {
        std::cout << "There are currently no employees.\n";
        return;
    }

    std::cout << "\nEmployees\n";
    std::cout << std::left << std::setw(8) << "EID"
              << std::setw(22) << "Name"
              << std::right << std::setw(12) << "Wage ($)\n";

    for (const auto& employee : employees)
        std::cout << std::left << std::setw(8) << employee.getEmployeeID()
                  << std::setw(22) << employee.getName()
                  << std::right << std::fixed << std::setprecision(2)
                  << std::setw(12) << employee.getWage() << '\n';
}

void listProjects(const std::vector<LeafRemovalProject>& projects) {
    if (projects.empty()) {
        std::cout << "There are currently no projects.\n";
        return;
    }

    std::cout << "\nProjects\n";
    std::cout << std::left << std::setw(7) << "PID"
              << std::setw(22) << "Customer"
              << std::setw(32) << "Address"
              << std::right << std::setw(12) << "Area"
              << std::setw(12) << "Fee"
              << std::setw(14) << "Total"
              << std::setw(8) << "EID" << '\n';

    for (const auto& project : projects)
        std::cout << std::left << std::setw(7) << project.getProjectID()
                  << std::setw(22) << project.getCustomer()
                  << std::setw(32) << project.getAddress()
                  << std::right << std::fixed << std::setprecision(2)
                  << std::setw(12) << project.getArea()
                  << std::setw(12) << project.getFeePerSquareYard()
                  << std::setw(14) << project.totalFee()
                  << std::setw(8) << project.getEmployeeID() << '\n';
}

void addEmployee(std::vector<LeafRemovalEmployee>& employees) {
    clearInput();
    std::string name;
    std::cout << "Enter employee name: ";
    std::getline(std::cin, name);

    double wage = readDouble("Enter hourly wage: ");
    LeafRemovalEmployee employee;
    if (!employee.setName(name) || !employee.setWage(wage)) {
        std::cout << "Employee was not added. Name must be 1-20 characters and wage must be non-negative.\n";
        return;
    }

    employees.push_back(employee);
    std::cout << "Employee added with EID " << employee.getEmployeeID() << ".\n";
}

void addProject(std::vector<LeafRemovalProject>& projects,
                const std::vector<LeafRemovalEmployee>& employees) {
    if (employees.empty()) {
        std::cout << "Add an employee before creating a project.\n";
        return;
    }

    int pid = readInt("Enter project ID: ");
    if (projectIndex(projects, pid) != -1) {
        std::cout << "That project ID already exists.\n";
        return;
    }

    clearInput();
    std::string customer, address;
    std::cout << "Enter customer name: ";
    std::getline(std::cin, customer);
    std::cout << "Enter customer address: ";
    std::getline(std::cin, address);

    double area = readDouble("Enter project area (0-5000 sq yd): ");
    double fee = readDouble("Enter fee per sq yd (0-5): ");
    int eid = readInt("Enter employee ID to assign: ");

    if (employeeIndex(employees, eid) == -1) {
        std::cout << "Employee ID not found.\n";
        return;
    }

    LeafRemovalProject project;
    if (!project.setCustomer(customer) || !project.setAddress(address) ||
        !project.setArea(area) || !project.setFeePerSquareYard(fee)) {
        std::cout << "Project was not added because one or more values are invalid.\n";
        return;
    }

    project.setProjectID(pid);
    project.setEmployeeID(eid);
    projects.push_back(project);
    std::cout << "Project " << pid << " added.\n";
}

void changeProject(std::vector<LeafRemovalProject>& projects) {
    int pid = readInt("Enter project ID to change: ");
    int index = projectIndex(projects, pid);
    if (index == -1) {
        std::cout << "Project not found.\n";
        return;
    }

    double area = readDouble("Enter new area (0-5000 sq yd): ");
    double fee = readDouble("Enter new fee per sq yd (0-5): ");

    if (!projects[index].setArea(area) ||
        !projects[index].setFeePerSquareYard(fee)) {
        std::cout << "Project was not changed because a value is outside the allowed range.\n";
        return;
    }

    std::cout << "Project " << pid << " updated.\n";
}

void deleteProject(std::vector<LeafRemovalProject>& projects) {
    int pid = readInt("Enter project ID to delete: ");
    int index = projectIndex(projects, pid);
    if (index == -1) {
        std::cout << "Project not found.\n";
        return;
    }

    projects.erase(projects.begin() + index);
    std::cout << "Project " << pid << " deleted.\n";
}

int menu() {
    std::cout << "\nLeaf Removal Management System\n"
              << "1 - Add project\n"
              << "2 - Change project\n"
              << "3 - Delete project\n"
              << "4 - List projects\n"
              << "5 - Add employee\n"
              << "6 - List employees\n"
              << "0 - Exit\n";
    return readInt("Option: ");
}

int main() {
    std::vector<LeafRemovalEmployee> employees{
        LeafRemovalEmployee("Alice", 20.00),
        LeafRemovalEmployee("Bob", 18.50)
    };

    std::vector<LeafRemovalProject> projects{
        LeafRemovalProject(702, "Wilson", "127 Main", 1100, 4.50, employees[0].getEmployeeID()),
        LeafRemovalProject(701, "Rubble", "89 Rock", 1200, 3.00, employees[1].getEmployeeID()),
        LeafRemovalProject(703, "Stanley", "1100 Elm", 450, 4.75, employees[0].getEmployeeID())
    };

    std::cout << "Welcome to the Leaf Removal Management System\n";

    int option;
    while ((option = menu()) != 0) {
        switch (option) {
            case 1: addProject(projects, employees); break;
            case 2: changeProject(projects); break;
            case 3: deleteProject(projects); break;
            case 4: listProjects(projects); break;
            case 5: addEmployee(employees); break;
            case 6: listEmployees(employees); break;
            default: std::cout << "Unknown option.\n";
        }
    }

    std::cout << "Goodbye.\n";
}
