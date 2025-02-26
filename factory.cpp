#include <iostream>
#include <memory>

class Base {
    public:
        virtual std::string name() = 0;
        virtual ~Base() = default;
};

class Derived1 : public Base {
    public: 
        std::string name() override { return "I am Derived1";}
};

class Derived2 : public Base {
        std::string name() override { return "I am Derived2";}
};

class Derived3 : public Base {
    public:
        std::string name() override { return "I am Derived3";}
};

std::unique_ptr<Base> create(const std::string& name)
{
    if(name == "Derived1") return std::make_unique<Derived1>();
    if(name == "Derived2") return std::make_unique<Derived2>();
    if(name == "Derived3") return std::make_unique<Derived3>();
    
    throw std::invalid_argument(std::string("Invalid Type ") + name);
}

int main()
{
    try
    {
        std::unique_ptr<Base> obj = create("Derived4");
        std::cout << obj->name() << "\n";
    }
    catch(std::exception& e) 
    {
        std::cerr << "Exception caught: " << e.what() << "\n";
    }

    return 0;
}


