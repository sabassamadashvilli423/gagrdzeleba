#include "User.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
void User::Add() {
   // ifs>>
}
void User:: View_adm()
{
    ofs << fname << " " << lname << " " << ID << endl;
}
void User:: View_tea()
{
    ofs << fname << " " << lname << " " << ID<< " " << subject << endl;
    for (int i = 0; i < classes_they_teach.size(); i++) {
        ofs<<classes_they_teach[i];
}
    
}
void User:: View_stu()
{
    ofs << fname << " " << lname << " " << ID << " " << subject << endl;
}
