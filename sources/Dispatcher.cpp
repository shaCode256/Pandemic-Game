#include "Dispatcher.hpp"

using namespace pandemic;

Dispatcher &Dispatcher::fly_direct(City cityTo) {
    currentCity=cityTo;
    return *this;
}