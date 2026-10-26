#include <iostream>
#include <string>

class my_class {
private:
    std::string element;

public:
    my_class() {
        element = "";
    }

    my_class(std::string val) {
        element = val;
    }


    void print_my_element() {
        std::cout << element << std::endl;
    }
};

int main() {
    my_class obj("Hello World !");
    obj.print_my_element();
    return 0;
}