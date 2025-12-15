#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include <sstream>
#include <algorithm>

class Building {
protected:
    std::string name;
    int floors;
    double area;
    std::vector<std::string> owners;

public:
    Building(const std::string& name = "", int floors = 0, double area = 0.0);
    virtual ~Building() = default;

    std::string getName() const { return name; }
    int getFloors() const { return floors; }
    double getArea() const { return area; }
    std::vector<std::string> getOwners() const { return owners; }

    void setName(const std::string& name) { this->name = name; }
    void setFloors(int floors) { this->floors = floors; }
    void setArea(double area) { this->area = area; }
    void addOwner(const std::string& owner);
    void setOwners(const std::vector<std::string>& owners);

    virtual void display() const;
    virtual std::string toString() const;
    virtual void fromString(const std::string& data);
    virtual void saveToFile(std::ofstream& file) const;
    virtual void loadFromFile(std::ifstream& file);

    static std::unique_ptr<Building> createFromString(const std::string& data);
};

class ResidentialBuilding : public Building {
private:
    int apartmentsCount;
    double averageApartmentArea;

public:
    ResidentialBuilding(const std::string& name = "", int floors = 0,
        double area = 0.0, int apartmentsCount = 0,
        double averageApartmentArea = 0.0);

    int getApartmentsCount() const { return apartmentsCount; }
    double getAverageApartmentArea() const { return averageApartmentArea; }

    void setApartmentsCount(int count) { apartmentsCount = count; }
    void setAverageApartmentArea(double area) { averageApartmentArea = area; }

    void display() const override;
    std::string toString() const override;
    void fromString(const std::string& data) override;
    void saveToFile(std::ofstream& file) const override;
    void loadFromFile(std::ifstream& file) override;
};

class OfficeBuilding : public Building {
private:
    int officesCount;
    double averageOfficeArea;

public:
    OfficeBuilding(const std::string& name = "", int floors = 0,
        double area = 0.0, int officesCount = 0,
        double averageOfficeArea = 0.0);

    int getOfficesCount() const { return officesCount; }
    double getAverageOfficeArea() const { return averageOfficeArea; }

    void setOfficesCount(int count) { officesCount = count; }
    void setAverageOfficeArea(double area) { averageOfficeArea = area; }

    void display() const override;
    std::string toString() const override;
    void fromString(const std::string& data) override;
    void saveToFile(std::ofstream& file) const override;
    void loadFromFile(std::ifstream& file) override;
};