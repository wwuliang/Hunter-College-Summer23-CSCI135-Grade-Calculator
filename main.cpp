/*
Name: William Wuliang
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Project 3

Program Description: 
Grade Calculator - main.cpp
*/
#include "student.hpp"
#include "grades.hpp"
#include "class.hpp"

int main(){
    // Create default class objects
    Student student;
    Grades grades;
    Class myClass;

    // Prompts the user to enter a csv file containing the students' grades
    string filename;
    cout << "Enter your CSV file name: ";
    cin >> filename;
    cout << endl;

    // Prompts the user to enter the desired student's name
    int choiceStudent;
    cout << "Enter 1 to search for a student by their first and last name." << endl;
    cout << "Enter 2 to search for a student by their ID." << endl;
    cout << "Enter your choice: ";
    cin >> choiceStudent;
    cout << endl;

    // Search the students by name or by student ID
    vector<Student> studentVector = student.searchStudent(filename, choiceStudent);

    if (!studentVector.empty()){
        vector<double> gradesVector = grades.readCSVFileGrades(filename, studentVector[0].getFirstName(), studentVector[0].getLastName(), "");

        // Display the student's information
        studentVector[0].displayStudentInfo(studentVector);

        // Display the student's grades
        grades.displayStudentTotalPoints(gradesVector);
        grades.displayStudentOverallGrade(gradesVector);


        // Display the class statistics
        myClass.calculateClassOverallGrades(filename);
        myClass.getClassGrades();
        myClass.displayClassStatistics();
    } 
}