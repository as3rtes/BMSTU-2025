#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Product {
    string name;
    double price = 0.0;
    int quantity = 0;
};

void writeToOutput(const string& message) {
    ofstream output("output.txt", ios::app);
    if (output.is_open()) {
        output << message << endl;
        output.close();
    }
    else {
        cout << "Error: cannot open output.txt for writing" << endl;
    }
}

vector<Product> readProductsFromFile() {
    vector<Product> products;
    ifstream file("products.txt");

    if (!file.is_open()) {
        cout << "File products.txt not found or cannot be opened!" << endl;
        return products;
    }

    Product p;
    while (file >> p.name >> p.price >> p.quantity) {
        products.push_back(p);
    }

    file.close();
    return products;
}

void writeProductsToFile(const vector<Product>& products) {
    ofstream file("products.txt");

    if (!file.is_open()) {
        cout << "Error: cannot open products.txt for writing!" << endl;
        return;
    }

    for (const auto& p : products) {
        file << p.name << " " << p.price << " " << p.quantity << endl;
    }

    file.close();
    cout << "Data successfully written to products.txt" << endl;
}

void createAndFillFile() {
    ofstream file("products.txt");

    if (!file.is_open()) {
        cout << "Error opening file products.txt!" << endl;
        return;
    }

    string name;
    double price;
    int quantity;

    cout << "Create and fill file" << endl;
    cout << "Enter product data (empty line in name to finish):" << endl;
    writeToOutput("Create and fill file");

    int productCount = 0;
    while (true) {
        cout << "Product name: ";
        getline(cin, name);

        if (name.empty()) {
            break;
        }

        cout << "Price: ";
        cin >> price;

        cout << "Quantity: ";
        cin >> quantity;

        cin.ignore();

        file << name << " " << price << " " << quantity << endl;

        string logMessage = "Added product: " + name + ", price: " + to_string(price) + ", quantity: " + to_string(quantity);
        cout << "Product added!" << endl;
        writeToOutput(logMessage);
        productCount++;
    }

    file.close();
    cout << "Data saved to 'products.txt'. Products added: " << productCount << endl;
    writeToOutput("Data saved to 'products.txt'. Products added: " + to_string(productCount));
}

void searchProduct() {
    string searchName;
    cout << "Enter product name to search: ";
    getline(cin, searchName);

    vector<Product> products = readProductsFromFile();
    bool found = false;

    cout << "Search results" << endl;
    writeToOutput("Search results");
    writeToOutput("Search product: " + searchName);

    for (const auto& p : products) {
        if (p.name == searchName) {
            cout << "Product found: " << endl;
            cout << "Name: " << p.name << endl;
            cout << "Price: " << p.price << endl;
            cout << "Quantity: " << p.quantity << endl;
            cout << "-------------------" << endl;

            string result = "Found: " + p.name + ", price: " + to_string(p.price) + ", quantity: " + to_string(p.quantity);
            writeToOutput(result);

            found = true;
        }
    }

    if (!found) {
        cout << "Product with name '" << searchName << "' not found." << endl;
        writeToOutput("Product not found: " + searchName);
    }
}

bool compareByPrice(const Product& a, const Product& b) {
    return a.price < b.price;
}

bool compareByQuantity(const Product& a, const Product& b) {
    return a.quantity < b.quantity;
}

void sortProducts() {
    int choice;
    cout << "Choose sort type:" << endl;
    cout << "1 - By price " << endl;
    cout << "2 - By quantity " << endl;
    cout << "Your choice: ";
    cin >> choice;
    cin.ignore();

    vector<Product> products = readProductsFromFile();

    if (products.empty()) {
        cout << "File is empty or not found!" << endl;
        return;
    }

    string sortType;
    switch (choice) {
    case 1:
        sort(products.begin(), products.end(), compareByPrice);
        cout << "Products sorted by price." << endl;
        sortType = "by price";
        break;
    case 2:
        sort(products.begin(), products.end(), compareByQuantity);
        cout << "Products sorted by quantity." << endl;
        sortType = "by quantity";
        break;
    default:
        cout << "Wrong choice!" << endl;
        return;
    }

    writeProductsToFile(products);

    cout << "\nSorted list:" << endl;
    cout << "-------------------" << endl;
    writeToOutput("Products sorted " + sortType);

    for (const auto& p : products) {
        cout << p.name << " | Price: " << p.price << " | Quantity: " << p.quantity << endl;
        string productInfo = p.name + " | Price: " + to_string(p.price) + " | Quantity: " + to_string(p.quantity);
        writeToOutput(productInfo);
    }
}

