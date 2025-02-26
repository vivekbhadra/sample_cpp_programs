#include <iostream> 
#include <exception>
#include <memory>

class Base 
{
    public:
        Base() = default;
        virtual ~Base() {}
};

class Derived1 : public Base 
{
    public:
        Derived1() = default;
        void print() { std::cout << "Hello I am Derived1\n"; }
        ~Derived1() {}
};

class Derived2 : public Base 
{
    public:
        Derived2() = default;
        void print() { std::cout << "Hello I am Derived2\n"; }
        ~Derived2() {}
};

class Derived3 : public Base 
{
    public:
        Derived3() = default;
        void print() { std::cout << "Hello I am Derived3\n"; }
        ~Derived3() {}
};

void printing_interface(std::shared_ptr<Base>& base_ptr)
{
    Derived1 * derived_ptr = dynamic_cast<Derived1 *>(base_ptr.get()); // dynamic_cast doesn't work on smart pointers,
                                                                       // get the raw pointer out of it
    if(derived_ptr) 
    {
        derived_ptr->print();
    } else {
        throw std::runtime_error("Invalid pointer conversion between parent and child obj types");
    }
}

int main()
{
    std::shared_ptr<Base> base_ptr = std::make_shared<Derived1>();
    printing_interface(base_ptr);

    return 0;
}
