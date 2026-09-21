#ifndef LEAF_REMOVAL_PROJECT_H
#define LEAF_REMOVAL_PROJECT_H

#include <string>

class LeafRemovalProject {
private:
    int projectID;
    int employeeID;
    std::string customer;
    std::string address;
    double area;
    double feePerSquareYard;

public:
    LeafRemovalProject();
    LeafRemovalProject(int projectID, const std::string& customer,
                       const std::string& address, double area,
                       double feePerSquareYard, int employeeID);

    int getProjectID() const;
    int getEmployeeID() const;
    const std::string& getCustomer() const;
    const std::string& getAddress() const;
    double getArea() const;
    double getFeePerSquareYard() const;
    double totalFee() const;

    void setProjectID(int projectID);
    void setEmployeeID(int employeeID);
    bool setCustomer(const std::string& customer);
    bool setAddress(const std::string& address);
    bool setArea(double area);
    bool setFeePerSquareYard(double fee);
};

#endif
