#include "ParkingManagementSystem.h"
#include <fstream>
#include <iostream>
#include <sstream>

ParkingManagementSystem::ParkingManagementSystem(int totalSpots)
    : totalSpots(totalSpots), nextAvailableSpot(0) {
    parkingSpots = new std::string[totalSpots]; // Allocate memory for the array
}

ParkingManagementSystem::~ParkingManagementSystem() {
    delete[] parkingSpots; // Free memory when the object is destroyed
}

void ParkingManagementSystem::loadParkingDataFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Warning: Unable to open file " << filename << ". Parking data not loaded." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string licensePlate;
        int spotIndex;
        if (iss >> licensePlate >> spotIndex) {
            parkingDatabase[licensePlate] = spotIndex;
            parkingSpots[spotIndex] = licensePlate;
            if (spotIndex >= nextAvailableSpot) {
                nextAvailableSpot = spotIndex + 1;
            }
        }
    }
    file.close();
}

int ParkingManagementSystem::assignParkingSpot(const std::string& licensePlate) {
    // Check if there are available spots
    if (nextAvailableSpot < totalSpots) {
        // Assign the next available spot to the car
        parkingDatabase[licensePlate] = nextAvailableSpot;
        parkingSpots[nextAvailableSpot] = licensePlate;
        return nextAvailableSpot++;
    } else {
        // All spots are reserved
        return -1;
    }
}

bool ParkingManagementSystem::isFull() const { //could also add the feature to show the next available time a spot will be free. 
    return nextAvailableSpot >= totalSpots;
}

bool ParkingManagementSystem::isReturningCar(const std::string &licensePlate) {
    // Search for the license plate in the array
    for (int i = 0; i < nextAvailableSpot; ++i) {
        if (parkingSpots[i] == licensePlate) {
            return true; // Car found
        }
    }
    return false; // Car not found
}

void ParkingManagementSystem::carLeaves(const std::string& licensePlate) {
    auto it = parkingDatabase.find(licensePlate);
    if (it != parkingDatabase.end()) {
        int spotIndex = it->second;
        parkingDatabase.erase(it);
        parkingSpots[spotIndex] = ""; // Mark the spot as available
    }
}
