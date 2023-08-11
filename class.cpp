/*
Name: William Wuliang
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Project 3

Program Description: 
Grade Calculator - class.cpp
Obtains the class statistics
*/

#include "class.hpp"

// Default constructor
Class::Class(){
    average = 0.0;
    median = 0.0;
    standardDeviation = 0.0;
}

// Constructor to initialize a student object with data
Class::Class(vector<double> grades,double avg, double med, double std){
    this -> classGrades = grades;
    this -> average = avg;
    this -> median = med;
    this -> standardDeviation = std;
}

// Getter functions
vector<double> Class::getClassGrades(){
    return classGrades;
}

string Class::getStringUntilComma(string& str){
    string res = str.substr(0, str.find(','));
    str = str.substr(str.find(',') + 1);
    return res;
}

// Calculate and store the overall grades of all students
void Class::calculateClassOverallGrades(string filename) {
    ifstream file(filename);

    if (file.fail()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1); // exit if failed to open the file
    }

    // Read the header line and extract it
    string header;
    getline(file, header);

    // Create a string variable called line to read each line of the CSV file
    string line;

    // Calculate and store overall grades for all students
    while (getline(file, line)) {
        // Create a copy of the line to be manipulated to extract the information
        string lineCopy = line;

        // Modify the line by using the helper function and to extract individual data from the line
        string first_name = getStringUntilComma(lineCopy);
        string last_name = getStringUntilComma(lineCopy);
        string SID = getStringUntilComma(lineCopy);

        // Read grades for this student from the CSV file
        Grades grades;
        vector<double> studentGrades = grades.readCSVFileGrades(filename, first_name, last_name, SID);

        // Calculate and store overall grade
        double overallGrade = grades.calculateFinalGrade(studentGrades);
        classGrades.push_back(overallGrade);
    }

    // Close the file after reading
    file.close();
}

double Class::getClassAverage(){ 
    double total = 0.0;
    for (int i = 0; i < classGrades.size(); i++) {
        total += classGrades[i];
    }

    average = total / classGrades.size();
    return average; 
}

double Class::getClassMedian(){ 
    // Sort the overall grades in order of least to greatest
    vector<double> grades = classGrades; 
    for (int i = 0; i < grades.size(); i++) {
        for (int j = i + 1; j < grades.size(); j++) {
            if (grades[i] > grades[j]) {
                double temp = grades[i];
                grades[i] = grades[j];
                grades[j] = temp;
            }
        }
    }

    // Calculate the median based on the number of grades
    if (grades.size() % 2 == 0){
        // If the number of grades is even, the median is the average of the two middle values
        int middleIndex = grades.size() / 2;
        median = (grades[middleIndex - 1] + grades[middleIndex]) / 2.0;
    } 
    // Else, if the number of grades is odd, the median is the middle value
    int middleIndex = grades.size() / 2;
    median = grades[middleIndex];

    return median; 
}

double Class::getClassStandardDeviation(){ 
    double average = getClassAverage();

    // Calculate the sum of squared differences between each grade and the mean
    double squaredDifferencesSum = 0.0;
    for (int i = 0; i < classGrades.size(); ++i){
        double difference = classGrades[i] - average;
        squaredDifferencesSum += (difference * difference);
    }

    // Calculate the variance (average of squared differences)
    double variance = squaredDifferencesSum / classGrades.size();

    // Calculate the standard deviation (square root of the variance)
    standardDeviation = sqrt(variance);

    return standardDeviation; 
}

void Class::displayClassStatistics(){
    cout << endl;
    cout << "Class' Statistics:" << endl;
    cout << "------------------" << endl;
    cout << "Class Size: " << classGrades.size() << " students" << endl;
    cout << "Class Average: " << getClassAverage() << endl;
    cout << "Class Median: " << getClassMedian() << endl;
    cout << "Class Standard Deviation: " << getClassStandardDeviation() << endl;
}