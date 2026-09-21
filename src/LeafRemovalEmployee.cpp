#include "LeafRemovalEmployee.h"

int LeafRemovalEmployee::nextEmployeeID = 700;

LeafRemovalEmployee::LeafRemovalEmployee()
    : employeeID(++nextEmployeeID), name("(not set)"), wage(0.0) {}

LeafRemovalEmployee::LeafRemovalEmployee(const std::string& name, double wage)
    : employeeID(++nextEmployeeID), name("(not set)"), wage(0.0) {
    setName(name);
    setWage(wage);
}

int LeafRemovalEmployee::getEmployeeID() const { return employeeID; }
const std::string& LeafRemovalEmployee::getName() const { return name; }
double LeafRemovalEmployee::getWage() const { return wage; }

bool LeafRemovalEmployee::setName(const std::string& value) {
    if (value.empty() || value.size() > 20) return false;
    name = value;
    return true;
}

bool LeafRemovalEmployee::setWage(double value) {
    if (value < 0.0) return false;
    wage = value;
    return true;
}
