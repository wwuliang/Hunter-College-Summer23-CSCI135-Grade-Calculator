/*
Name: William Wuliang
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Project 3

Program Description: 
Grade Calculator - class.hpp
*/

#ifndef CLASS_HPP
#define CLASS_HPP

#include "student.hpp"
#include "grades.hpp"
using namespace std;

class Class{
    private:
        vector<double> classGrades;     // A vector of each student's grades
        double average;                 // The average of the class' grades
        double median;                  // The median of the class' grades
        double standardDeviation;       // The standard deviation of the class' grades
    public: 
        /**
            @post : A Class object is created with default values
                        - classGrades : empty vector
                        - average : 0.0
                        - median : 0.0
                        - standardDeviation : 0.0
        */  
        Class();
        /**
            @param grades : A vector containing overall grades of all students in the class.
            @param avg    : The average overall grade of the class.
            @param med    : The median overall grade of the class.
            @param std    : The standard deviation of the overall grades in the class.
            @post         : Initializes the classGrades, average, median, and standardDeviation
                            with the provided values.
         */
        Class(vector<double> grades, double avg, double med, double std);
        /**
            @return : A vector containing overall grades of all students in the class.
         */
        vector<double> getClassGrades();
        /**
            @return : The average overall grade of the class.
         */
        double getClassAverage();
        /**
            @return : The median overall grade of the class.
        */
        double getClassMedian();
        /**
            @return : The standard deviation of the overall grades in the class.
        */
        double getClassStandardDeviation();
        /**
            @param str : The string read from the CSV file.
            @return    : The string value from the CSV file without the comma.
         */
        string getStringUntilComma(string& str);
        /** 
            @param filename : The name of the CSV file containing students' grades.
            @post           : The classGrades vector is populated with the overall grades of all students in the class.
         */
        void calculateClassOverallGrades(string filename);
        /**
            @post : Display class statistics, including class size, average overall grade, median overall grade,
                    and standard deviation of the overall grades in the class.
         */
        void displayClassStatistics();
};

#endif