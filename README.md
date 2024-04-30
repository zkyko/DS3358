# DS3358

1A)	A car parking management system is designed to manage a reserved parking spot, possibly for an apartment complex or valet service. Vehicles are assigned a specific spot when they first arrive, and keep that spot if they return. The primary goal is to streamline the parking process by assigning new cars to an individual spot, and the same spot whenever they return. 

1B)	The system can be conceptualized using an array of strings, where each spot in the array represents a parking spot, and the string in the spot is the license plate number of the assigned car. When a car comes to the garage, the system checks if they have an assigned spot. If they do, then nothing changes in the array. If not, the system assigns then the next available spot, (unless all spots have been reserved already). 

![Copy of Untitled Diagram drawio](https://github.com/zkyko/DS3358/assets/168230970/1e82364c-833b-4778-a1ba-eb69245c40dc)
--------------------------------------------------------------------------------------------
The parking management system is designed to efficiently assign and manage parking spots for vehicles in a lot or garage setting. The system handles real-time parking assignments, tracks vehicle entries and exits, and maintains a detailed log of parking activity. This documentation outlines the approach to solving the parking management problem, details the usage of classes, and describes the overall implementation strategy to aid developers who may wish to extend or integrate this system into broader applications.

Approach to Solving the Problem
The parking management system aims to optimize the use of parking spaces by automating the assignment of vehicles to available spots and tracking their occupancy status. The primary challenges addressed include:

Dynamic Spot Assignment: Ensuring that each vehicle is assigned to the most appropriate available parking spot upon entry.
Tracking Occupancy: Maintaining up-to-date records of which spots are occupied and which are available, adjusting in real-time as vehicles enter and leave.
Handling Re-entry: Efficiently managing vehicles that frequently enter and leave the parking area by remembering their previously assigned spots.
Scalability and Flexibility: Designing the system to easily scale up for large parking lots and to adapt to different types of parking scenarios.
Usage of Classes
The system is built using several key classes, each responsible for a specific part of the parking management process:

ParkingManagementSystem: The core class that handles the logic for parking spot assignments, tracking, and management.
Methods:
assignParkingSpot: Assigns an available parking spot to a vehicle.
carLeaves: Frees up a parking spot when a vehicle exits.
isFull: Checks if the parking lot is at full capacity.
loadParkingDataFromFile: Initializes the parking spot statuses from a file.
isReturningCar: Checks if a vehicle has previously parked in the lot.
UserInterface: Facilitates interaction with the parking management system through a command-line interface or potentially a graphical user interface (GUI).
Methods:
getUserInput: Collects input from the user.
displayMessage: Displays messages to the user.
LogToCSV: Provides functionality to log parking events to a CSV file for record-keeping and later analysis.
Methods:
LogToCSV: Logs details about parking events (time, license plate, parking spot, and status).

Implementation Strategy
The implementation strategy involves the following steps:

1. Initialization: On startup, the system loads existing parking data from a file if available, setting up the initial state of parking spots.
2. User Interaction: The user interacts with the system primarily through the UserInterface class, which prompts for inputs such as vehicle license plates and commands to exit.
3. Real-Time Management: As vehicles enter the parking lot, the ParkingManagementSystem assigns spots based on availability and updates the internal data structures to reflect the new state. When vehicles leave, the system updates the statuses again, marking spots as available.
4. Logging and Monitoring: All parking events are logged to a CSV file using the LogToCSV class, enabling detailed monitoring and later analysis of parking lot usage.
5. Extensibility and Integration: The system is designed with clear interfaces and encapsulated functionality to allow for easy integration into larger systems or adaptation to different requirements. Developers can extend the classes to add new features.
