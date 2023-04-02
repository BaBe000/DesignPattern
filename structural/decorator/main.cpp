#include <iostream>
#define MILKTEA_COST 5;
#define BLACKSUGER_COST 2
#define BUBLLE_COST 2
#define EGGPUDDING_COST 3
#define WHITEPUDDING_COST 1.5
#define FUITPUDDING_COST 3

using namespace std;
class IMilktea {
public:
    // IMilktea();
    virtual double cost() = 0;
};


class Milktea : public IMilktea {
public:
    Milktea() {};
    double cost() override {
        return MILKTEA_COST;
    };
};

class MilkTeaDecorator : public IMilktea {
protected:
    MilkTeaDecorator(IMilktea *milktea) : milktea(milktea) {};
public:
    virtual double cost() override {
        return milktea->cost();
    };
private:
    IMilktea *milktea;
};

class BlackSugar : public MilkTeaDecorator {
public:
    BlackSugar(IMilktea *milktea) : MilkTeaDecorator(milktea) {};
    double cost() override {
        return BLACKSUGER_COST + MilkTeaDecorator::cost();
    }
};

class Bubble : public MilkTeaDecorator {
public:
    Bubble(IMilktea *milktea) : MilkTeaDecorator(milktea) {};
    double cost() override {
        return BUBLLE_COST + MilkTeaDecorator::cost();
    }
};

class Eggpudding : public MilkTeaDecorator {
public:
    Eggpudding(IMilktea *milktea) : MilkTeaDecorator(milktea) {};
    double cost() override {
        return EGGPUDDING_COST + MilkTeaDecorator::cost();
    }
};

class Fruitpudding : public MilkTeaDecorator {
public:
    Fruitpudding(IMilktea *milktea) : MilkTeaDecorator(milktea) {};
    double cost() override {
        return FUITPUDDING_COST + MilkTeaDecorator::cost();
    }
};

class WhitePudding : public MilkTeaDecorator {
public:
    WhitePudding(IMilktea *milktea) : MilkTeaDecorator(milktea) {};
    double cost() override {
        return WHITEPUDDING_COST + MilkTeaDecorator::cost();
    }
};

int main() {
    auto result = new Eggpudding(
                                    new Fruitpudding(
                                        new BlackSugar(
                                            new Bubble(
                                                new Milktea()))));
    // auto result = new Eggpudding(new Milktea());

    cout << " The cost of your milktea is: " << result->cost();
    return 0;
}