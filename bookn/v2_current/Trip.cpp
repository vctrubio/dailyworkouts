#include "Trip.hpp"

Trip::Trip(User *driver):_driver(driver), _id(s_counterId++), _price(0)
{
}


int Trip::s_counterId = 0;


