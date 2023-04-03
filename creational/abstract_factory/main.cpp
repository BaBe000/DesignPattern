#include <iostream>

using namespace std;

class AbstractChair {
public:
    virtual void createChair() = 0;
};

class ModernChair : public AbstractChair {
public:
    ModernChair() {};
    void createChair() override {
        cout << "Created modern chair" << endl;
    }
};

class VintageChair : public AbstractChair {
public:
    VintageChair() {};
    void createChair() override {
        cout << "Created vintage chair" << endl;
    }
};

class AbstractSofa {
public:
    virtual void createSofa() = 0;
};

class ModernSofa : public AbstractSofa {
public:
    ModernSofa() {};
    void createSofa() override {
        cout << "Created modern sofa" << endl;
    }
};

class VintageSofa : public AbstractSofa {
public:
    VintageSofa() {};
    void createSofa() override {
        cout << "Created vintage sofa" << endl;
    }
};

class AbstractFactory {
public:
    virtual AbstractChair* createProductChair() = 0;
    virtual AbstractSofa* createProductSofa() = 0;
};

class ModernFactory : public AbstractFactory {
public:
    ModernFactory() {};
    AbstractChair* createProductChair() override {
        return new ModernChair();
    }
    AbstractSofa* createProductSofa() override {
        return new ModernSofa();
    }
};

class VintageFactory : public AbstractFactory {
public:
    VintageFactory() {};
    AbstractChair* createProductChair() override {
        return new VintageChair();
    }
    AbstractSofa* createProductSofa() override {
        return new VintageSofa();
    }
};

void requestfromClient(AbstractFactory *factory) {
    AbstractChair *chair = factory->createProductChair();
    AbstractSofa *sofa = factory->createProductSofa();
    chair->createChair();
    sofa->createSofa();
}

int main() {
    cout << "Create modern pattern:" << endl;
    AbstractFactory *test1 = new ModernFactory();
    requestfromClient(test1);
    cout << "Created vintage pattern:" << endl;
    AbstractFactory *test2 = new VintageFactory();
    requestfromClient(test2);
    return 0;
}