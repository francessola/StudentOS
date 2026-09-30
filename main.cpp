#include <iostream>
#include <string>
#include <vector>

struct Task {
    std::string name;
    std::string course;
    int daysUntilDeadline;
    int estimatedMinutes;
};

struct Course {
    std::string name;
    std::string code;
};

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
            std::cout << "\n--- Your Tasks ---\n";

            if (tasks.empty()) {
                std::cout << "No tasks added yet.\n";
            }
            else {
                for (int i = 0; i < tasks.size(); i++) {
                    std::cout << i + 1 << ". " << tasks[i].name << "\n";
                    std::cout << " Course: " << tasks[i].course << "\n";
                    std::cout << " Deadline: " << tasks[i].daysUntilDeadline << " days\n";
                    std::cout << " Estimated time: " << tasks[i].estimatedMinutes << " minutes\n";
                }
            }
        }

        else if (option == 2) {
            
            // 1. Make sure courses exist
            if (courses.empty()) {
                std::cout << "\nNo courses available. Please add a course first.\n";
                continue;
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
            std::cout << "Days until deadline: ";

            while (!(std::cin >> newTask.daysUntilDeadline) || newTask.daysUntilDeadline < 0) {
                std::cout << "Invalid input. Please enter a valid number: ";
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
            
            // 10. Save task
            tasks.push_back(newTask);
            std::cout << "Tasks added successfully\n";
        }

        else if (option == 3) {
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

        else if (option == 4) {
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