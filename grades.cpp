/*
Name: William Wuliang
Course: CSCI-135
Instructor: Sadab Hafiz
Assignment: Project 3

Program Description: 
Grade Calculator - grades.cpp
Obtains the student's grades
*/

#include "grades.hpp"

Grades::Grades(){}

Grades::Grades(vector<double> studentGrades, vector<double> mtGrades, vector<double> feGrades, vector<double> p1Grades, vector<double> p2Grades, vector<double> p3Grades, vector<double> qGrades, vector<double> lGrades, vector<double> cwGrades, vector<double> hwGrades){
    this -> student_grades = studentGrades;
    this -> midterm = mtGrades;
    this -> final_exam = feGrades;
    this -> project1 = p1Grades;
    this -> project2 = p2Grades;
    this -> project3 = p3Grades;
    this -> lab_quiz = qGrades;
    this -> lab = lGrades;
    this -> classwork = cwGrades;
    this -> homework = hwGrades;
}

// Helpfer function to extract each value in the CSV file
string Grades::getStringUntilComma(string &str){
    string res = str.substr(0, str.find(','));
    str = str.substr(str.find(',') + 1);
    return res;
}

// Read through the CSV file and store the grades into a vector to find a target student by their name
vector<double> Grades::readCSVFileGrades(string filename, string targetFirstName, string targetLastName, string targetSID){
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
    vector<Student> studentInfo;
    vector<double> studentGrades;

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
        if ((first_name == targetFirstName && last_name == targetLastName) || (SID == targetSID)){
            studentInfo.push_back(Student(first_name, last_name, SID, email));
            for (int i = 0; i < 113; i++){
                studentGrades.push_back(stod(getStringUntilComma(lineCopy)));
            }
            studentFound = true;
        }
    }

    if (studentFound == false){
        cout << "Sudent not found." << endl;
    }

    // Close the file after reading
    file.close();

    // Return the student vector
    return studentGrades;
}

// Getter functions to access the grades
double Grades::getMidtermGrades(vector<double> gradesVector){
    return gradesVector.at(0);
}

double Grades::getFinalGrades(vector<double> gradesVector){
    return gradesVector.at(1);
}

double Grades::getProject1Grades(vector<double> gradesVector){
    double p1a = gradesVector.at(2);
    double p1b = gradesVector.at(3);
    double p1c = gradesVector.at(4);
    double p1d = gradesVector.at(5);

    double total_p1 = p1a + p1b + p1c + p1d;
    return total_p1;
}

double Grades::getProject2Grades(vector<double> gradesVector){
    double p2a = gradesVector.at(7);
    double p2b = gradesVector.at(8);

    double total_p2 = p2a + p2b;
    return total_p2;
}

double Grades::getProject3Grades(vector<double> gradesVector){
    return gradesVector.at(10);
}

double Grades::getQuizGrades(vector<double> gradesVector){
    double quiz;
    for (int i = 11; i < 24; i++){
        quiz += gradesVector.at(i);
    }
    return quiz;
}

double Grades::getLabGrades(vector<double> gradesVector){
    double lab;
    for (int i = 24; i < 88; i++){
        if (gradesVector.at(i) > 5.0){
            gradesVector.at(i) = 5.0;
        }
        lab += gradesVector.at(i);
    }
    return lab;
}

double Grades::getClassworkGrades(vector<double> gradesVector){
    double classwork;
    for (int i = 88; i < 98; i++){
        classwork += gradesVector.at(i);
    }
    return classwork;
}

double Grades::getHomeworkGrades(vector<double> gradesVector){
    double homework;
    for (int i = 98; i < 113; i++){
        homework += gradesVector.at(i);
    }
    return homework;
}

// Setter function to calculate and set the final weighted grades for a specific student
double Grades::setMidtermGrades(vector<double> gradesVector){
    Grades mt;
    double pointsEarned_mt = mt.getMidtermGrades(gradesVector);
    double weightedGrade_mt = ((pointsEarned_mt / 100) * 0.20) * 100;

    return weightedGrade_mt;
}

double Grades::setFinalGrades(vector<double> gradesVector){
    Grades fe;
    double pointsEarned_fe = fe.getFinalGrades(gradesVector);
    double weightedGrade_fe = ((pointsEarned_fe / 100) * 0.25) * 100;

    return weightedGrade_fe;
}

double Grades::setProject1Grades(vector<double> gradesVector){
    Grades p1;
    double pointsEarned_p1 = p1.getProject1Grades(gradesVector);
    double p1Deduction = gradesVector.at(6);
    double weightedGrade_p1 = (((pointsEarned_p1 / 200) * 0.10) - p1Deduction) * 100;
    if (weightedGrade_p1 < 0){
        weightedGrade_p1 = 0;
    }

    return weightedGrade_p1;
}

