# StudentOS

StudentOS is a student productivity application designed to help students organize academic responsibilities, manage their time, and decide what to work on based on their workload and availability.

The goal is to go beyond a traditional to-do list by combining task management, course organization, priority calculation, and daily planning in one application.

> **Status:** StudentOS is currently in active development. The current version is a C++ command-line application, with a graphical interface and additional scheduling features planned for future versions.

## Current Features

The current C++ CLI supports:

- Adding and viewing courses
- Adding and viewing academic tasks
- Tracking deadlines and estimated task duration
- Calculating task priorities
- Recommending what task to work on
- Generating a basic daily work plan
- Input validation for user entries

## How It Works

StudentOS stores information about a student's courses and tasks, including:

- Course
- Task name
- Days until deadline
- Estimated completion time

This information is used to calculate task priorities and help determine which responsibilities should be addressed first.

## Roadmap

StudentOS is being developed incrementally. Planned features include:

- Graphical user interface
- User accounts and login
- Persistent storage for courses, tasks, and schedules
- Calendar and agenda system
- Support for non-academic commitments and personal activities
- Availability-aware daily schedule generation
- Improved task-priority algorithms
- AI/ML-assisted planning and recommendations

## Technologies

**Current**
- C++
- Object-Oriented Programming
- Git / GitHub

**Planned**
- GUI framework
- Database / persistent storage
- AI/ML integration

## Running Locally

Clone the repository:

```bash
git clone https://github.com/francessola/StudentOS.git
```

Navigate into the project:

```bash
cd StudentOS
```

Compile:

```bash
g++ main.cpp -o StudentOS
```

Run:

**Windows**
```bash
StudentOS.exe
```

**Linux/macOS**
```bash
./StudentOS
```

## Project Vision

StudentOS is intended to become a centralized planning tool that understands both a student's academic workload and their available time. Rather than simply displaying a list of assignments, the application aims to help students answer a more practical question:

**What should I work on, and when should I work on it?**