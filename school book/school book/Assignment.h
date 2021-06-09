#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include"User.h"
#include<vector>
using namespace std;
class Assignment
{
public: string homework, subject;
	  bool done_or_not;
	  Assignment(string homework, string subject, bool done_or_not)
	  {
		  this->homework = homework;
		  this->subject = subject;
		  this->done_or_not = done_or_not;
	  }
	  Assignment() {

	  }
	  ~Assignment() {

	  }
	  void Print_info() {
		  cout << homework << " " << subject << " " << done_or_not << endl;
	  }
};

