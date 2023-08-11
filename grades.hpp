/*
Name: William Wuliang
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Project 2

Program Description: 
Grade Calculator - grades.hpp
*/

#ifndef GRADES_HPP
#define GRADES_HPP

#include "student.hpp"
using namespace std;

class Grades{
    private:
        vector<double> student_grades;  // All of the student's grades
        vector<double> midterm;         // Student's midterm grade
        vector<double> final_exam;      // Student's final exam grade
        vector<double> project1;        // Student's project 1 grades
        vector<double> project2;        // Student's project 2 grades
        vector<double> project3;        // Student's project 3 grades
        vector<double> lab_quiz;        // Student's lab quiz grades
        vector<double> lab;             // Student's lab grades
        vector<double> classwork;       // Student's classwork grades
        vector<double> homework;        // Student's homework grades
    public:
        /**
            @post : A Grades object is created with default values.
                        - student_grades : empty vector
                        - midterm : empty vector
                        - final_exam : empty vector
                        - project1 : empty vector
                        - project2 : empty vector
                        - lab_quiz : empty vector
                        - lab : empty vector
                        - classwork : empty vector
                        - homework : empty vector
         */
        Grades();

        /**
            @param studentGrades : vector of overall student grades
            @param mtGrades      : vector of midterm exam grades
            @param feGrades      : vector of final exam grades
            @param p1Grades      : vector of project 1 grades
            @param p2Grades      : vector of project 2 grades
            @param p3Grades      : vector of project 3 grades
            @param qGrades       : vector of lab quiz grades
            @param lGrades       : vector of lab grades
            @param cwGrades      : vector of classwork grades
            @param hwGrades      : vector of homework grades
            @post                : Initializes a Grades object with specific grades.
         */
        Grades(vector<double> studentGrades, vector<double> mtGrades, vector<double> feGrades, vector<double> p1Grades, vector<double> p2Grades, vector<double> p3Grades, vector<double> qGrades, vector<double> lGrades, vector<double> cwGrades, vector<double> hwGrades);

        /**
        @param filename         : the CSV file name to read
        @param targetFirstName  : first name of the student to search for
        @param targetLastName   : last name of the student to search for
        @param targetSID        : student ID to search for
        @return                 : a vector containing the grades for the target student
        @post                   : Reads the CSV file for the given student to extract the grades
                                  and store them in their respective vectors.
         */
        vector<double> readCSVFileGrades(string filename, string targetFirstName, string targetLastName, string targetSID);

        /**
            @param str : A string read from the CSV file.
            @return    : The string value from the CSV file without the comma.
        */
        string getStringUntilComma(string &str);

        /**
            @param gradesVector : vector of grades for a specific student
            @return             : The student's raw midterm exam score.
            @post               : The raw midterm exam score is returned from the grades vector.
         */
        double getMidtermGrades(vector<double> gradesVector);

        /**
            @param gradesVector : vector of grades for a specific student
            @return             : The student's raw final exam score.
            @post               : The raw final exam score is returned from the grades vector.
         */
        double getFinalGrades(vector<double> gradesVector);

        /**
            @param gradesVector : vector of grades for a specific student
            @return             : The calculated total grade for Project 1.
            @post               : The function takes the student's raw project 1 scores from the grades vector,
                                  calculates the total score, deducts any penalty, multiplies it by the weight of the project (0.10),
                                  and scales it to a percentage value. The calculated weighted project 1 grade is returned as a percentage (0-100).
         */
        double getProject1Grades(vector<double> gradesVector);

        /**
            @param gradesVector : vector of grades for a specific student
            @return             : The calculated total grade for Project 2.
            @post               : The function takes the student's raw project 2 scores from the grades vector,
                                  calculates the total score, deducts any penalty, multiplies it by the weight of the project (0.10),
                                  and scales it to a percentage value. The calculated weighted project 2 grade is returned as a percentage (0-100).
         */
        double getProject2Grades(vector<double> gradesVector);

        /**
            @param gradesVector : vector of grades for a specific student
            @return             : The student's raw score for Project 3.
            @post               : The raw score for Project 3 is returned from the grades vector.
         */
        double getProject3Grades(vector<double> gradesVector);

        /**
            @param gradesVector : vector of grades for a specific student
            @return             : The calculated total quiz grade for the student.
            @post               : The function takes the student's raw quiz scores from the grades vector,
                                  calculates the total quiz score, multiplies it by the weight of quizzes (0.05),
                                  and scales it to a percentage value. The calculated weighted quiz grade is returned as a percentage (0-100).
         */
        double getQuizGrades(vector<double> gradesVector);

        /**
            @param gradesVector : vector of grades for a specific student
            @return             : The calculated total lab grade for the student.
            @post               : The function takes the student's raw lab scores from the grades vector,
                                  calculates the total lab score, deducts any penalty, multiplies it by the weight of labs (0.20),
                                  and scales it to a percentage value. The calculated weighted lab grade is returned as a percentage (0-100).
         */
        double getLabGrades(vector<double> gradesVector);

        /**
            @param gradesVector : vector of grades for a specific student
            @return             : The calculated total classwork grade for the student.
            @post               : The function takes the student's raw classwork scores from the grades vector,
                                  calculates the total classwork score, multiplies it by the weight of classwork (0.05),
                                  and scales it to a percentage value. The calculated weighted classwork grade is returned as a percentage (0-100).
         */
        double getClassworkGrades(vector<double> gradesVector);

