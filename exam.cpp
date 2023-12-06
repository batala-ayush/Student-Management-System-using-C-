#include <iostream> 
#include <fstream> 
#include <string> 
#include <conio.h> 

#define CLEAR_COMMAND "cls" 

using namespace std; 

struct Student { 
string name; 
int id; 
string residence; 
string nationality; 
}; 

const int MAX_STUDENTS = 5; 
Student students[MAX_STUDENTS]; 
int numStudents = 0;

void AddStudent() { 
	system(CLEAR_COMMAND); 
	
	if (numStudents >= MAX_STUDENTS) { 
		cout << "Maximum number of students reached.\n"; 
		cout << "Press any key to continue..."; 
		_getch(); // Wait for user input 
		return; 
		} 
	
	cout << "----- Add Student -----\n"; 
	cout << "Name: "; 
	getline(cin, students[numStudents].name); 
	
	int newId; 
	bool isDuplicateId; 
	do { 
		isDuplicateId = false; 
		cout << "ID: "; 
		cin >> newId; 
		cin.ignore(); // Ignore the remaining newline character 
		
		for (int i = 0; i < numStudents; ++i) { 
			if (students[i].id == newId) { 
				cout << "Error: Student with the same ID already exists.\n"; 
				isDuplicateId = true; 
				break; 
				} 
			} 
		} while (isDuplicateId); 
	
	students[numStudents].id = newId; 
	
	cout << "Residence : "; 
	getline(cin, students[numStudents].residence); 
	cout << "Nationality: "; 
	getline(cin, students[numStudents].nationality); 
	
	numStudents++; 
	cout << "Student information added successfully.\n"; 
	
	// Save the records automatically after adding a new student 
	ofstream outFile("student_records.txt"); 
	if (outFile.is_open()) { 
		for (int i = 0; i < numStudents; ++i) { 
			outFile << students[i].name << "\n"; 
			outFile << students[i].id << "\n"; 
			outFile << students[i].residence << "\n"; 
			outFile << students[i].nationality << "\n"; 
			} 
		outFile.close(); 
		cout << "Student records saved successfully.\n"; 
		} 
	else { 
		cout << "Unable to open the file for writing.\n"; 
		} 
		
	cout << "Press any key to continue..."; 
	_getch(); 
	} 

void ViewStudentByID() { 
	system(CLEAR_COMMAND); // Clear console screen 
	
	if (numStudents == 0) { 
		cout << "No students added yet.\n"; 
		cout << "Press any key to continue..."; 
		_getch(); 
		return; 
		} 
	
	cout << "----- View Student by ID -----\n"; 
	int searchId; 
	cout << "Enter a student ID to view their information: "; 
	cin >> searchId; 
	
	bool found = false; 
	for (int i = 0; i < numStudents; ++i) { 
		if (students[i].id == searchId) { 
		system(CLEAR_COMMAND); // Clear console screen 
		cout << "----- View Student by ID -----\n"; 
		cout << "\nInformation for Student with ID " << searchId << ":\n"; 
		cout << "Name: " << students[i].name << "\n"; 
		cout << "ID: " << students[i].id << "\n"; 
		cout << "Residence: " << students[i].residence << "\n"; 
		cout << "Nationality: " << students[i].nationality << "\n"; 
		found = true; 
		break; 
		} 
	} 
	
	if (!found) { 
		cout << "\nStudent with ID " << searchId << " not found.\n"; 
		} 
	
	cout << "\nPress any key to continue..."; 
	_getch(); 
	} 

