// C++ program to convert sorted 
// array to BST.
#include<bits/stdc++.h>
using namespace std;
  
class Node { 
public:
    int data; 
    Node* left; 
    Node* right; 
    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Recursive function to construct BST
Node* sortedArrayToBSTRecur(vector<int>& arr, 
                               int start, int end) {
    if(start > end) return nullptr;
    
    // Find the middle element
    int mid = start + (end - start) / 2;
    
    // Create root node
    Node* root = new Node(arr[mid]);
    
    // Create left subtree
    root->left = sortedArrayToBSTRecur(arr, start, 
                                      mid - 1);
                                      
    // Create right subtree
    root->right = sortedArrayToBSTRecur(arr, mid + 1,
                                       end);
    return root;
}

Node* sortedArrayToBST(vector<int> &arr) {
    int n = arr.size();
    return sortedArrayToBSTRecur(arr, 0, n-1);
}

void preOrder(Node* root) {
    if(root == nullptr) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main(){
    
    vector<int> arr = {1, 2, 3, 4};
    Node* root = sortedArrayToBST(arr);
    preOrder(root);
    
    return 0;
}


question 2
#include <bits/stdc++.h>
using namespace std;

// Function to check if the Sudoku matrix is valid
int isValid(vector<vector<int>> & mat) {
  
    // Arrays of unordered sets to keep track of seen
    // numbers in rows, columns, and subMatrix
    unordered_set<int> rows[9];
    unordered_set<int> cols[9];
    unordered_set<int> subMat[9];

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
          
            // Get the value at the current cell
            int val = mat[i][j];

            // For empty (0), skip to the next cell
            if (val == 0) continue;

            // Check if the value already exists
            // in the current row
            if (rows[i].find(val) != rows[i].end()) {
              
                // Duplicate found, return false
                return false;
            }
          
            // Insert the value into the current row's set
            rows[i].insert(val);

            // Check if the value already exists
            // in the current column
            if (cols[j].find(val) != cols[j].end()) {
              
                // Duplicate found, return false
                return false; 
            }
          
            // Insert the value into the current column's set
            cols[j].insert(val);

            // Calculate the index for the 3x3 box
            int idx = (i / 3) * 3 + j / 3;
          
            // Check if the value already exists
            // in the current 3x3 box
            if (subMat[idx].find(val) != subMat[idx].end()) {
              
                // Duplicate found, return false
                return false; 
            }
          
            // Insert the value into the current box's set
            subMat[idx].insert(val);
        }
    }
  
    // If no duplicates were found, return true
    return true;
}

