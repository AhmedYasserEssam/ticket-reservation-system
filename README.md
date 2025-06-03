# 🎬 Cinema Ticket Reservation System

A robust and feature-rich C++ application designed for modern cinema management, offering comprehensive ticket reservation capabilities, movie scheduling, and customer relationship management.

![C++](https://img.shields.io/badge/C++-17-blue.svg)
![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux%20%7C%20macOS-lightgrey.svg)

## 📋 Table of Contents
- [Features](#-features)
- [System Architecture](#-system-architecture)
- [Installation](#-installation)

## ✨ Features

### Core Functionality
- 🎥 **Movie Management**
  - Comprehensive movie database
  - Dynamic scheduling system
  - Real-time availability tracking
  - Movie details and showtimes

- 🎫 **Reservation System**
  - Interactive seat selection
  - Multiple payment gateway support
  - Instant booking confirmation
  - Reservation modification and cancellation
  - Email notifications

- 👥 **User Management**
  - Multi-level user authentication
  - Customer profiles and history
  - Employee management system
  - Admin dashboard
  - Role-based access control

- 🏢 **Hall Management**
  - Multiple hall configurations
  - Customizable seating layouts
  - Real-time capacity monitoring
  - Maintenance scheduling

## 🏗 System Architecture

```
├── src/                    # Source files
│   ├── Admin.cpp          # Admin functionality
│   ├── Cinema.cpp         # Cinema management
│   ├── CreditCard.cpp     # Payment processing
│   ├── Customer.cpp       # Customer management
│   ├── Employee.cpp       # Employee functionality
│   ├── Hall.cpp          # Hall management
│   ├── Movie.cpp         # Movie information
│   ├── Person.cpp        # Base person class
│   ├── Reservation.cpp   # Reservation handling
│   ├── Seat.cpp          # Seat management
│   ├── Session.cpp       # Session handling
│   └── TimeTable.cpp     # Schedule management
├── include/               # Header files
├── ui/                    # User interface components
└── text files/           # Data storage
```

## 💻 Installation

### Prerequisites
- C++ compiler (GCC 7.0+ or MSVC 2019+)
- CMake 3.10+
- Git

### Build Instructions

1. **Clone the Repository**
```bash
git clone https://github.com/yourusername/ticket-reservation-system.git
cd ticket-reservation-system
```

2. **Build the Project**
```bash
# Create build directory
mkdir build && cd build

# Configure with CMake
cmake ..

# Build the project
cmake --build .
```

3. **Run the Application**
```bash
./ticket-system
```

## Dependencies
- Standard C++ Libraries
- SQLite3 (for data storage)
- OpenSSL (for secure transactions)

## Team
- Ahmed Yasser
- Patrick Boules
- Youssef Ashour
- Youssef Wael
- Youssef Ashoush
