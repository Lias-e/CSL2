#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Product {
    string code_prod;
    string designation;
    string UM;
    double PUA_HT;
    double Qty;
    double VAT;
    Product* next;
};

class ProductList {
private:
    Product* head;

public:
    ProductList() : head(nullptr) {}

    void addProduct() {
        Product* newProduct = new Product;
        cout << "Enter product code: ";
        cin >> newProduct->code_prod;
        cout << "Enter designation: ";
        cin.ignore();
        getline(cin, newProduct->designation);
        cout << "Enter unit of measurement: ";
        cin >> newProduct->UM;
        cout << "Enter unit purchase price (excluding tax): ";
        cin >> newProduct->PUA_HT;
        cout << "Enter quantity purchased: ";
        cin >> newProduct->Qty;
        cout << "Enter VAT (9 or 21): ";
        cin >> newProduct->VAT;
        newProduct->next = head;
        head = newProduct;
    }

    void viewProducts() {
        Product* temp = head;
        while (temp != nullptr) {
            cout << "Code: " << temp->code_prod << ", Designation: " << temp->designation
                 << ", UM: " << temp->UM << ", PUA_HT: " << temp->PUA_HT
                 << ", Qty: " << temp->Qty << ", VAT: " << temp->VAT << "%" << endl;
            temp = temp->next;
        }
    }

    void displayTotals() {
        int totalProducts = 0;
        double totalExclVAT = 0, totalVAT = 0, totalTTC = 0;
        Product* temp = head;
        while (temp != nullptr) {
            totalProducts++;
            double exclVAT = temp->PUA_HT * temp->Qty;
            double vatAmount = exclVAT * (temp->VAT / 100);
            totalExclVAT += exclVAT;
            totalVAT += vatAmount;
            totalTTC += exclVAT + vatAmount;
            temp = temp->next;
        }
        cout << "Total products: " << totalProducts << endl;
        cout << "Total excl. VAT: " << totalExclVAT << endl;
        cout << "Total VAT: " << totalVAT << endl;
        cout << "Total TTC: " << totalTTC << endl;
    }

    void processPayment() {
        double amountPaid;
        displayTotals();
        cout << "Enter amount paid by customer: ";
        cin >> amountPaid;
        double totalTTC = 0;
        Product* temp = head;
        while (temp != nullptr) {
            double exclVAT = temp->PUA_HT * temp->Qty;
            double vatAmount = exclVAT * (temp->VAT / 100);
            totalTTC += exclVAT + vatAmount;
            temp = temp->next;
        }
        double difference = amountPaid - totalTTC;
        cout << "Difference: " << difference << endl;
    }

    void deleteProduct() {
        string code;
        cout << "Enter product code to delete: ";
        cin >> code;
        Product* temp = head;
        Product* prev = nullptr;
        while (temp != nullptr && temp->code_prod != code) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Product not found." << endl;
            return;
        }
        if (prev == nullptr) {
            head = temp->next;
        } else {
            prev->next = temp->next;
        }
        delete temp;
        cout << "Product deleted." << endl;
    }

    void showMaxMinPrice() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        double maxPrice = head->PUA_HT;
        double minPrice = head->PUA_HT;
        Product* temp = head->next;
        while (temp != nullptr) {
            if (temp->PUA_HT > maxPrice) maxPrice = temp->PUA_HT;
            if (temp->PUA_HT < minPrice) minPrice = temp->PUA_HT;
            temp = temp->next;
        }
        cout << "Max price: " << maxPrice << endl;
        cout << "Min price: " << minPrice << endl;
    }

    void emptyList() {
        while (head != nullptr) {
            Product* temp = head;
            head = head->next;
            delete temp;
        }
        cout << "List emptied." << endl;
    }

    void calculateProfit() {
        double totalProfit = 0;
        Product* temp = head;
        while (temp != nullptr) {
            double exclVAT = temp->PUA_HT * temp->Qty;
            totalProfit += exclVAT * 0.10;
            temp = temp->next;
        }
        cout << "Total profit: " << totalProfit << endl;
    }

    void stopProgram() {
        cout << "Stopping the program." << endl;
        exit(0);
    }
};

int main() {
    ProductList productList;
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. ADD Products At the top of the list\n";
        cout << "2. VIEW the list of products purchased\n";
        cout << "3. Display the total number of products purchased as well as the total amounts excl. VAT, total VAT and total TTC\n";
        cout << "4. Ask the customer for payment and calculate the difference between the amount paid and the net amount to be paid\n";
        cout << "5. DELETE products\n";
        cout << "6. Show max and min price\n";
        cout << "7. EMPTY the list\n";
        cout << "8. STOPPING the program\n";
        cout << "9. Calculate Total profit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: productList.addProduct(); break;
            case 2: productList.viewProducts(); break;
            case 3: productList.displayTotals(); break;
            case 4: productList.processPayment(); break;
            case 5: productList.deleteProduct(); break;
            case 6: productList.showMaxMinPrice(); break;
            case 7: productList.emptyList(); break;
            case 8: productList.stopProgram(); break;
            case 9: productList.calculateProfit(); break;
            default: cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 8);

    return 0;
}
