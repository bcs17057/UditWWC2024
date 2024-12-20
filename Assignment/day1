// Develop a Warehouse Inventory Management System using C++ to simulate how industries manage and track their inventory.
The program should enable users to add new items to the inventory, update stock levels, track inventory movement, and
generate reports.
Each item in the inventory should be represented as an object with attributes like a unique item ID, name, category,
quantity, and reorder level.
The system should include functionality to alert the user when stock levels fall below the reorder threshold.
A menu-driven interface should allow users to perform operations such as viewing inventory, searching for items
by name or category, and exporting inventory data to a file for record-keeping.
This assignment is designed to mirror real-world inventory management systems used in industries like retail, manufacturing, and logistics,
providing hands-on experience with object-oriented design, file handling, and user interaction in C++.//



#include <iostream>
#include <vector>
#include <fstream>
#include <string>

class InventoryItem {
public:
    int itemID;
    std::string name;
    std::string category;
    int quantity;
    int reorderLevel;

    InventoryItem(int id, const std::string& n, const std::string& c, int q, int r)
        : itemID(id), name(n), category(c), quantity(q), reorderLevel(r) {}

    void display() const {
        std::cout << "ID: " << itemID << ", Name: " << name
                  << ", Category: " << category << ", Quantity: " << quantity
                  << ", Reorder Level: " << reorderLevel << std::endl;
    }
};

class InventoryManagementSystem {
private:
    std::vector<InventoryItem> inventory;

public:
    void addItem() {
        int id, quantity, reorderLevel;
        std::string name, category;

        std::cout << "Enter Item ID: ";
        std::cin >> id;
        std::cin.ignore(); // Clear newline from input buffer
        std::cout << "Enter Item Name: ";
        std::getline(std::cin, name);
        std::cout << "Enter Item Category: ";
        std::getline(std::cin, category);
        std::cout << "Enter Item Quantity: ";
        std::cin >> quantity;
        std::cout << "Enter Reorder Level: ";
        std::cin >> reorderLevel;

        inventory.emplace_back(id, name, category, quantity, reorderLevel);
        std::cout << "Item added successfully!\n";
    }

    void updateStock() {
        int id, newQuantity;
        std::cout << "Enter Item ID to update: ";
        std::cin >> id;

        for (auto& item : inventory) {
            if (item.itemID == id) {
                std::cout << "Current Quantity: " << item.quantity << std::endl;
                std::cout << "Enter new quantity: ";
                std::cin >> newQuantity;
                item.quantity = newQuantity;
                std::cout << "Stock updated successfully!\n";
                return;
            }
        }
        std::cout << "Item not found!\n";
    }

    void viewInventory() const {
        std::cout << "Current Inventory:\n";
        for (const auto& item : inventory) {
            item.display();
            if (item.quantity < item.reorderLevel) {
                std::cout << "ALERT: Stock for " << item.name << " is below reorder level!\n";
            }
        }
    }

    void searchItem() const {
        std::string searchTerm;
        std::cout << "Enter item name or category to search: ";
        std::cin.ignore();
        std::getline(std::cin, searchTerm);

        std::cout << "Search Results:\n";
        for (const auto& item : inventory) {
            if (item.name == searchTerm || item.category == searchTerm) {
                item.display();
            }
        }
    }

    void exportInventory() const {
        std::ofstream outFile("inventory_report.txt");
        if (outFile.is_open()) {
            for (const auto& item : inventory) {
                outFile << item.itemID << "," << item.name << "," << item.category
                        << "," << item.quantity << "," << item.reorderLevel << "\n";
            }
            outFile.close();
            std::cout << "Inventory exported to inventory_report.txt\n";
        } else {
            std::cout << "Error opening file for writing.\n";
        }
    }
};

int main() {
    InventoryManagementSystem ims;
    int choice;

    do {
        std::cout << "\nWarehouse Inventory Management System\n";
        std::cout << "1. Add Item\n";
        std::cout << "2. Update Stock\n";
        std::cout << "3. View Inventory\n";
        std::cout << "4. Search Item\n";
        std::cout << "5. Export Inventory\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                ims.addItem();
                break;
            case 2:
                ims.updateStock();
                break;
            case 3:
                ims.viewInventory();
                break;
            case 4:
                ims.searchItem();
                break;
            case 5:
                ims.exportInventory();
                break;
            case 6:
                std::cout << "Exiting the program.\
