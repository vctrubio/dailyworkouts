#include "Car.hpp"

Car::Car(string model, unsigned int price):_model(model), _price(price), _brand(MERCEDES) 
{

}

Car::~Car()
{}

std::ostream& operator<<(std::ostream& os, const Car& car)
{
    os << "Model: " << car._model << ", Price: " << car._price;
    return os;
}