int main() {

    vector<vector<int>> mat = {
        {9, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 5, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    cout << (isValid(mat) ? "true" : "false") << "\n";
    return 0;
}

question 3

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int removeDuplicates(vector<int>& arr) {
  
    // To track seen elements
    unordered_set<int> s; 
  
    // To maintain the new size of the array
    int idx = 0;  

    for (int i = 0; i < arr.size(); i++) {
        if (s.find(arr[i]) == s.end()) { 
            s.insert(arr[i]);  
            arr[idx++] = arr[i];  
        }
    }
 
    // Return the size of the array 
    // with unique elements
    return s.size(); 
}

int main() {
    vector<int> arr = {1, 2, 2, 3, 4, 4, 4, 5, 5};
    int newSize = removeDuplicates(arr);
    for (int i = 0; i < newSize; i++) 
        cout << arr[i] << " ";
    return 0;
}

question 4
#include <iostream>
#include <cstdlib>

using namespace std;

// Define a struct to represent a task
struct Task {
    int taskId;
    int priority;
    int executionTime;
    Task* nextTask;
};

// Define a class to manage the task scheduler
class TaskScheduler {
private:
    Task* head;

public:
    TaskScheduler() {
        head = nullptr;
    }

    // Function to insert a new task into the scheduler
    void insertTask(int taskId, int priority, int executionTime) {
        Task* newTask = new Task();
        newTask->taskId = taskId;
        newTask->priority = priority;
        newTask->executionTime = executionTime;
        newTask->nextTask = nullptr;

        if (head == nullptr || priority > head->priority) {
            newTask->nextTask = head;
            head = newTask;
        } else {
            Task* currentTask = head;
            while (currentTask->nextTask != nullptr && currentTask->nextTask->priority >= priority) {
                currentTask = currentTask->nextTask;
            }
            newTask->nextTask = currentTask->nextTask;
            currentTask->nextTask = newTask;
        }
    }

    // Function to remove a task from the scheduler
    void removeTask(int taskId) {
        if (head == nullptr) {
            cout << "Task not found." << endl;
            return;
        }

        if (head->taskId == taskId) {
            Task* tempTask = head;
            head = head->nextTask;
            delete tempTask;
            return;
        }

        Task* currentTask = head;
        while (currentTask->nextTask != nullptr) {
            if (currentTask->nextTask->taskId == taskId) {
                Task* tempTask = currentTask->nextTask;
                currentTask->nextTask = currentTask->nextTask->nextTask;
                delete tempTask;
                return;
            }
            currentTask = currentTask->nextTask;
        }

        cout << "Task not found." << endl;
    }

    // Function to display the current state of the task scheduler
    void displayTasks() {
        Task* currentTask = head;
        while (currentTask != nullptr) {
            cout << "Task ID: " << currentTask->taskId << endl;
            cout << "Priority: " << currentTask->priority << endl;
            cout << "Execution Time: " << currentTask->executionTime << endl;
            cout << endl;
            currentTask = currentTask->nextTask;
        }
    }
};

int main() {
    TaskScheduler scheduler;

    scheduler.insertTask(1, 3, 10);
    scheduler.insertTask(2, 2, 5);
    scheduler.insertTask(3, 1, 15);

    scheduler.displayTasks();

    scheduler.removeTask(2);

    scheduler.displayTasks();

    return 0;
}

question 5
#include <iostream>
#include <string>

struct Booking {
    int seatNumber;
    std::string passengerName;
    Booking* next;

    Booking(int seat, const std::string& name) : seatNumber(seat), passengerName(name), next(nullptr) {}
};

struct Compartment {
    int compartmentID;
    int totalSeats;
    Booking* bookings;

    Compartment(int id, int seats) : compartmentID(id), totalSeats(seats), bookings(nullptr) {}

    void bookSeat(const std::string& passengerName) {
        int seatNumber = 1;
        Booking* current = bookings;
        while (current && seatNumber == current->seatNumber) {
            seatNumber++;
            current = current->next;
        }

        if (seatNumber > totalSeats) {
            std::cout << "No available seats in Compartment " << compartmentID << "!" << std::endl;
            return;
        }

        Booking* newBooking = new Booking(seatNumber, passengerName);
        newBooking->next = bookings;
        bookings = newBooking;

        std::cout << "Seat " << seatNumber << " booked for " << passengerName << " in Compartment " << compartmentID << "!" << std::endl;
    }

    void cancelBooking(int seatNumber) {
        if (!bookings) {
            std::cout << "No bookings found in Compartment " << compartmentID << "!" << std::endl;
            return;
        }

        if (bookings->seatNumber == seatNumber) {
            Booking* toDelete = bookings;
            bookings = bookings->next;
            delete toDelete;
            std::cout << "Booking for seat " << seatNumber << " canceled in Compartment " << compartmentID << "!" << std::endl;
            return;
        }

        Booking* current = bookings;
        while (current->next && current->next->seatNumber != seatNumber) {
            current = current->next;
        }

        if (current->next) {
            Booking* toDelete = current->next;
            current->next = current->next->next;
            delete toDelete;
            std::cout << "Booking for seat " << seatNumber << " canceled in Compartment " << compartmentID << "!" << std::endl;
        } else {
            std::cout << "Seat " << seatNumber << " not found in Compartment " << compartmentID << "!" << std::endl;
        }
    }

    void checkAvailability() {
        int bookedSeats = 0;
        Booking* current = bookings;
        while (current) {
            bookedSeats++;
            current = current->next;
        }

        std::cout << "Compartment " << compartmentID << " has " << (totalSeats - bookedSeats)
                  << " available seats out of " << totalSeats << "." << std::endl;
    }

    ~Compartment() {
        while (bookings) {
            Booking* toDelete = bookings;
            bookings = bookings->next;
            delete toDelete;
        }
    }
};

struct Train {
    int trainID;
    Compartment** compartments;
    int compartmentCount;

    Train(int id, int numberOfCompartments, int seatsPerCompartment) : trainID(id), compartmentCount(numberOfCompartments) {
        compartments = new Compartment*[numberOfCompartments];
        for (int i = 0; i < numberOfCompartments; ++i) {
            compartments[i] = new Compartment(i + 1, seatsPerCompartment);
        }
    }

    void bookSeat(int compartmentID, const std::string& passengerName) {
        if (compartmentID <= 0 || compartmentID > compartmentCount) {
            std::cout << "Invalid Compartment ID!" << std::endl;
            return;
        }
        compartments[compartmentID - 1]->bookSeat(passengerName);
    }

    void cancelBooking(int compartmentID, int seatNumber) {
        if (compartmentID <= 0 || compartmentID > compartmentCount) {
            std::cout << "Invalid Compartment ID!" << std::endl;
            return;
        }
        compartments[compartmentID - 1]->cancelBooking(seatNumber);
    }

    void checkAvailability(int compartmentID) {
        if (compartmentID <= 0 || compartmentID > compartmentCount) {
            std::cout << "Invalid Compartment ID!" << std::endl;
            return;
        }
        compartments[compartmentID - 1]->checkAvailability();
    }

    ~Train() {
        for (int i = 0; i < compartmentCount; ++i) {
            delete compartments[i];
        }
        delete[] compartments;
    }
};

int main() {
    Train train(1, 3, 5);

    train.bookSeat(1, "Alice");
    train.bookSeat(1, "Bob");
    train.bookSeat(2, "Charlie");

    train.checkAvailability(1);
    train.checkAvailability(2);

    train.cancelBooking(1, 1);
    train.checkAvailability(1);

    train.bookSeat(1, "Diana");
    train.checkAvailability(1);

    return 0;
}