double Grades::setProject2Grades(vector<double> gradesVector){
    Grades p2;
    double pointsEarned_p2 = p2.getProject2Grades(gradesVector);
    double p2Deduction = gradesVector.at(9);
    double weightedGrade_p2 = (((pointsEarned_p2 / 100) * 0.10)  - p2Deduction) * 100;
    if (weightedGrade_p2 < 0){
        weightedGrade_p2 = 0;
    }

    return weightedGrade_p2;
}

double Grades::setProject3Grades(vector<double> gradesVector){
    Grades p3;
    double pointsEarned_p3 = p3.getProject3Grades(gradesVector);
    double weightedGrade_p3 = ((pointsEarned_p3 / 10) * 0.10) * 100;

    return weightedGrade_p3;
}

double Grades::setQuizGrades(vector<double> gradesVector){
    Grades q;
    double pointsEarned_q = q.getQuizGrades(gradesVector);
    double weightedGrade_q = ((pointsEarned_q / 26) * 0.05) * 100;

    return weightedGrade_q;
}

double Grades::setLabGrades(vector<double> gradesVector){
    Grades l;
    double pointsEarned_l = l.getLabGrades(gradesVector);
    double weightedGrade_l = ((pointsEarned_l / 320) * 0.20) * 100;

    return weightedGrade_l;
}

double Grades::setClassworkGrades(vector<double> gradesVector){
    Grades cw;
    double pointsEarned_cw = cw.getClassworkGrades(gradesVector);
    double weightedGrade_cw = ((pointsEarned_cw / 50) * 0.05) * 100;

    return weightedGrade_cw;
}

double Grades::setHomeworkGrades(vector<double> gradesVector){
    Grades hw;
    double pointsEarned_hw = hw.getHomeworkGrades(gradesVector);
    double weightedGrade_hw = ((pointsEarned_hw / 30) * 0.05) * 100;

    return weightedGrade_hw;
}

double Grades::calculateFinalGrade(vector<double> gradesVector){
    double overallGrade = 0.0;
    overallGrade = setMidtermGrades(gradesVector) + setFinalGrades(gradesVector) + setProject1Grades(gradesVector) + setProject2Grades(gradesVector) + setProject3Grades(gradesVector) + setQuizGrades(gradesVector) + setLabGrades(gradesVector) + setClassworkGrades(gradesVector) + setHomeworkGrades(gradesVector);

    return overallGrade;
}

string Grades::calculateLetterGrade(double numeric_grade){
    string letterGrade = "";
    if (numeric_grade >= 97.5){
        letterGrade = "A+";
    }
    else if (numeric_grade >= 92.5 && numeric_grade <= 97.4){
        letterGrade = "A";
    }
    else if (numeric_grade >= 90.0 && numeric_grade <= 92.4){
        letterGrade = "A-";
    }
    else if (numeric_grade >= 87.5 && numeric_grade <= 89.9){
        letterGrade = "B+";
    }
    else if (numeric_grade >= 82.5 && numeric_grade <= 87.4){
        letterGrade = "B";
    }
    else if (numeric_grade >= 80.0 && numeric_grade <= 82.4){
        letterGrade = "B-";
    }
    else if (numeric_grade >= 77.5 && numeric_grade <= 79.9){
        letterGrade = "C+";
    }
    else if (numeric_grade >= 70.0 && numeric_grade <= 77.4){
        letterGrade = "C";
    }
    else if (numeric_grade >= 60.0 && numeric_grade <= 69.9){
        letterGrade = "D";
    }
    else if (numeric_grade >= 0.0 && numeric_grade <= 59.9){
        letterGrade = "F";
    }

    return letterGrade;
}

void Grades::displayStudentTotalPoints(vector<double> gradesVector){
    Grades grades;
    cout << endl;
    cout << "Student's Total Points:" << endl;
    cout << "-----------------------" << endl;
    cout << "Midterm Grade: " << grades.getMidtermGrades(gradesVector) << endl;
    cout << "Final Grade: " << grades.getFinalGrades(gradesVector) << endl;
    cout << "Project 1 Grade: " << grades.getProject1Grades(gradesVector) << endl; 
    cout << "Project 2 Grade: " << grades.getProject2Grades(gradesVector) << endl; 
    cout << "Project 3 Grade: " << grades.getProject3Grades(gradesVector) << endl;
    cout << "Lab Quiz Grade: " << grades.getQuizGrades(gradesVector) << endl; 
    cout << "Lab Grade: " << grades.getLabGrades(gradesVector) << endl; 
    cout << "Classwork Grade: " << grades.setClassworkGrades(gradesVector) << endl; 
    cout << "Homework Grade: " << grades.getHomeworkGrades(gradesVector) << endl; 
}

void Grades::displayStudentOverallGrade(vector<double> gradesVector){
    Grades grades;
    double finalGrade = grades.calculateFinalGrade(gradesVector);
    string letterGrade = grades.calculateLetterGrade(finalGrade);
    cout << endl;
    cout << "Student's Overall Grade:" << endl;
    cout << "------------------------" << endl;
    cout << "Overall Final Grade: " << setprecision(4) << finalGrade << "%" << endl;
    cout << "Overall Letter Grade: " << letterGrade << endl;
}