#include "LeafRemovalProject.h"

LeafRemovalProject::LeafRemovalProject()
    : projectID(0), employeeID(0), customer("(not set)"),
      address("(not set)"), area(0.0), feePerSquareYard(0.0) {}

LeafRemovalProject::LeafRemovalProject(
    int projectID, const std::string& customer, const std::string& address,
    double area, double feePerSquareYard, int employeeID)
    : LeafRemovalProject() {
    setProjectID(projectID);
    setCustomer(customer);
    setAddress(address);
    setArea(area);
    setFeePerSquareYard(feePerSquareYard);
    setEmployeeID(employeeID);
}

int LeafRemovalProject::getProjectID() const { return projectID; }
int LeafRemovalProject::getEmployeeID() const { return employeeID; }
const std::string& LeafRemovalProject::getCustomer() const { return customer; }
const std::string& LeafRemovalProject::getAddress() const { return address; }
double LeafRemovalProject::getArea() const { return area; }
double LeafRemovalProject::getFeePerSquareYard() const { return feePerSquareYard; }
double LeafRemovalProject::totalFee() const { return area * feePerSquareYard; }

void LeafRemovalProject::setProjectID(int value) { projectID = value; }
void LeafRemovalProject::setEmployeeID(int value) { employeeID = value; }

bool LeafRemovalProject::setCustomer(const std::string& value) {
    if (value.empty() || value.size() > 20) return false;
    customer = value;
    return true;
}

bool LeafRemovalProject::setAddress(const std::string& value) {
    if (value.empty() || value.size() > 30) return false;
    address = value;
    return true;
}

bool LeafRemovalProject::setArea(double value) {
    if (value < 0.0 || value > 5000.0) return false;
    area = value;
    return true;
}

bool LeafRemovalProject::setFeePerSquareYard(double value) {
    if (value < 0.0 || value > 5.0) return false;
    feePerSquareYard = value;
    return true;
}
