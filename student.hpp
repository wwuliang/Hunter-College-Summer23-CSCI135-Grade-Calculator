/*
Name: William Wuliang
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Project 3

Program Description: 
Grade Calculator - student.hpp
*/

#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Student{
    private:
        string firstName;       // The first name of the student
        string lastName;        // The last name of the student
        string studentID;       // The student ID of the student
        string studentEmail;    // The student email of the student
    public: 
        /**
            @post : A Student object is created with default values
                        - firstName : ""
                        - lastName : ""
                        - studentID : ""
                        - studentEmail : ""
        */  
        Student();
        /**
            @param first_name : The first name of the student
            @param last_name  : The last name of the student
            @param SID        : The student ID of the student
            @param email      : The student email of the student
            @post             : Initializes the first name, last name, student ID, and email as the corresponding parameters.
        */
        Student(const string& first_name, const string& last_name, const string& SID, const string& email);
        
        /**
            @return : The first name of the student.
        */
        string getFirstName();
        /**
            @return : The last name of the student.
        */
        string getLastName();
        /**
            @return : The student ID of the student.
        */
        string getSID();
        /**
            @return : The email of the student.
        */
        string getEmail();

        /**
            @param str : A string read from the CSV file.
            @return    : The string value from the CSV file without the comma.
        */
        string getStringUntilComma(string& str);

        /**
            @param filename          : The name of the CSV file name.
            @param targetFirstName   : The student's first name.
            @param targetLastName    : The student's last name.
            @param SID               : The student's ID.
            @param searchMethod      : The search method chosen by the user (1 for name, 2 for ID).
            @return                  : A vector of Student objects containing the student's information.
            @post                    : The user will provide a CSV file and choose a search method to either search 
         *                            for a student's information by name or by their student ID.
        */
        vector<Student> readCSVFileStudent(string filename, string targetFirstName, string targetLastName, string SID, int searchMethod);
        /**
            @param filename      : The name of the CSV file.
            @param choiceStudent : The search method chosen by the user (1 for name, 2 for ID).
            @return              : A vector of Student objects containing the student's information.
         */
        vector<Student> searchStudent(const string& filename, int choiceStudent);

        /**
            @param studentVector : A vector of Student objects.
            @post                : Display the student information including first name, last name, student ID, and email
                                   for each student in the vector.
         */
        void displayStudentInfo(const vector<Student>& studentVector);
};

#endif