#include <iostream>
#include <exception>

// Inherit from standard exception
class MyLegacyError : public std::exception {
public:
    // We override 'what()'. 
    // We MUST include 'throw()' to match the base class in C++98.
    virtual const char* what() const throw() {
        return "Something went wrong (C++98 style)";
    }
};
class MyLegacyError2 : public std::exception {
public:
    // We override 'what()'. 
    // We MUST include 'throw()' to match the base class in C++98.
    virtual const char* what() const throw() {
        return "Something went wrong (C++98 style)22222";
    }
};

int main() {
    try {
        int nb = -1;
        if(nb < 0) {
            throw MyLegacyError();
        }
        if (nb == 0) {
            throw MyLegacyError2();
        }
    } 
    catch (const std::exception& e) {
        std::cout << "Caught: " << e.what() << std::endl;
    }
    return 0;
}