#include "main.h"

void Main::Ask_User()
{
	this->ResetCredentials();

	cout << "1. Modify or see a student's account" << endl;
	cout << "2. Register a student's account" << endl;
	cout << "3. Register for an admin Account" << endl;
	cout << "4. Exit" << endl;
	cout << "Choose from 1 to 4 to do your respective action" << endl;
	cin >> Answers;
	if (Answers == "1")
	{
		this->StudentInfo();
	}

	else if (Answers == "2")
	{
		this->Ask_Details_Of_Student();
	}

	else if (Answers == "3")
	{
		this->Register_Admin_Account();
	}
	else if (Answers == "4")
	{
		cout << "Ok thank you for using our services" << endl;
		exit(0);
	}
}

void Main::Confirm_Identity_Of_User()
{
	this->ResetCredentials();
	cout << "Please confirm your identity before modyfying any student" << endl;
	cout << "Enter your name: \t";
	cin >> admin_name;
	cout << "Enter your password: \t";
	cin >> admin_password;
	ifstream Admin_Log(admin_name + ".txt");
	Admin_Log >> temp_account_type;
	getline(Admin_Log, temp_name);
	getline(Admin_Log, temp_password);
	if (temp_name != admin_name)
	{
		Answers = "";
		cout << "The User with this name does not exist" << endl;
		cout << "Do you want to register an admin account? Format: Y/n \t";
		cin >> Answers;
		if (Answers == "Y")
		{
			cout << "\n";
			Answers = "";
			this->Register_Admin_Account();
		}
		else if (Answers == "n")
		{
			cout << "Ok thank you for using our services" << endl;
			Answers = "";
			exit(0);
		}
	}
	else if (temp_password != admin_password)
	{
		cout << "Wrong password" << endl;
		Answers = "";
		cout << "Do you want to try again? Format: Y/n" << endl;
		cin >> Answers;
		if (Answers == "Y")
		{
			this->Confirm_Identity_Of_User();
		}

		else if (Answers == "n")
		{
			cout << "Ok thank you for using our services";
			exit(0);
		}
	}
	Admin_Log.close();
}

void Main::Register_Admin_Account()
{
	this->ResetCredentials();

	cout << "Enter the name of the employee whose admin account is to be made: \t";
	cin >> admin_name;
	cout << "Enter the employee id of the employee: \t";
	cin >> admin_employee_number;
	cout << "Enter the salary of the employee: \t";
	cin >> admin_salary;
	cout << "Enter a password for your account: \t";
	cin >> admin_password;

	ofstream Reg_Admin_Acc(admin_name + ".txt");
	Reg_Admin_Acc << "Admin Account" << endl;
	Reg_Admin_Acc << admin_name << endl;
	Reg_Admin_Acc << admin_password << endl;
	Reg_Admin_Acc << admin_employee_number << endl;
	Reg_Admin_Acc << admin_salary << endl;
	Reg_Admin_Acc.close();
	cout << "Registration of the admin is successfull" << endl;
	cout << "Do you want to continue? Format: Y/n" << endl;
	cin >> Answers;
}

void Main::Ask_Details_Of_Student()
{
	this->ResetCredentials();

	this->Confirm_Identity_Of_User();
	cout << "Enter the full name of the new student: \t";
	cin >> student_name;
	cout << "Enter the the admission no. for the new student: \t";
	cin >> student_admission_no;
	cout << "Enter the age of the new student: \t";
	cin >> student_age;
	cout << "Enter the fee status of the student which has joined: \t";
	cin >> student_fee_status;

	ofstream Student_Reg(student_name + ".txt");
	Student_Reg << student_name << endl;
	Student_Reg << student_admission_no << endl;
	Student_Reg << student_age << endl;
	Student_Reg << student_fee_status << endl;
	Student_Reg.close();
	cout << "Registeration of the student was successful \n" << endl;
	this->Ask_User();
}

void Main::StudentInfo()
{
	this->ResetCredentials();

	cout << "Please first confirm your identity" << endl;
	this->Confirm_Identity_Of_User();
	cout << "Enter the name of the student for which you want to see the information" << endl;
	cin >> student_name;
	ifstream StudInf(student_name + ".txt");
	this->ResetCredentials();
	getline(StudInf, student_name);
	getline(StudInf, student_admission_no);
	getline(StudInf, student_age);
	getline(StudInf, student_fee_status);
	

}

void Main::ResetCredentials()
{
	temp_name = "";
	temp_password = "";
	temp_employee_number = "";
	temp_account_type = "";
	admin_name = "";
	admin_employee_number = "";
	admin_salary = "";
	admin_password = "";
	Answers = "";
	student_name = "";
	student_admission_no = "";
	student_age = "";
	student_fee_status = "";
}

int main()
{

}