# Hunter College's CSCI 135 Grade Calculator

Grade Calculator is a simple tool that allows an instructor from Hunter College's CSCI 13500 Summer 2023 course to obtain a student's information and calculate the overall grade they will receive
in the course. The student's final letter grade is calculated using Hunter College's grading structure (https://hunter.cuny.edu/students/registration/records-and-transcripts/grading-structure/).
The program will additionally provide the class statistics (class size, mean, median, and standard deviation) for the instructor to see how the student compares to the overall class, as well as evaluate the class' overall
performance. 

## Additional Notes

- The grading structure is ONLY applicable to the Summer 2023 CSCI 13500 course at Hunter College
- To use the program effectively, ensure that you enter student information and grades in the provided sample CSV file, "grades.csv".
    - If there are missing grades for any category, input 0.

## Compilation and Execution

1. Download the following files:
  - main.cpp
  - student.hpp
  - student.cpp
  - grades.hpp
  - grades.cpp
  - class.hpp
  - class.cpp
  - grades.csv (This CSV file can be replaced with your own CSV file filled with the student's information and grades)

2. Open a terminal and execute the following command: _g++ main.cpp student.cpp grades.cpp class.cpp && ./a.out_

## How to use the program
1. The program will first prompt you to enter the name of your CSV file containing all your students' grades and information
2. The program will then ask you to choose a choice between entering the student's name or EMPLID by entering the values of 1 or 2.
    - If you want to calculate the grade of a student using their first and last name, enter 1.
    - If you want to calculate the grade of a student using their student ID, enter 2.
3. If you choose to enter the student's first and last name, the program will ask for the first name first, and then the last name (DO NOT ENTER THE FULL NAME).
    - If you choose to enter the student's ID, enter the student's ID.
4. The program will finally print out the student's total points earned in each category and their final grade earned. 
    - The program will also print out the class statistics containing the size of the class, average, median, and standard deviation.

## Sample Output
Enter your CSV file name: grades.csv

Enter 1 to search for a student by their first and last name.
Enter 2 to search for a student by their ID.
Enter your choice: 1

Enter the student's first name: Eric
Enter the student's last name: Cartman

Student Information:
----------------------
First Name: Eric
Last Name: Cartman
SID: 11111111
Email: eric.cartman@myhunter.cuny.edu

Student's Total Points:
-----------------------
Midterm Grade: 60
Final Grade: 80
Project 1 Grade: 56
Project 2 Grade: 0
Project 3 Grade: 4
Lab Quiz Grade: 11.9
Lab Grade: 186.8
Classwork Grade: 3.5
Homework Grade: 21.5

Student's Overall Grade:
------------------------
Overall Final Grade: 57.05%
Overall Letter Grade: F

Class' Statistics:
------------------
Class Size: 5 students
Class Average: 75.42
Class Median: 71.45
Class Standard Deviation: 14.13
