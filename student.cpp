/*
Name: William Wuliang
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Project 3

Program Description: 
Grade Calculator - student.cpp
Obtains the students information
*/

#include "student.hpp"

Student::Student(){}

// Constructor to initialize a student object with data
Student::Student(const string& first_name, const string& last_name, const string& SID, const string& email){
    this -> firstName = first_name;
    this -> lastName = last_name;
    this -> studentID = SID; 
    this -> studentEmail = email;
}

// Getter functions
string Student::getFirstName(){ 
    return firstName; 
}

string Student::getLastName(){ 
    return lastName; 
}

string Student::getSID(){ 
    return studentID; 
}

string Student::getEmail(){ 
    return studentEmail; 
}

// Helper functions used to obtain the necessary information from the dataset
string Student::getStringUntilComma(string &str){
    string res = str.substr(0, str.find(','));
    str = str.substr(str.find(',') + 1);
    return res;
}

// Read through the CSV file and store the information into a vector to find a target student by their name
vector<Student> Student::readCSVFileStudent(string filename, string targetFirstName, string targetLastName, string targetSID, int searchMethod){
    ifstream file(filename);

    if (file.fail()){
        cerr << "File cannot be opened for reading." << endl;
        exit(1); // exit if failed to open the file
    }

    // Read the header line and extract it
    string header;
    getline(file, header);

    // Create a string variable called line to read each line of the CSV file
    string line;

    // Create a vector to store the Student objects
    vector<Student> studentVector;

    // Boolean variable to indicate if the student is found
    bool studentFound = false;

    // Read each line of the csv file
    while (getline(file, line)){
        // Create a copy of the line to be manipulated to extract the information
        string lineCopy = line;

        // Modify the line by using the helper function and to extract individual data from the line
        string first_name = getStringUntilComma(lineCopy);
        string last_name = getStringUntilComma(lineCopy);
        string SID = getStringUntilComma(lineCopy);
        string email = getStringUntilComma(lineCopy); 

        // Store the necessary information into the Student vector
        if ((searchMethod == 1 && first_name == targetFirstName && last_name == targetLastName) || (searchMethod == 2 && SID == targetSID)){
            studentVector.push_back(Student(first_name, last_name, SID, email));
            studentFound = true;
        }
    }

    if (studentFound == false){
        cout << "Sudent not found." << endl;
    }

    // Close the file after reading
    file.close();

    return studentVector;
}

vector<Student> Student::searchStudent(const string& filename, int choiceStudent) {
    vector<Student> studentVector;

    if (choiceStudent == 1){
        string studentFirstName;
        string studentLastName;

        cout << "Enter the student's first name: ";
        cin >> studentFirstName;
        cout << "Enter the student's last name: ";
        cin >> studentLastName;

        // Create Student object with the provided data
        Student student(studentFirstName, studentLastName, "", "");

        // Read student data based on the search method
        studentVector = student.readCSVFileStudent(filename, studentFirstName, studentLastName, "", choiceStudent);
    }
    else if (choiceStudent == 2){
        string studentSID;
        cout << "Enter the student's ID: ";
        cin >> studentSID;

        // Create Student object with the provided data
        Student student("", "", studentSID, "");

        // Read student data based on the search method
        studentVector = student.readCSVFileStudent(filename, "", "", studentSID, choiceStudent);
    }

    return studentVector;
}

void Student::displayStudentInfo(const vector<Student>& studentVector){
    cout << endl;
    cout << "Student's Information:" << endl;
    cout << "----------------------" << endl;
    for (int i = 0; i < studentVector.size(); i++){
        Student student = studentVector.at(i);
        cout << "First Name: " << student.getFirstName() << endl;
        cout << "Last Name: " << student.getLastName() << endl;
        cout << "SID: " << student.getSID() << endl;
        cout << "Email: " << student.getEmail() << endl;
    }
}