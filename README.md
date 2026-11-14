# 🚦 Traffic Signal Queue Management System

### A Data Structures & Algorithms Based Traffic Management Simulation

A smart traffic management simulation designed to manage vehicle queues at a four-way intersection using the **Deque (Double-Ended Queue)** data structure in C++. The system follows a round-robin signal mechanism and provides priority to emergency vehicles to ensure efficient traffic flow.

---

## 📌 Project Overview

Traffic congestion at busy intersections causes delays, increases travel time, and creates difficulties for emergency vehicles such as ambulances and fire trucks.

The **Traffic Signal Queue Management System** simulates a four-way traffic intersection consisting of North, East, South, and West directions. It uses separate deques to manage vehicles in each direction.

Normal vehicles follow the First-In-First-Out (FIFO) principle, while emergency vehicles receive priority by being inserted at the front of the deque.

The system processes up to five vehicles during each green signal and rotates traffic signals in a round-robin sequence.

## 🎯 Objectives

- Manage vehicle queues across four directions.
- Implement the Deque data structure for flexible vehicle management.
- Provide priority to emergency vehicles.
- Maintain fair traffic rotation using the round-robin approach.
- Demonstrate the practical application of DSA concepts in real-world problems.

## 🛠️ Technologies Used

| Technology | Purpose |
|---|---|
| C++ | Core programming and traffic management logic |
| STL Deque | Vehicle queue management |
| HTML | Web interface |
| CSS | Interface styling |
| JavaScript | Frontend interactions and simulation |

## 🧠 Data Structures & Concepts Used

**1. Deque (Double-Ended Queue)**

A deque allows insertion and deletion from both ends.

- `push_back()` – Adds normal vehicles at the rear.
- `push_front()` – Adds emergency vehicles at the front.
- `pop_front()` – Removes vehicles when they pass the signal.
- `front()` – Accesses the first vehicle.
- `empty()` – Checks whether a lane is empty.

**2. Round-Robin Scheduling**

Traffic signals rotate in the following order:

North → East → South → West → North

This ensures fair opportunities for all four directions.

**3. STL Containers**

- `map` – Stores vehicle queues for different directions.
- `vector` – Maintains the order of traffic lanes.
- `deque` – Manages vehicles in each lane.

## ⚙️ Key Features

- 🚗 **Normal Vehicle Management:** Adds vehicles at the rear of the queue.
- 🚑 **Emergency Vehicle Priority:** Inserts emergency vehicles at the front.
- 🚦 **Four-Way Traffic Simulation:** Manages North, East, South, and West lanes.
- 🔄 **Automatic Signal Rotation:** Follows a round-robin scheduling mechanism.
- 🚘 **Vehicle Processing:** Allows up to five vehicles to pass during one processing cycle.
- 📊 **Traffic Status:** Displays waiting vehicles and their order in each lane.
- 🔁 **Reset Function:** Clears all queues and restores the initial system state.

## 🔄 System Workflow

1. Initialize four separate deques for North, East, South, and West.
2. Add normal vehicles using `push_back()`.
3. Add emergency vehicles using `push_front()`.
4. Check for emergency priority.
5. Process up to five vehicles from the selected lane using `pop_front()`.
6. Rotate the signal according to the round-robin sequence.
7. Display the updated traffic status.
8. Repeat until the user exits the system.

## ⏱️ Time Complexity

| Operation | Time Complexity |
|---|---|
| Add Normal Vehicle | O(1) per vehicle |
| Add Emergency Vehicle | O(1) |
| Remove Vehicle | O(1) |
| Check Empty Queue | O(1) |
| Display Traffic Status | O(N) |

*Note: Adding multiple vehicles takes O(k), where k is the number of vehicles added.*

## 🧪 Testing & Results

The system was tested with different scenarios:

- Adding multiple normal vehicles to a lane.
- Checking emergency vehicle priority.
- Processing heavy traffic with more than five vehicles.
- Processing an empty lane.
- Verifying round-robin signal rotation.
- Resetting the complete system.

**Expected Outcome:** The system maintains vehicle order, prioritises emergency vehicles, limits vehicle processing per cycle, and ensures fair signal rotation.

## 🚀 Future Enhancements

- Integration with real-time traffic sensors.
- Dynamic green signal timing based on queue length.
- Camera-based vehicle detection.
- AI-based traffic prediction and optimisation.
- Integration of multiple traffic intersections.
- Live emergency vehicle detection and route prioritisation.

## 👩‍💻 Project Team

**Developed By:**
Rakhi Kumari (25BCS12333)
Aditi Kukreja (25BCS10021)
Diksha Kamboj (25BCS12095)

**Department:** Computer Science and Engineering  
**University:** Chandigarh University  
**Project Type:** Data Structures & Algorithms Project  
**Academic Session:** 2026

## 📚 References

- [GeeksforGeeks – Deque Data Structure](https://www.geeksforgeeks.org/deque-cpp-stl/)
- [C++ Reference – std::deque](https://en.cppreference.com/w/cpp/container/deque)
- Fundamentals of Data Structures – Ellis Horowitz and Sartaj Sahni.

---

### ⭐ Conclusion

The Traffic Signal Queue Management System demonstrates how fundamental data structures such as Deque can be applied to solve practical traffic management problems. By combining FIFO vehicle processing, emergency priority, and round-robin scheduling, the project provides a simple and efficient simulation of a four-way traffic intersection.
