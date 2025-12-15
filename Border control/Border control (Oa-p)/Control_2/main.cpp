#include "Building.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <memory>
#include <algorithm>
#include <vector>
#include <iterator>
#include <limits>

using namespace std;

void displayMenu() {
    cout << "\n=== MAIN MENU ===" << endl;
    cout << "1. Load data from file" << endl;
    cout << "2. Display all buildings" << endl;
    cout << "3. Search/filter buildings" << endl;
    cout << "4. Sort buildings" << endl;
    cout << "5. Add new building" << endl;
    cout << "6. Edit existing building" << endl;
    cout << "7. Delete building" << endl;
    cout << "8. Save current state to file" << endl;
    cout << "9. Statistics (lambda functions)" << endl;
    cout << "0. Exit" << endl;
    cout << "Select action: ";
}

void loadDataFromFile(list<unique_ptr<Building>>& buildings) {
    string filename;
    cout << "Enter filename (default: city.txt): ";
    getline(cin, filename);
    if (filename.empty()) {
        filename = "city.txt";
    }

    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    buildings.clear();
    string line;
    while (getline(file, line)) {
        auto building = Building::createFromString(line);
        if (building) {
            buildings.push_back(move(building));
        }
    }

    cout << "Data loaded. Loaded " << buildings.size() << " objects." << endl;
}

void displayAllBuildings(const list<unique_ptr<Building>>& buildings) {
    if (buildings.empty()) {
        cout << "Building list is empty." << endl;
        return;
    }

    int counter = 1;
    for (const auto& building : buildings) {
        cout << "\n[" << counter++ << "] ";
        building->display();
        cout << endl;
    }
}

void searchBuildings(const list<unique_ptr<Building>>& buildings) {
    cout << "\n=== SEARCH AND FILTER ===" << endl;
    cout << "1. By name" << endl;
    cout << "2. By minimum floors" << endl;
    cout << "3. By minimum area" << endl;
    cout << "4. By owner" << endl;
    cout << "5. Residential buildings with >100 apartments" << endl;
    cout << "6. Residential buildings with floors > 10" << endl;
    cout << "Select search criteria: ";

    int choice;
    cin >> choice;
    cin.ignore();

    bool found = false;

    switch (choice) {
    case 1: {
        string name;
        cout << "Enter name to search: ";
        getline(cin, name);

        for (const auto& building : buildings) {
            if (building->getName().find(name) != string::npos) {
                building->display();
                found = true;
                cout << endl;
            }
        }
        break;
    }
    case 2: {
        int minFloors;
        cout << "Enter minimum floors: ";
        cin >> minFloors;

        for (const auto& building : buildings) {
            if (building->getFloors() >= minFloors) {
                building->display();
                found = true;
                cout << endl;
            }
        }
        break;
    }
    case 3: {
        double minArea;
        cout << "Enter minimum area: ";
        cin >> minArea;

        for (const auto& building : buildings) {
            if (building->getArea() >= minArea) {
                building->display();
                found = true;
                cout << endl;
            }
        }
        break;
    }
    case 4: {
        string owner;
        cout << "Enter owner name: ";
        getline(cin, owner);

        for (const auto& building : buildings) {
            auto owners = building->getOwners();
            if (find(owners.begin(), owners.end(), owner) != owners.end()) {
                building->display();
                found = true;
                cout << endl;
            }
        }
        break;
    }
    case 5: {
        int count = 0;
        for (const auto& building : buildings) {
            if (auto residential = dynamic_cast<ResidentialBuilding*>(building.get())) {
                if (residential->getApartmentsCount() > 100) {
                    residential->display();
                    count++;
                    found = true;
                    cout << endl;
                }
            }
        }
        cout << "Found " << count << " residential buildings with more than 100 apartments." << endl;
        break;
    }
    case 6: {
        vector<Building*> filtered;

        for (const auto& building : buildings) {
            if (building->getFloors() > 10) {
                if (auto residential = dynamic_cast<ResidentialBuilding*>(building.get())) {
                    filtered.push_back(building.get());
                }
            }
        }

        if (!filtered.empty()) {
            cout << "Found " << filtered.size() << " residential buildings with floors > 10:" << endl;
            for (auto building : filtered) {
                building->display();
                cout << endl;
            }
            found = true;
        }
        break;
    }
    default:
        cout << "Invalid choice!" << endl;
        return;
    }

    if (!found) {
        cout << "No objects found." << endl;
    }
}

