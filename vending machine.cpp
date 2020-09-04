/*
Project title: Automatic Vending Machine(Hot & Cold Drinks)

Starting date: 25/11/2017
Finshed by:

Group Members:
		1- Md. Afique Amin zian(1631005)
		2- Nasik Sami Khan(1638153)
		3- Habib Faisal(1628223)
		4- Istiak Khan(1625203)
*/

//Header Files section
#include "./HeaderFiles/ManagerClass.h"
#include "./HeaderFiles/UserClass.h"
#include "./HeaderFiles/Libraries.h"

//definetion section
void instructions(){
	cout << "\n\n\n\t\t\t\tWelcome to Al-Sufi Vending Machine." << endl;
	cout<<  "\n\n\t\tHope You Will Be satisfied with our service."<<endl;
	cout <<"\nInstructions:" << endl;
	cout << "\t1- Manager:" << endl;
    cout << "\t\t- You have to login to your account using your username and password." << endl;
    cout << "\t\t- Username should make sure that the Capitalization(case Sensitive) is right." << endl;
	cout << "\t\t- Password should contain 6 digits." << endl;
	cout << "\t\t- You can collect your salary with any amount you want but not exceed the amount in the Account." << endl;
	cout << "\t\t- You can Refill this Vending machine with any amount from 1 - 20 Cans." << endl;
	cout << "\t\t- You can check how many Cans has been sold." << endl;


	cout << "\n\t2- Customer:" << endl;
	cout << "\t\t- You can buy Cans with any amount you want but not exceed 20(Maximum) Cans." << endl;
	cout << "\t\t- If you don't have enough money you can left any type of can and take another." << endl;
	cout << "\t\t- You can insert money either coins or notes." << endl;
	cout << "\t\t- Once you finish your transactions Please check your Balance." << endl;

	cout << "\n\t3- Both Manager and Customers:" << endl;
	cout << "\t\t- Please choose only the transaction that already displayed because the program will close automatically after 10 Wrong inputs" << endl;

	cout << "\n\t\t\t\t Please Press 'Enter' to continue.." << endl;
	cin.get();
	system("cls");
}

void openingTheProgram(){

	system("cls");

    string choice;

	cout << "\n\n\t\t\t\tWelcome to Al-Sufi Vending Machine." << endl;
	cout << "\nPlease use one of the following transactions: " << endl;
	cout << "\n1 - Customer" << endl;
	cout << "2 - Manager" << endl;
	cout << "\nYour transaction: ";

	cin >> choice;
	//Checking the input whether is it valid or not.
	if (choice != "1" && choice != "2"){
		cout << "\nInvalid Input" << endl;
		Sleep(1000);
		openingTheProgram();
	}

    CustomerClass CuC;
    ManagerClass MaC;

    if(choice == "1")
		CuC.GetUsersOrder();
	else if(choice == "2")
		MaC.GetManagerDetails();
}

using namespace std;
int main(){
	instructions();
    openingTheProgram();
}