void addProductToFile() {
    string name;
    double price;
    int quantity;

    cout << "Add new product" << endl;
    cout << "Enter new product data:" << endl;
    writeToOutput("Add new product");

    cout << "Product name: ";
    getline(cin, name);

    cout << "Price: ";
    cin >> price;

    cout << "Quantity: ";
    cin >> quantity;

    cin.ignore();

    ofstream file("products.txt", ios::app);
    if (!file.is_open()) {
        cout << "Error: cannot open products.txt for adding!" << endl;

        ofstream newFile("products.txt");
        if (newFile.is_open()) {
            newFile << name << " " << price << " " << quantity << endl;
            newFile.close();
            cout << "New file created and product added!" << endl;
        }
        else {
            cout << "Failed to create file!" << endl;
            return;
        }
    }
    else {
        file << name << " " << price << " " << quantity << endl;
        file.close();
        cout << "New product added to end of file!" << endl;
    }

    string logMessage = "Added new product: " + name + ", price: " + to_string(price) + ", quantity: " + to_string(quantity);
    writeToOutput(logMessage);

    vector<Product> products = readProductsFromFile();
    cout << "Total products in file: " << products.size() << endl;
}

void showProductsByPrice() {
    double maxPrice;
    cout << "Enter maximum price: ";
    cin >> maxPrice;
    cin.ignore();

    vector<Product> products = readProductsFromFile();
    vector<Product> filteredProducts;

    for (const auto& p : products) {
        if (p.price <= maxPrice) {
            filteredProducts.push_back(p);
        }
    }

    cout << "\nProducts with price not more than " << maxPrice << endl;
    writeToOutput("Products with price not more than " + to_string(maxPrice));

    if (filteredProducts.empty()) {
        cout << "Products with price not more than " << maxPrice << " not found." << endl;
        writeToOutput("Products not found");
    }
    else {
        for (const auto& p : filteredProducts) {
            cout << p.name << " | Price: " << p.price << " | Quantity: " << p.quantity << endl;
            string productInfo = p.name + " | Price: " + to_string(p.price) + " | Quantity: " + to_string(p.quantity);
            writeToOutput(productInfo);
        }
        cout << "Products found: " << filteredProducts.size() << endl;
    }
}

void displayAllProducts() {
    vector<Product> products = readProductsFromFile();

    if (products.empty()) {
        cout << "File is empty!" << endl;
        return;
    }

    cout << "All products" << endl;
    cout << "Total products: " << products.size() << endl;
    cout << "-------------------" << endl;
    writeToOutput("All products");
    writeToOutput("Total products: " + to_string(products.size()));

    for (const auto& p : products) {
        cout << p.name << " | Price: " << p.price << " | Quantity: " << p.quantity << endl;
        string productInfo = p.name + " | Price: " + to_string(p.price) + " | Quantity: " + to_string(p.quantity);
        writeToOutput(productInfo);
    }
}

void clearOutputFile() {
    ofstream output("output.txt");
    output << "Program log" << endl;
    output.close();
}

int main() {
    clearOutputFile();

    int choice;

    do {
        cout << "\nMenu" << endl;
        cout << "1 - Create and fill file" << endl;
        cout << "2 - Search product by name" << endl;
        cout << "3 - Sort products" << endl;
        cout << "4 - Add new product" << endl;
        cout << "5 - Show products by price" << endl;
        cout << "6 - Show all products" << endl;
        cout << "0 - Exit" << endl;
        cout << "Your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            createAndFillFile();
            break;
        case 2:
            searchProduct();
            break;
        case 3:
            sortProducts();
            break;
        case 4:
            addProductToFile();
            break;
        case 5:
            showProductsByPrice();
            break;
        case 6:
            displayAllProducts();
            break;
        case 0:
            cout << "Program exit." << endl;
            writeToOutput("Program exit");
            break;
        default:
            cout << "Wrong choice!" << endl;
        }

    } while (choice != 0);

    return 0;
}
