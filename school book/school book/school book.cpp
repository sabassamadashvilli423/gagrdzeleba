#include<iostream>
#include"Assignment.h"
#include"Student.h"
#include"Teacher.h"
#include"User.h"
#include<vector>
#include<string>
#include<algorithm>
#include<fstream>
void Add_u(User &u) {
	ifstream ifs("user.txt", fstream::app);
	ifs >> u.fname >> u.lname >> u.ID;
}
void Add_t(Teacher &t) {
	ifstream ifs("user.txt", fstream::app);
	ifs >> t.fname >> t.lname >> t.ID >> t.subject;
	for (int i = 0; i < t.classes_they_teach.size(); i++) {
		ifs >> t.classes_they_teach[i];
	}
}
void Add_s(Student &s) {
	ifstream ifs("user.txt", fstream::app);
	ifs >> s.fname >> s.lname >> s.ID;

}
void Dlt_u(vector<User> &u,string &cID) {
	for (int i = 0; i< u.size(); i++) {
		if (u[i].ID==cID) {
			u.erase(u.begin()+i);
		}
	}
}
void Dlt_t(vector<Teacher> &t, string &cID) {
	for (int i = 0; i < t.size(); i++) {
		if (t[i].ID == cID) {
			t.erase(t.begin() + i);
		}
	}
}
void Dlt_s(vector<Student> &s, string &cID) {
	for (int i = 0; i < s.size(); i++) {
		if (s[i].ID == cID) {
			s.erase(s.begin() + i);
		}
	}
}
void View_adm(vector<User> &u) {
	ofstream ofs("admins.txt");
	for (int i = 0; i < u.size(); i++)
	{
		cout << u[i].fname << " " << u[i].lname << " " << u[i].ID << endl;
	}
}
void View_std(vector<Student> &s) {
	ofstream ofs("students.txt");
	for (int i = 0; i < s.size(); i++)
	{
		cout << s[i].fname << " " << s[i].lname << " " << s[i].ID << endl;
	}
}
void View_teach(vector<Teacher> t) {
	ofstream ofs("teachers.txt");
	
	// dasamatebelia danarcheni
	for (int i = 0; i < t.size(); i++)
	{
		cout << t[i].fname << " " << t[i].lname << " " << t[i].ID << endl;
	}
}

int main() {
	ifstream fin("admins.txt");
	vector<Student> s;
	vector<Teacher> t;
	vector<Assignment> a;
	vector<User> u;
	string fname, lname, ID;
	string userType;
	User user1;
	Teacher t1;
	Student s1;
	string cID;
	cout << "which type of user would you like to log in to" << endl;
	cin >> userType;
	cout << "enter first name "<<endl;
	cin >> fname;
	cout << " enter last name " << endl;
	cin >> lname;
	cout << "enter ID " << endl;
	cin >> ID;
	while (fin >> user1.fname >> user1.lname >> user1.ID)
	{
		u.push_back(user1);
	}

	while (fin >> t1.fname >> t1.lname >> t1.ID)
	{
		t.push_back(t1);
	}

	while (fin >> s1.fname >> s1.lname >> s1.ID)
	{
		s.push_back(s1);
	}

	if (userType == "user")
	{
		for (int i = 0; i < u.size(); i++)
		{
			if (u[i].ID == ID)
			{
				if (i == u.size() - 1 && u[i].ID != ID)
				{
					cout << "this user does not exist" << endl;
					break;
				}
				cout << " WHICH LIST WOULD YOU LIKE TO SEE?" << endl << "1)	Administrators" << endl << "2)	Teachers" << endl << "3)	Students" << endl;
				int k,j; //გადასაყვანია დინამიურზე
				cin >> k;
				switch (k) {
				case 1: View_adm(u);				
				case 2: View_teach(t);
				case 3: View_std(s);
				}
				cout << "WHAT WOULD YOU LIKE TO DO NEXT ?" << endl << "1)	Add member " << endl << "2)	Delete member " << endl << " 3)	Exit" << endl;
				cin >> j;
				switch (j) {
				case 1: 
				{ 
					
					if (k == 1)
					{
						User u1;
						cin >> u1.fname >> u1.lname >> u1.ID;
						Add_u(u1);
					}
					if (k == 2)  
					{
						Teacher t1;
						cin >> t1.fname >> t1.lname >> t1.ID>>t1.subject;
						for (int i = 0; i < t1.classes_they_teach.size(); i++) {
							cin >> t1.classes_they_teach[i];
						}
					}
					if (k == 3)
					{
						Student s1;
						cin >> s1.fname >> s1.lname >> s1.ID;
						// გაგრძელება under construction
					}
				}
				case 2:
				{
					if (k == 1)
					{
						cin >> cID;
						Dlt_u(u, cID);
					}
					if (k == 2)
					{
						cin >> cID;
						Dlt_t(t, cID);
				    }
					if (k == 3)
					{
						cin >> cID;
						Dlt_s(s, cID);
					}
				}
				case 3:
					break;
				}
			}
		}
	}
	else if (userType == "teacher") 
	{
		for (int i = 0; i < t.size(); i++) 
		{
			if (t[i].ID == ID) 
			{
				if (i == t.size() - 1 && t[i].ID != ID)
				{
					cout << "this user does not exist" << endl;
					break;
				}	
				cout << "which class would you like to see" << endl;
				for (int p = 0; p < t[i].classes_they_teach.size(); p++) 
				{
					cout << t[i].classes_they_teach[p];
				}
				int o;
				cin >> o;
				switch (o) 
				{
				case 1:

				case 2:

				case 3:
					// students txt unda davshalot 3 txt_d  usershi students txt dabechdvis magivrad unda gamobechdos 1,2,3 ristvisac gamogvadgeba ukve 
					//arsebuli view_std funqcia
			    }
			}			
				
		}
	}
	else if (userType == "student") 
	{
		for (int i = 0; i < u.size(); i++) 
		{
			if (s[i].ID == ID) 
			{

			}
				// გაგრძელება under construction 
		}
	}
	else cout << "ERROR" << endl;
}
