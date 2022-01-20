// name(s) and Perm 
// This is the only file to submit.

#include "car.hpp"
#include <cstddef>
#include <cstring>
// #include ......
Car::Car() : manufacturer(NULL), model(NULL), zeroToSixtyNs(0), headonDragCoeff(0), horsepower(0), backseatDoors(None), seatCount(0) {

}

Car::Car(const char* const manufacturerName, const char* const modelName, PerformanceStats perf, uint8_t numSeats, DoorKind backseatDoorDesign): zeroToSixtyNs(perf.zeroToSixtyNs), horsepower(perf.horsepower), headonDragCoeff(perf.headonDragCoeff), backseatDoors(backseatDoorDesign), seatCount(numSeats){
	manufacturer = (char*)manufacturerName;
	model = (char*)modelName;
}

Car::Car(Car const& o){
	this->manufacturer = (char*)o.getManufacturer();
    this->model = (char*)o.getModel();
    this->zeroToSixtyNs = o.getStats().zeroToSixtyNs;
    this->headonDragCoeff = o.getStats().headonDragCoeff;
    this->horsepower = o.getStats().horsepower;
    this->backseatDoors = o.getBackseatDoors();
    this->seatCount = o.getSeatCount();
	//comment
}

Car::~Car(){

}

Car& Car::operator=(Car const& o){
	if(this == &o){
		 return *this;
	 }
	this->manufacturer = (char*)o.getManufacturer();
    this->model = (char*)o.getModel();
    this->zeroToSixtyNs = o.getStats().zeroToSixtyNs;
    this->headonDragCoeff = o.getStats().headonDragCoeff;
    this->horsepower = o.getStats().horsepower;
    this->backseatDoors = o.getBackseatDoors();
    this->seatCount = o.getSeatCount();
	return *this;
}


char const* Car::getManufacturer() const{
	return (char const*)manufacturer;
}

char const* Car::getModel() const{
	return (char const*)model;
}

PerformanceStats Car::getStats() const{
	return PerformanceStats(horsepower, zeroToSixtyNs, headonDragCoeff);
}

uint8_t Car::getSeatCount() const{
	return seatCount;
}

DoorKind Car::getBackseatDoors() const{
	return backseatDoors;
}

void Car::manufacturerChange(char const* const newManufacturer){
	manufacturer = (char*)newManufacturer;
}

void Car::modelNameChange(char const* const newModelName) {
	model = (char*)newModelName;
}

void Car::reevaluateStats(PerformanceStats newStats) {
	horsepower = newStats.horsepower;
	zeroToSixtyNs = newStats.zeroToSixtyNs;
	headonDragCoeff = newStats.headonDragCoeff;
}

void Car::recountSeats(uint8_t newSeatCount) {
	seatCount = newSeatCount;
}

void Car::reexamineDoors(DoorKind newDoorKind) {
	backseatDoors = newDoorKind;
}