void sortBuildings(list<unique_ptr<Building>>& buildings) {
    cout << "\n=== SORTING ===" << endl;
    cout << "1. By area (descending)" << endl;
    cout << "2. By floors (descending)" << endl;
    cout << "3. By area and floors (lambda)" << endl;
    cout << "Select sorting type: ";

    int choice;
    cin >> choice;
    cin.ignore();

    vector<unique_ptr<Building>> tempVector;
    tempVector.reserve(buildings.size());
    while (!buildings.empty()) {
        tempVector.push_back(move(buildings.front()));
        buildings.pop_front();
    }

    switch (choice) {
    case 1:
        sort(tempVector.begin(), tempVector.end(),
            [](const unique_ptr<Building>& a, const unique_ptr<Building>& b) {
                return a->getArea() > b->getArea();
            });
        break;
    case 2:
        sort(tempVector.begin(), tempVector.end(),
            [](const unique_ptr<Building>& a, const unique_ptr<Building>& b) {
                return a->getFloors() > b->getFloors();
            });
        break;
    case 3:
        sort(tempVector.begin(), tempVector.end(),
            [](const unique_ptr<Building>& a, const unique_ptr<Building>& b) {
                if (a->getArea() != b->getArea()) {
                    return a->getArea() > b->getArea();
                }
                return a->getFloors() > b->getFloors();
            });
        cout << "Sorted by area and floors." << endl;
        break;
    default:
        cout << "Invalid choice!" << endl;
        return;
    }

    for (auto& building : tempVector) {
        buildings.push_back(move(building));
    }

    cout << "Sorting completed." << endl;
}

void addNewBuilding(list<unique_ptr<Building>>& buildings) {
    cout << "\n=== ADD NEW BUILDING ===" << endl;
    cout << "1. Residential building" << endl;
    cout << "2. Office building" << endl;
    cout << "Select building type: ";

    int choice;
    cin >> choice;
    cin.ignore();

    string name;
    int floors;
    double area;

    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter floors: ";
    cin >> floors;
    cout << "Enter total area: ";
    cin >> area;
    cin.ignore();

    if (choice == 1) {
        int apartmentsCount;
        double avgArea;
        cout << "Enter apartments count: ";
        cin >> apartmentsCount;
        cout << "Enter average apartment area: ";
        cin >> avgArea;
        cin.ignore();

        auto building = make_unique<ResidentialBuilding>(name, floors, area, apartmentsCount, avgArea);

        cout << "Add owners? (y/n): ";
        char addOwners;
        cin >> addOwners;
        cin.ignore();

        if (addOwners == 'y' || addOwners == 'Y') {
            cout << "Enter owner names separated by comma: ";
            string ownersInput;
            getline(cin, ownersInput);

            istringstream iss(ownersInput);
            string owner;
            while (getline(iss, owner, ',')) {
                owner.erase(0, owner.find_first_not_of(' '));
                owner.erase(owner.find_last_not_of(' ') + 1);
                building->addOwner(owner);
            }
        }

        buildings.push_back(move(building));
        cout << "Residential building added." << endl;

    }
    else if (choice == 2) {
        int officesCount;
        double avgArea;
        cout << "Enter offices count: ";
        cin >> officesCount;
        cout << "Enter average office area: ";
        cin >> avgArea;
        cin.ignore();

        auto building = make_unique<OfficeBuilding>(name, floors, area, officesCount, avgArea);

        cout << "Add owners? (y/n): ";
        char addOwners;
        cin >> addOwners;
        cin.ignore();

        if (addOwners == 'y' || addOwners == 'Y') {
            cout << "Enter owner names separated by comma: ";
            string ownersInput;
            getline(cin, ownersInput);

            istringstream iss(ownersInput);
            string owner;
            while (getline(iss, owner, ',')) {
                owner.erase(0, owner.find_first_not_of(' '));
                owner.erase(owner.find_last_not_of(' ') + 1);
                building->addOwner(owner);
            }
        }

        buildings.push_back(move(building));
        cout << "Office building added." << endl;

    }
    else {
        cout << "Invalid choice!" << endl;
    }
}

