#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include"User.h"
#include<vector>
#include"Student.h"
using namespace std;
class Teacher : public User
{
public: 
      vector<int> classes_they_teach;
      string subject;
      Teacher( vector<int> classes_they_teach, string subject):User(fname,lname,ID) {
          this->classes_they_teach = classes_they_teach;
          this->subject = subject;
      }
      Teacher() {

      }
      ~Teacher() {

      }
};