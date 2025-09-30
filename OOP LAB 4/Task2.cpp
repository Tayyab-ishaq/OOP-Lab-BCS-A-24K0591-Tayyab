#include <iostream>
#include <string>
using namespace std;

class Product {
    int id;
    string name;
    double price;
    int stockQuantity;
public:
    Product() {}
    Product(int i, string n, double p, int q) {
        id = i;
        name = n;
        price = p;
        stockQuantity = q;
    }
    int getId() { return id; }
    string getName() { return name; }
    double getPrice() { return price; }
    int getStock() { return stockQuantity; }
    void reduceStock(int q) { stockQuantity -= q; }
};

class ShoppingCart {
    Product** items;  //making object of type class dynamically
    int* quantities;
    int capacity;
    int count;
public:
    ShoppingCart(int c) {
        capacity = c;
        count = 0;
        items = new Product*[capacity];
        quantities = new int[capacity];
    }
     ~ShoppingCart() {
        delete[] items;
        delete[] quantities;   //since allocating dynamically we have to free it manually
    }
    ShoppingCart(Product* p, int q) {
        capacity = 10;
        count = 0;
        items = new Product*[capacity];
        quantities = new int[capacity];
        addProduct(p, q);
    }
    void addProduct(Product* p, int q) {
        if (p->getStock() >= q && count < capacity) {
            items[count] = p;
            quantities[count] = q;
            p->reduceStock(q);
            count++;
        } else {
            cout << "Not enough stock or cart is full" << endl;
        }
    }
    void removeProduct(int id) {
        for (int i = 0; i < count; i++) {
            if (items[i]->getId() == id) {
                for (int j = i; j < count - 1; j++) {
                    items[j] = items[j + 1];
                    quantities[j] = quantities[j + 1];
                }
                count--;
                break;
            }
        }
    }
    void displayCart() {
        if (count == 0) {
            cout << "Cart is empty" << endl;
            return;
        }
        for (int i = 0; i < count; i++) {
            cout << items[i]->getId() << " " << items[i]->getName() 
                 << " x" << quantities[i] 
                 << " = " << items[i]->getPrice() * quantities[i] << endl;
        }
    }
    double calculateTotal() {
        double total = 0;
        for (int i = 0; i < count; i++) {
            total += items[i]->getPrice() * quantities[i];
        }
        return total;
    }
};

int main() {
    Product p1(1, "Laptop", 50000, 5);
    Product p2(2, "Phone", 25000, 10);
    Product p3(3, "Headphones", 3000, 20);

    ShoppingCart cart(10);
    cart.addProduct(&p1, 2);
    cart.addProduct(&p2, 1);
    cart.addProduct(&p3, 3);

    cout << "Cart contents:" << endl;
    cart.displayCart();
    cout << "Total: " << cart.calculateTotal() << endl;

    cout << endl << "Removing product ID 2" << endl;
    cart.removeProduct(2);

    cart.displayCart();
    cout << "Total: " << cart.calculateTotal() << endl;

    return 0;
}