void editBuilding(list<unique_ptr<Building>>& buildings) {
    if (buildings.empty()) {
        cout << "Building list is empty." << endl;
        return;
    }

    cout << "\n=== EDIT BUILDING ===" << endl;

    int counter = 1;
    for (const auto& building : buildings) {
        cout << counter++ << ". " << building->getName()
            << " (" << (dynamic_cast<ResidentialBuilding*>(building.get()) ? "Residential" : "Office")
            << ")" << endl;
    }

    cout << "Select building number to edit: ";
    int index;
    cin >> index;
    cin.ignore();

    if (index < 1 || index > buildings.size()) {
        cout << "Invalid number!" << endl;
        return;
    }

    auto it = buildings.begin();
    advance(it, index - 1);
    Building* building = it->get();

    cout << "\nEditing building: " << building->getName() << endl;
    cout << "1. Change floors" << endl;
    cout << "2. Change area" << endl;
    cout << "3. Add owner" << endl;
    cout << "4. Change specific parameters" << endl;
    cout << "Select action: ";

    int choice;
    cin >> choice;
    cin.ignore();

    switch (choice) {
    case 1: {
        int newFloors;
        cout << "Enter new floors: ";
        cin >> newFloors;
        building->setFloors(newFloors);
        cout << "Floors changed." << endl;
        break;
    }
    case 2: {
        double newArea;
        cout << "Enter new area: ";
        cin >> newArea;
        building->setArea(newArea);
        cout << "Area changed." << endl;
        break;
    }
    case 3: {
        string newOwner;
        cout << "Enter new owner name: ";
        getline(cin, newOwner);
        building->addOwner(newOwner);
        cout << "Owner added." << endl;
        break;
    }
    case 4: {
        if (auto residential = dynamic_cast<ResidentialBuilding*>(building)) {
            int newCount;
            double newAvgArea;
            cout << "Enter new apartments count: ";
            cin >> newCount;
            cout << "Enter new average apartment area: ";
            cin >> newAvgArea;
            residential->setApartmentsCount(newCount);
            residential->setAverageApartmentArea(newAvgArea);
            cout << "Residential building parameters changed." << endl;
        }
        else if (auto office = dynamic_cast<OfficeBuilding*>(building)) {
            int newCount;
            double newAvgArea;
            cout << "Enter new offices count: ";
            cin >> newCount;
            cout << "Enter new average office area: ";
            cin >> newAvgArea;
            office->setOfficesCount(newCount);
            office->setAverageOfficeArea(newAvgArea);
            cout << "Office building parameters changed." << endl;
        }
        break;
    }
    default:
        cout << "Invalid choice!" << endl;
    }
}

void deleteBuilding(list<unique_ptr<Building>>& buildings) {
    if (buildings.empty()) {
        cout << "Building list is empty." << endl;
        return;
    }

    cout << "\n=== DELETE BUILDING ===" << endl;

    int counter = 1;
    for (const auto& building : buildings) {
        cout << counter++ << ". " << building->getName() << endl;
    }

    cout << "Select building number to delete: ";
    int index;
    cin >> index;
    cin.ignore();

    if (index < 1 || index > buildings.size()) {
        cout << "Invalid number!" << endl;
        return;
    }

    auto it = buildings.begin();
    advance(it, index - 1);

    string name = (*it)->getName();
    buildings.erase(it);

    cout << "Building '" << name << "' deleted." << endl;
}

void saveDataToFile(const list<unique_ptr<Building>>& buildings) {
    string filename;
    cout << "Enter filename for saving (default: city_modified.txt): ";
    getline(cin, filename);
    if (filename.empty()) {
        filename = "city_modified.txt";
    }

    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Error creating file!" << endl;
        return;
    }

    for (const auto& building : buildings) {
        if (auto residential = dynamic_cast<ResidentialBuilding*>(building.get())) {
            residential->saveToFile(file);
        }
        else if (auto office = dynamic_cast<OfficeBuilding*>(building.get())) {
            office->saveToFile(file);
        }
    }

    cout << "Data saved to file: " << filename << endl;
}

