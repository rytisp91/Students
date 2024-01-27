#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <fstream>

class Student {
private:
    std::string Name, Surname;
    std::vector<int> HW;
    int Exam;
    float AvgRes;
    float MedRes;

public:
    Student();
    Student(std::string N, std::string S, std::vector<int> H, int E);
    Student(const Student& A);
    Student& operator=(const Student& A);
    ~Student();
    float Avg();
    float Med();
    void Result();
    //setters
    inline void SetName(std::string N) { Name = N; };
    inline void SetSurname(std::string S) { Surname = S; }
    inline void SetHW(std::vector<int> Vec) { HW = Vec; };
    inline void SetExam(int n) { Exam = n; };
    friend std::ostream& operator<<(std::ostream& out, const Student& A);
    friend std::istream& operator>>(std::istream& in, Student& A);
};

int minimum(int a, int b);
void manualEnter();
void generateStudents();
void generateStudentsFromInputFile(const std::string& filename, int numberOfStudents);
