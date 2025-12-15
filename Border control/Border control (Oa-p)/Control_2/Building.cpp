#include "Building.h"

using namespace std;

Building::Building(const std::string& name, int floors, double area)
    : name(name), floors(floors), area(area) {
}

void Building::addOwner(const std::string& owner) {
    owners.push_back(owner);
}

void Building::setOwners(const std::vector<std::string>& owners) {
    this->owners = owners;
}

void Building::display() const {
    cout << "Name: " << name << endl;
    cout << "Floors: " << floors << endl;
    cout << "Total area: " << area << " sq.m" << endl;
    cout << "Owners: ";
    for (size_t i = 0; i < owners.size(); ++i) {
        cout << owners[i];
        if (i < owners.size() - 1) cout << ", ";
    }
    cout << endl;
}

std::string Building::toString() const {
    ostringstream oss;
    oss << name << ";" << floors << ";" << area << ";";
    for (size_t i = 0; i < owners.size(); ++i) {
        oss << owners[i];
        if (i < owners.size() - 1) oss << "|";
    }
    return oss.str();
}

void Building::fromString(const std::string& data) {
    istringstream iss(data);
    string token;

    getline(iss, name, ';');

    getline(iss, token, ';');
    floors = stoi(token);

    getline(iss, token, ';');
    area = stod(token);

    owners.clear();
    string ownersStr;
    getline(iss, ownersStr);
    if (!ownersStr.empty()) {
        istringstream ownersStream(ownersStr);
        string owner;
        while (getline(ownersStream, owner, '|')) {
            owners.push_back(owner);
        }
    }
}

void Building::saveToFile(ofstream& file) const {
    file << toString() << endl;
}

void Building::loadFromFile(ifstream& file) {
    string line;
    if (getline(file, line)) {
        fromString(line);
    }
}

unique_ptr<Building> Building::createFromString(const string& data) {
    istringstream iss(data);
    string type;
    getline(iss, type, ';');

    unique_ptr<Building> building;

    if (type == "Residential") {
        building = make_unique<ResidentialBuilding>();
    }
    else if (type == "Office") {
        building = make_unique<OfficeBuilding>();
    }
    else {
        return nullptr;
    }

    building->fromString(data.substr(data.find(';') + 1));
    return building;
}

ResidentialBuilding::ResidentialBuilding(const std::string& name, int floors,
    double area, int apartmentsCount,
    double averageApartmentArea)
    : Building(name, floors, area), apartmentsCount(apartmentsCount),
    averageApartmentArea(averageApartmentArea) {
}

void ResidentialBuilding::display() const {
    cout << "=== RESIDENTIAL BUILDING ===" << endl;
    Building::display();
    cout << "Apartments count: " << apartmentsCount << endl;
    cout << "Average apartment area: " << averageApartmentArea << " sq.m" << endl;
    cout << "Total residential area: " << apartmentsCount * averageApartmentArea
        << " sq.m" << endl;
}

std::string ResidentialBuilding::toString() const {
    ostringstream oss;
    oss << "Residential;" << Building::toString() << ";"
        << apartmentsCount << "-" << averageApartmentArea;
    return oss.str();
}

void ResidentialBuilding::fromString(const std::string& data) {
    istringstream iss(data);
    string token;

    getline(iss, token, ';');
    name = token;

    getline(iss, token, ';');
    floors = stoi(token);

    getline(iss, token, ';');
    area = stod(token);

    owners.clear();
    string ownersStr;
    getline(iss, ownersStr, ';');
    if (!ownersStr.empty()) {
        istringstream ownersStream(ownersStr);
        string owner;
        while (getline(ownersStream, owner, '|')) {
            owners.push_back(owner);
        }
    }

    string param;
    getline(iss, param);

    size_t dashPos = param.find('-');
    if (dashPos != string::npos) {
        apartmentsCount = stoi(param.substr(0, dashPos));
        averageApartmentArea = stod(param.substr(dashPos + 1));
    }
}

void ResidentialBuilding::saveToFile(ofstream& file) const {
    file << toString() << endl;
}

void ResidentialBuilding::loadFromFile(ifstream& file) {
    string line;
    if (getline(file, line)) {
        fromString(line);
    }
}

OfficeBuilding::OfficeBuilding(const std::string& name, int floors,
    double area, int officesCount,
    double averageOfficeArea)
    : Building(name, floors, area), officesCount(officesCount),
    averageOfficeArea(averageOfficeArea) {
}

void OfficeBuilding::display() const {
    cout << "=== OFFICE BUILDING ===" << endl;
    Building::display();
    cout << "Offices count: " << officesCount << endl;
    cout << "Average office area: " << averageOfficeArea << " sq.m" << endl;
    cout << "Total office area: " << officesCount * averageOfficeArea
        << " sq.m" << endl;
}

std::string OfficeBuilding::toString() const {
    ostringstream oss;
    oss << "Office;" << Building::toString() << ";"
        << officesCount << "-" << averageOfficeArea;
    return oss.str();
}

void OfficeBuilding::fromString(const std::string& data) {
    istringstream iss(data);
    string token;

    getline(iss, token, ';');
    name = token;

    getline(iss, token, ';');
    floors = stoi(token);

    getline(iss, token, ';');
    area = stod(token);

    owners.clear();
    string ownersStr;
    getline(iss, ownersStr, ';');
    if (!ownersStr.empty()) {
        istringstream ownersStream(ownersStr);
        string owner;
        while (getline(ownersStream, owner, '|')) {
            owners.push_back(owner);
        }
    }

    string param;
    getline(iss, param);

    size_t dashPos = param.find('-');
    if (dashPos != string::npos) {
        officesCount = stoi(param.substr(0, dashPos));
        averageOfficeArea = stod(param.substr(dashPos + 1));
    }
}

void OfficeBuilding::saveToFile(ofstream& file) const {
    file << toString() << endl;
}

void OfficeBuilding::loadFromFile(ifstream& file) {
    string line;
    if (getline(file, line)) {
        fromString(line);
    }
}