        /**
            @param gradesVector : vector of grades for a specific student
            @return             : The calculated total homework grade for the student.
            @post               : The function takes the student's raw homework scores from the grades vector,
                                  calculates the total homework score, multiplies it by the weight of homework (0.05),
                                  and scales it to a percentage value. The calculated weighted homework grade is returned as a percentage (0-100).
         */
        double getHomeworkGrades(vector<double> gradesVector);

        /**
            @param gradesVector : vector of grades for a specific student
            @return             : The calculated weighted midterm grade for the student.
            @post               : The calculated weighted midterm grade is returned as a percentage (0-100).
                                  The function takes the student's raw midterm exam score from the grades vector,
                                  multiplies it by the weight of the midterm (0.20), and scales it to a percentage value.
        */
        double setMidtermGrades(vector<double> gradesVector);
        /**
            @param gradesVector : vector of grades for a specific student
            @return             : The calculated weighted final exam grade for the student.
            @post               : The calculated weighted final exam grade is returned as a percentage (0-100).
                                  The function takes the student's raw final exam score from the grades vector,
                                  multiplies it by the weight of the final exam (0.25), and scales it to a percentage value.
        */
        double setFinalGrades(vector<double> gradesVector);

        /**
            @param gradesVector : vector of grades for a specific student
            @return             : The calculated weighted grade for Project 1.
            @post               : The function takes the student's raw project 1 scores from the grades vector,
                                  calculates the total score, deducts any penalty, multiplies it by the weight of the project (0.10),
                                  and scales it to a percentage value. The calculated weighted project 1 grade is returned as a percentage (0-100).
        */
        double setProject1Grades(vector<double> gradesVector);

        /**
            @param gradesVector : vector of grades for a specific student
            @return             : The calculated weighted grade for Project 2.
            @post               : The function takes the student's raw project 2 scores from the grades vector,
                                  calculates the total score, deducts any penalty, multiplies it by the weight of the project (0.10),
                                  and scales it to a percentage value. The calculated weighted project 2 grade is returned as a percentage (0-100).
        */
        double setProject2Grades(vector<double> gradesVector);

        /**
            @param gradesVector : vector of grades for a specific student
            @return             : The calculated weighted grade for Project 3.
            @post               : The function takes the student's raw project 3 scores from the grades vector,
                                  multiplies it by the weight of the project (0.10), and scales it to a percentage value.
                                  The calculated weighted project 3 grade is returned as a percentage (0-100).
        */
        double setProject3Grades(vector<double> gradesVector);

        /**
            @param gradesVector : vector of grades for a specific student
            @return             : The calculated weighted grade for quizzes.
            @post               : The function takes the student's raw quiz scores from the grades vector,
                                  calculates the total quiz score, multiplies it by the weight of quizzes (0.05),
                                  and scales it to a percentage value. The calculated weighted quiz grade is returned as a percentage (0-100).
        */
        double setQuizGrades(vector<double> gradesVector);

        /**
            @param gradesVector : vector of grades for a specific student
            @return             : The calculated weighted grade for labs.
            @post               : The function takes the student's raw lab scores from the grades vector,
                                  calculates the total lab score, deducts any penalty, multiplies it by the weight of labs (0.20),
                                  and scales it to a percentage value. The calculated weighted lab grade is returned as a percentage (0-100).
        */
        double setLabGrades(vector<double> gradesVector);

        /**
            @param gradesVector : vector of grades for a specific student
            @return             : The calculated weighted grade for classwork.
            @post               : The function takes the student's raw classwork scores from the grades vector,
                                  calculates the total classwork score, multiplies it by the weight of classwork (0.05),
                                  and scales it to a percentage value. The calculated weighted classwork grade is returned as a percentage (0-100).
        */
        double setClassworkGrades(vector<double> gradesVector);

        /**
            @param gradesVector : vector of grades for a specific student
            @return             : The calculated weighted grade for homework.
            @post               : The function takes the student's raw homework scores from the grades vector,
                                  calculates the total homework score, multiplies it by the weight of homework (0.05),
                                  and scales it to a percentage value. The calculated weighted homework grade is returned as a percentage (0-100).
        */
        double setHomeworkGrades(vector<double> gradesVector);

        /**
            @param gradesVector : vector of grades for a specific student
            @return             : The calculated final overall grade for the student.
            @post               : The function calculates the final overall grade based on the student's weighted grades
                                  in different categories (midterm, final exam, projects, quizzes, labs, classwork, homework, etc.),
                                  sums them up, and returns the overall grade as a percentage (0-100).
        */
        double calculateFinalGrade(vector<double> gradesVector);

        /**
            @param numericGrade : final numeric grade of a student
            @return             : The corresponding letter grade based on the final numeric grade.
            @post               : The function determines the corresponding letter grade based on the given numeric grade.
                                  It returns a string representing the letter grade (A, B, C, D, or F).
         */  
        string calculateLetterGrade(double numericGrade);

        /**
            @param gradesVector : vector of grades for a specific student
            @post               : Displays the student's total points for each grade category.
         */   
        void displayStudentTotalPoints(vector<double> gradesVector);

        /**
            @param gradesVector : vector of grades for a specific student
            @post               : Displays the student's overall grade in percentage and letter grade.
        */
        void displayStudentOverallGrade(vector<double> gradesVector);
};

#endif