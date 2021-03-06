#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Main 
{
private:
	string temp_name, temp_password, temp_employee_number, temp_account_type, Answers, student_name, student_admission_no, student_age, student_fee_status, admin_name, admin_employee_number, admin_salary, admin_password, temp_name_of_file;
public:
	void Confirm_Identity_Of_User();
	void Register_Admin_Account();
	void Ask_Details_Of_Student();
	void Ask_User();
	void StudentInfo();
	void ResetCredentials();
	void GreetingsAfterExit();
	inline bool exist(const string&);
};