void UpdateStudent() { 
	system(CLEAR_COMMAND); // Clear console screen 
	
	if (numStudents == 0) { 
		cout << "No students added yet.\n"; 
		cout << "Press any key to continue..."; 
		_getch(); 
		return; 
		} 
	
	cout << "----- Update Student -----\n"; 
	int searchId; 
	cout << "Enter a student ID to update their information: "; 
	cin >> searchId; 
	cin.ignore(); // Ignore the remaining newline character 
	
	bool found = false; 
	for (int i = 0; i < numStudents; ++i) { 
		if (students[i].id == searchId) { 
			system(CLEAR_COMMAND); // Clear console screen 
			cout << "----- Update Student -----\n"; 
			cout << "\nCurrent Information for Student with ID " << searchId << ":\n"; 
			cout << "Name: " << students[i].name << "\n"; 
			cout << "Residence: " << students[i].residence << "\n"; 
			cout << "Nationality: " << students[i].nationality << "\n"; 
			
			cout << "\nEnter the updated information:\n"; 
			cout << "Name: "; 
			getline(cin, students[i].name); 
			cout << "Residence (Dormitory/Outside): "; 
			getline(cin, students[i].residence); 
			cout << "Nationality: "; 
			getline(cin, students[i].nationality); 
			
			// Save the records automatically after adding a new student 
			ofstream outFile("student_records.txt"); 
			if (outFile.is_open()) { 
				for (int i = 0; i < numStudents; ++i) { 
					outFile << students[i].name << "\n"; 
					outFile << students[i].id << "\n"; 
					outFile << students[i].residence << "\n"; 
					outFile << students[i].nationality << "\n"; 
					} 
					outFile.close(); 
					
					cout << "Student information updated successfully.\n"; 
					} 
			else { 
				cout << "Unable to open the file for writing.\n"; 
				} 
			found = true; 
			break; 
			} 
	} 
	
	if (!found) { 
		cout << "\nStudent with ID " << searchId << " not found.\n"; 
		} 
	
	cout << "\nPress any key to continue..."; 
	_getch(); 
	} 

void ShowAllStudents() { 
	system(CLEAR_COMMAND); // Clear console screen 
	
	if (numStudents == 0) { 
		cout << "No students added yet.\n"; 
		cout << "Press any key to continue..."; 
		_getch(); 
		return; 
		} 
	
	cout << "----- All Students’ Information -----\n"; 
	
	for (int i = 0; i < numStudents; ++i) { 
		cout << "\nInformation for Student with ID " << students[i].id << ":\n"; 
		cout << "Name: " << students[i].name << "\n"; 
		cout << "Residence: " << students[i].residence << "\n"; 
		cout << "Nationality: " << students[i].nationality << "\n"; 
		} 
	
	cout << "\nPress any key to continue..."; 
	_getch(); 
	} 

void DisplayMenu() { 
	system(CLEAR_COMMAND); 
	
	cout << "----- Student Management System -----\n"; 
	cout << "1. Add Student\n"; 
	cout << "2. View Student by ID\n"; 
	cout << "3. Update Student\n"; 
	cout << "4. Show All Students\n"; 
	cout << "5. Exit\n"; 
	cout << "--------------------------------------\n"; 
	cout << "Enter your choice: "; 
	} 

int main() { 
	int choice; 
	
	ifstream inFile("student_records.txt"); 
	if (inFile.is_open()) { 
		string line; 
		int recordCount = 0; 
		while (getline(inFile, line)) { 
			students[recordCount].name = line; 
			inFile >> students[recordCount].id; 
			inFile.ignore(); // Ignore the remaining newline character 
			getline(inFile, students[recordCount].residence); 
			getline(inFile, students[recordCount].nationality); 
			recordCount++; 
			if (recordCount >= MAX_STUDENTS) { 
				break; 
				} 
			} 
		numStudents = recordCount; 
		inFile.close(); 
		cout << "Student records loaded successfully.\n"; 
		} 
	else { 
		cout << "No existing student records found.\n"; 
		} 
	
	do { 
		DisplayMenu(); 
		cin >> choice; 
		cin.ignore(); // Ignore the remaining newline character 
		
		switch (choice) { 
			case 1: 
				AddStudent(); 
				break; 
			case 2: 
				ViewStudentByID(); 
				break; 
			case 3: 
				UpdateStudent(); 
				break; 
			case 4: 
				ShowAllStudents(); 
				break; 
			case 5: 
				cout << "Exiting the program.\n"; 
				break; 
			default: 
				cout << "Invalid choice. Please try again.\n"; 
			} 
		} while (choice != 5); 
	
	return 0; 
	}
