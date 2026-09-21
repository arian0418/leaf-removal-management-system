#ifndef LEAF_REMOVAL_EMPLOYEE_H
#define LEAF_REMOVAL_EMPLOYEE_H

#include <string>

class LeafRemovalEmployee {
private:
    int employeeID;
    std::string name;
    double wage;
    static int nextEmployeeID;

public:
    LeafRemovalEmployee();
    LeafRemovalEmployee(const std::string& name, double wage);

    int getEmployeeID() const;
    const std::string& getName() const;
    double getWage() const;

    bool setName(const std::string& name);
    bool setWage(double wage);
};

#endif