void showStatistics(const list<unique_ptr<Building>>& buildings) {
    cout << "\n=== STATISTICS (LAMBDA FUNCTIONS) ===" << endl;

    if (buildings.empty()) {
        cout << "Building list is empty." << endl;
        return;
    }

    auto countResidentialOver100 = [&buildings]() -> int {
        int count = 0;
        for (const auto& building : buildings) {
            if (auto residential = dynamic_cast<ResidentialBuilding*>(building.get())) {
                if (residential->getApartmentsCount() > 100) {
                    count++;
                }
            }
        }
        return count;
        };

    cout << "1. Residential buildings with >100 apartments: " << countResidentialOver100() << endl;

    if (!buildings.empty()) {
        auto tallest = max_element(buildings.begin(), buildings.end(),
            [](const unique_ptr<Building>& a, const unique_ptr<Building>& b) {
                return a->getFloors() < b->getFloors();
            });

        cout << "2. Tallest building: " << (*tallest)->getName()
            << " (" << (*tallest)->getFloors() << " floors)" << endl;
    }

    double maxOfficeArea = 0;
    string largestOfficeName;

    for (const auto& building : buildings) {
        if (auto office = dynamic_cast<OfficeBuilding*>(building.get())) {
            double totalOfficeArea = office->getOfficesCount() * office->getAverageOfficeArea();
            if (totalOfficeArea > maxOfficeArea) {
                maxOfficeArea = totalOfficeArea;
                largestOfficeName = office->getName();
            }
        }
    }

    if (maxOfficeArea > 0) {
        cout << "3. Largest office building: " << largestOfficeName
            << " (total office area: " << maxOfficeArea << " sq.m)" << endl;
    }
    else {
        cout << "3. No office buildings found." << endl;
    }

    vector<Building*> residentialOver10;
    for (const auto& building : buildings) {
        if (dynamic_cast<ResidentialBuilding*>(building.get())) {
            if (building->getFloors() > 10) {
                residentialOver10.push_back(building.get());
            }
        }
    }

    cout << "4. Residential buildings with floors > 10: " << residentialOver10.size() << endl;

    int residentialCount = 0;
    int officeCount = 0;
    double totalArea = 0;

    for (const auto& building : buildings) {
        totalArea += building->getArea();
        if (dynamic_cast<ResidentialBuilding*>(building.get())) {
            residentialCount++;
        }
        else if (dynamic_cast<OfficeBuilding*>(building.get())) {
            officeCount++;
        }
    }

    cout << "5. General statistics:" << endl;
    cout << "   - Total buildings: " << buildings.size() << endl;
    cout << "   - Residential buildings: " << residentialCount << endl;
    cout << "   - Office buildings: " << officeCount << endl;
    cout << "   - Average building area: " << (buildings.size() > 0 ? totalArea / buildings.size() : 0)
        << " sq.m" << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    list<unique_ptr<Building>> buildings;
    int choice;

    cout << "Welcome to Building Management System!" << endl;
    cout << "Attempting to load data from city.txt..." << endl;

    ifstream defaultFile("city.txt");
    if (defaultFile.is_open()) {
        string line;
        while (getline(defaultFile, line)) {
            auto building = Building::createFromString(line);
            if (building) {
                buildings.push_back(move(building));
            }
        }
        cout << "Loaded " << buildings.size() << " buildings from city.txt" << endl;
    }
    else {
        cout << "File city.txt not found. Starting with empty database." << endl;
    }

    do {
        displayMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            loadDataFromFile(buildings);
            break;
        case 2:
            displayAllBuildings(buildings);
            break;
        case 3:
            searchBuildings(buildings);
            break;
        case 4:
            sortBuildings(buildings);
            break;
        case 5:
            addNewBuilding(buildings);
            break;
        case 6:
            editBuilding(buildings);
            break;
        case 7:
            deleteBuilding(buildings);
            break;
        case 8:
            saveDataToFile(buildings);
            break;
        case 9:
            showStatistics(buildings);
            break;
        case 0:
            cout << "Exit program. Save changes? (y/n): ";
            char save;
            cin >> save;
            if (save == 'y' || save == 'Y') {
                saveDataToFile(buildings);
            }
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 0);

    return 0;
}