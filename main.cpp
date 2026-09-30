#include <iostream>
#include <string>
#include <vector>

enum class Importance {
    Low,
    Medium,
    High
};

struct Date {
    int year;
    int month;
    int day;
};

struct Task {
    std::string name;
    std::string course;
    Date deadline;
    int estimatedMinutes;
    Importance importance;
};

struct Course {
    std::string name;
    std::string code;
};

std::string importanceToString(Importance importance) {

    if(importance == Importance::Low) {
        return "Low";
    }
    else if (importance == Importance::Medium) {
        return "Medium";
    }
    else {
        return "High";
    }
}

bool isLeapYear(int year) {
    if (year % 400 == 0) {
        return true;
    }
    else if (year %100 == 0) {
        return false;
    }
    else if (year %4 == 0) {
        return true;
    }
    else {
        return false;
    }
}

int daysInMonth(int month, int year) {
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    else if (month == 2) {
        if (isLeapYear(year) == true) {
            return 29;
        }
        else {
            return 28;
        }
    }
    else {
        return 31;
    }
}

void viewTasks(const std::vector<Task>& tasks) {
    std::cout << "\n--- Your Tasks ---\n";

    if (tasks.empty()) {
        std::cout << "No tasks added yet.\n";
    }
    else {
        for (int i = 0; i < tasks.size(); i++) {
            std::cout << i + 1 << ". " << tasks[i].name << "\n";
            std::cout << " Course: " << tasks[i].course << "\n";
            std::cout << " Deadline: " << tasks[i].deadline.month << "-"
                                        << tasks[i].deadline.day << "-"
                                        << tasks[i].deadline.year << "\n";
            std::cout << " Estimated time: " << tasks[i].estimatedMinutes << " minutes\n";
            std::cout << " Importance: " << importanceToString(tasks[i].importance) << "\n";
        }
    }
}

void viewCourses(const std::vector<Course>& courses) {
    std::cout << "\n--- Your Courses ---\n";

    if (courses.empty()) {
        std::cout << "No courses added yet.\n";
    }
    else {
        for (int i = 0; i < courses.size(); i++) {
            std::cout << i + 1 << ". " << courses[i].name << "\n";
            std::cout << " Code: " << courses[i].code << "\n";
        }
    }
}

void addCourse(std::vector<Course>& courses) {
    Course newCourse;
    std::cout << "\n--- Add Course ---\n";

    std::cout << "Course name: ";
    std::cin.ignore();
    std::getline(std::cin, newCourse.name);

    std::cout << "Course code: ";
    std::getline(std::cin, newCourse.code);

    courses.push_back(newCourse);

    std::cout << "Course added successfully!\n";

}

void addTask(std::vector<Task>& tasks, const std::vector<Course>& courses) {

    // 1. Make sure courses exist
    if (courses.empty()) {
        std::cout << "\nNo courses available. Please add a course first.\n";
        return;
    }

    // 2. Create a new Task
    Task newTask;

    std::cout << "\n--- Add Task ---\n";

    // 3. Get task name
    std::cout << "Task name: ";
    std::cin.ignore();
    std::getline(std::cin, newTask.name);

    // 4. Show available courses
    std::cout << "\nSelect a course:\n";
            
    for (int i = 0; i < courses.size(); i++) {
        std::cout << i + 1 << ". "
                    << courses[i].name
                    << " (" << courses[i].code << ")\n";
    }

    // 5. Get course selection
    int courseChoice;

    std::cout << "Course: ";

    while (!(std::cin >> courseChoice) || courseChoice < 1 || courseChoice > courses.size()) {
                
        std::cout << "Invalid course. Please select a valid number: ";

        std::cin.clear();
        std::cin.ignore(10000, '\n');
     }

    newTask.course = courses[courseChoice - 1].name;

    // 6. Validate courseChoice


    // 7. Store selected course


    // 8. Deadline

    // Year
    std::cout << "Deadline year: ";
    
    while (!(std::cin >> newTask.deadline.year) ||
            newTask.deadline.year <= 0) {

        std::cout << "Invalid year. Please enter a valid year: ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
    
    // Month
    std::cout << "Deadline month: ";

    while (!(std::cin >> newTask.deadline.month) ||
            newTask.deadline.month < 1 ||
            newTask.deadline.month > 12) {
            
        std::cout << "Invalid month. Please enter a number from 1 to 12; ";

        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    // Find maximum number of days for selected month
    int maxDays = daysInMonth(newTask.deadline.month, newTask.deadline.year);

    // Day
    std::cout << "Deadline day: ";
    
    while (!(std::cin >> newTask.deadline.day) || 
            newTask.deadline.day < 1 ||
            newTask.deadline.day > maxDays) {

        std::cout << "Invalid day. Please enter a number from 1 to " << maxDays << ": ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');

    }

    // 9. Estimated time
    std::cout << "Estimated time (minutes): ";

    while (!(std::cin >> newTask.estimatedMinutes) || newTask.estimatedMinutes <= 0) {
        std::cout << "Invalid input. Please enter a number greater than 0: ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    // 10. Importance
    int importanceChoice;

    std::cout << "\nImportance:\n"
                << "1. Low\n"
                << "2. Medium\n"
                << "3. High\n"
                << "Select importance: ";

    while (!(std::cin >> importanceChoice) ||
            importanceChoice < 1 ||
            importanceChoice > 3) {

                std::cout << "Invalid importance. Please select 1, 2, or 3: ";

                std::cin.clear();
                std::cin.ignore(10000, '\n');

            }
    

    if (importanceChoice == 1) {
        newTask.importance = Importance::Low;
    }
    else if (importanceChoice == 2) {
        newTask.importance = Importance::Medium;
    }
    else {
        newTask.importance = Importance::High;
    }

    // 11. Save task
    tasks.push_back(newTask);
    std::cout << "Tasks added successfully\n";
}

int main() {

    std::vector<Task> tasks;
    std::vector<Course> courses;
    
    while (true) {


        std::cout << "1. View tasks\n"
                    << "2. Add task\n"
                    << "3. View Courses\n"
                    << "4. Add Course\n"
                    << "5. Calculate Priorities\n"
                    << "6. What Should I Work On?\n"
                    << "7. Plan My Day\n"
                    << "8. Exit\n"
                    << "Select an option: ";
   
        int option;
        
        if (!(std::cin >> option)) {
            std::cout << "Invalid input. Please enter a number.\n";

            std::cin.clear();
            std::cin.ignore(10000, '\n');

            continue;
        }

        if (option == 1) {
            
            viewTasks(tasks);

        }

        else if (option == 2) {
            
           addTask(tasks, courses);

        }

        else if (option == 3) {
            
            viewCourses(courses);

        }

        else if (option == 4) {
            
            addCourse(courses);
            
        }

        else if (option == 5) {
            std::cout << "Calculating your priorities...\n";
        }

        else if (option == 6) {
            std::cout << "Planning what you should work on...\n";
        }

        else if (option == 7) {
            std::cout << "Planning your day...\n";
        }

        else if (option == 8) {
            std::cout << "Exiting...\n";
            break;
        }

        else {
            std::cout << "Invalid option\n";
        }
    }


    return 0;
}