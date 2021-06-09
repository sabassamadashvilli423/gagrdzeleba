#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include"User.h"
#include<vector>
#include"Assignment.h"
using namespace std;
class Student:public User
{
public:
      Assignment a;
      vector<int> grade;
      Student(Assignment a, vector<int> grade) :User(fname, lname, ID) {
          this->grade = grade;
          this->a = a;
      }
      Student() {

      }
      ~Student() {

      }
};

