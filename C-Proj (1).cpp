#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// Function to display the restaurant menu
void displayMenu() {
    cout << "===== Restaurant Menu =====" << endl;
    cout << "1. Burger - $5.99" << endl;
    cout << "2. Pizza - $8.99" << endl;
    cout << "3. Pasta - $7.49" << endl;
    cout << "4. Salad - $4.99" << endl;
    cout << "===========================" << endl;
}

int main() {
    // Open a file for writing the receipt
    ofstream receiptFile("receipt.txt");

    if (!receiptFile.is_open()) {
        cerr << "Error opening receipt file!" << endl;
        return 1;
    }

    // Display the menu
    displayMenu();

    // Get user orders
    int choice;
    int quantity;
    double totalAmount = 0.0;

    do {
        cout << "Enter the item number (1-4) or 0 to exit: ";
        cin >> choice;

        if (choice >= 1 && choice <= 4) {
            cout << "Enter the quantity: ";
            cin >> quantity;

            // Update total amount
            switch (choice) {
            case 1:
                totalAmount += quantity * 5.99;
                break;
            case 2:
                totalAmount += quantity * 8.99;
                break;
            case 3:
                totalAmount += quantity * 7.49;
                break;
            case 4:
                totalAmount += quantity * 4.99;
                break;
            }

            // Write the order to the receipt file
            receiptFile << "Item: " << setw(10) << left << choice << "Quantity: " << setw(5) << left << quantity
                << "Total: $" << fixed << setprecision(2) << setw(10) << left << totalAmount << endl;
        }
        else if (choice != 0) {
            cout << "Invalid choice. Please enter a number between 1 and 4, or 0 to exit." << endl;
        }
    } while (choice != 0);

    // Print the total amount at the end of the receipt
    receiptFile << "===========================" << endl;
    receiptFile << "Total Amount: $" << fixed << setprecision(2) << totalAmount << endl;

    // Close the receipt file
    receiptFile.close();

    cout << "Receipt generated successfully. Check 'receipt.txt' for details." << endl;

    return 0;
}
