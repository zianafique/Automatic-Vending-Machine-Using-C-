#include "./Libraries.h"

using namespace std;



//Manager Class which include all manager stuffs.
class ManagerClass{
	private:
		string username;
		string password;
	public:
		void GetManagerDetails();
		void CheckThePasswordLenght();
		void CheckTheUserNameAndPassword();
		void DisplayTransactions();
		void Transaction(string choice);
		int CheckBrandName(string);
		void RefillTheMachine();
		void continueChoice();
		void endOFProgram();
		int ChangeStringToInt(string);
		void OutPutTheSalary();	//read the salary from a file.
		void DisplayBrandsAmount();
		void DisplaySlaesHistory();	//read the sales history from a file.
};

//Prompt the user to write the username and the password.
void ManagerClass::GetManagerDetails(){
	string userName;
	string passCode;

	system("cls");

	//Greeting for the managers
	cout << "\n\t\t\tWelcome th the manager section" << endl;
	cout << "\nPlease Type valid Username And password: " << endl;
	//Getting the manager input.
	cout << "\nUserName: ";
	cin >> userName;
	cout << "Password: ";
	cin >> passCode;

	//assign the values of the user ans the pass to the private variables.
	password = passCode;
	username = userName;

	//Calling this function to make sure that the pass has lenght of 6 digits.
	CheckThePasswordLenght();
}

//Check the lenght of the password.
void ManagerClass::CheckThePasswordLenght(){
	//Changing the password from int to string.

	if (password.size() != 6){
		cout << "\nInvalid Password" << endl;
		cout << "Your password must have lenght of 6 digits" << endl;
		Sleep(3000);
		GetManagerDetails();	//Repeat again if the password does not has a lenght of 6 digits.
	}
	else
		CheckTheUserNameAndPassword();	//Calling this function to make sure that the username and pass are totally right.
}

//Check the password and the user name.
void ManagerClass::CheckTheUserNameAndPassword(){
	string managersName[4] = {"Zian", "Sami", "Leepu","Istiak"};
	string passcode[4] = {"123456", "654321", "456789","234567"};
	if(username == managersName[0] && password == passcode[0]){
		system("cls");
		cout << "\n\nWelcome Zian Nice to see you again" << endl;
		DisplayTransactions();
	}
	else if(username == managersName[1] && password == passcode[1]){
		system("cls");
		cout << "\n\nWelcome Sami Nice to see you again" << endl;
		DisplayTransactions();
	}
	else if(username == managersName[2] && password == passcode[2]){
		system("cls");
		cout << "\n\nWelcome Leepu Nice to see you again" << endl;
		DisplayTransactions();
	}
	else if(username==managersName[3]&& password==passcode[3]){
		system("cls");
		cout<<"\n\nWelcome Istiak Nice to see u again"<<endl;
		DisplayTransactions();
	}
	else{
		cout << "\nInvalid Username OR Password" << endl;
		Sleep(2000);
		GetManagerDetails();
		}
}

//Display transactions for the manager.
void ManagerClass::DisplayTransactions(){
	string choice;

	system("cls");
	cout << "\nHow can i help you sir?" << endl;
	cout << "\n1 : Sales History" << endl;
	cout << "2 :Salary" << endl;
	cout << "3 : Refill The Machine." << endl;
	cout << "4 : Exit" << endl;
	cout << "\nYour Transaction: ";
	cin >> choice;

	if (choice != "1" && choice != "2" && choice != "3" && choice != "4"){
		cout << "\nInvalid Input" << endl;
		Sleep(1000);
		DisplayTransactions();
	}

	Transaction(choice);
}

/*
This function can:
1 - Display either the salary.
2 - Get more information about the sales
	more info{
		How many cans the program has sold.
		With more specific details.
	}
3 - Can Exit from the program easily
*/
void ManagerClass::Transaction(string choice){
	string FinalChoice, choicee;

	if(choice == "1") DisplaySlaesHistory();
	else if(choice == "2")
			OutPutTheSalary();	//output the salary for one manager then give a choice to collect or leave them.
	else if(choice == "3"){
		//Refill the machine with maximum 20 Can for each brand.
		//Give the manager the ability to takr a look for the brands which need to refill.
		system("cls");

		cout << "\nPlease Choose One of the following: " << endl;
		cout << "\n1- Brands Amount" << endl;
		cout << "2- Refill The Machine" << endl;
		cout << "\nYour transaction: ";
		cin >> choicee;

		if(choicee == "1") DisplayBrandsAmount();
		else if(choicee == "2") RefillTheMachine();
		else{
			cout << "\nInvalid Input" << endl;
			Sleep(2000);
			continueChoice();
		}
	}
	else if(choice == "4"){
		Sleep(2000);
		endOFProgram();
	}
}

void ManagerClass::DisplayBrandsAmount(){
	string display;	//read from the machine and display.
	string choice;
	int n, counter = 0;
	bool ok = 0;

	system("cls");

	ifstream RMC;	//Read machine Capacity.
	RMC.open("./Files/MachineCapacity.txt");

	cout << "\n\n\n\t\t\t\tBrands Amount" << endl;
	cout << endl;
	while(RMC >> display){
		n = display.size();
		cout << display << " ";
		if(display[n-1] >= '0' && display[n-1] <= '9'){
			counter++;
			ok = 0;
		}
		if(counter == 1 && !ok){
			ok = 1;
			cout << "\b- ";
		}
		else if(counter == 2){
			counter = 0;
			cout << endl;
		}
	}
	RMC.close();

	cout << "\nPlease choose One of the following:" << endl;
	cout << "\n1- RefillTheMachine" << endl;
	cout << "2- Continue." << endl;
	cout << "\nYour transaction: ";
	cin >> choice;

	if(choice == "1"){
		Sleep(2000);
		RefillTheMachine();
	}
	else if(choice == "2"){
		Sleep(2000);
		DisplayTransactions();
	}
	else{
		cout << "\nInvalid Input" << endl;
		Sleep(2000);
		continueChoice();
	}
}

//printing the salary and check wether the manager want to collect or continue.
void ManagerClass::OutPutTheSalary(){

	system("cls");

	int num;
	string MN[4] = {
		"Zian", "Sami", "Leepu","Istiak"
	};	//Managersnames
	string name, choice;
	double salary[4] = {0.0};

	ifstream OS;	//output the salary
	OS.open("./Files/Salary.txt");

	int i = 0;
	while(OS >> num >> name >> salary[i]){
		if(name == username){
			cout << "\n\n\t\t\t\tHello Mr(s) " << name << endl;
			cout << "\t\t\t\t  Nice to see you sir" << endl;
			cout << "\n\nYour Current Salary: RM" << salary[i] << endl;
		}
		i++;
	}
	cout << "\nPlease choose one of the following" << endl;
	cout << "\n1- Collect" << endl;
	cout << "2- continue" << endl;
	cout << "\nYour transaction: ";
	cin >> choice;

	if(choice == "1"){
		ofstream WNS;	//writing the new salary.
		WNS.open("./Files/Salary.txt");

		i = 0;
		while(WNS.good()){
			if(i == 4) break;
			if(username == MN[i])
				WNS << i+1 << " " << MN[i] << " " << salary[i]-salary[i] << endl;
			else
				WNS << i+1 << " " << MN[i] << " " << salary[i] << endl;
			i++;
		}
		Sleep(2000);
		continueChoice();
	}
	else if(choice == "2")
       	DisplayTransactions();
    else{
        cout << "Invalid Input" << endl;
        Sleep(2000);
        continueChoice();
    }
}

//Ability to refill the machine with maximum 20 pieces each no matter how many it is.
void ManagerClass::RefillTheMachine(){

	system("cls");

	string brandNames[9] = {
		"CostaCoffee", "Starbucks","Nescafe","Fanta","Mocha","CocaCola","Pepsi","Americano","Milo"
	};
	int RMB[9] = {0};	//refill the brand;
	string s, brandName, Amount;	//to read from the file.
	int n, m, BrandCode, value;	//(n) for the number od the product, (m) for the number of items.

	ifstream RM;
	RM.open("./Files/MachineCapacity.txt");


	cout << "\n\nPlease Enter The following:" << endl;
	cout << "\nBrand Name: ";
	cin >> brandName;
	BrandCode = CheckBrandName(brandName);

	cout << "Amount: ";
	cin >>  Amount;
	value = ChangeStringToInt(Amount);

	//Reading from the file.
	int i = 0;
	while(RM >> n >> s >> RMB[i]){
		if(n == BrandCode){
			if(value+RMB[i] <= 20){
				cout << "\nThe Brand's Amount has been Updated" << endl;
				RMB[i] += value;
				cout << "This Brand Contains " << RMB[i] << " Pieces now." << endl;
			}
			else if(20-RMB[i] != 0){
				cout << "\nYou Can Refill this brand with " << 20-RMB[i] << " Only." << endl;
				Sleep(2000);
				continueChoice();
			}
			else if(20-RMB[i] == 0){
				cout << "\nThis brand is 20 pieces already" << endl;
				cout << "You cannot Refill This brand" << endl;
				Sleep(2000);
				continueChoice();
			}
		}
		i++;
	}
	RM.close();

	ofstream WRM;	//writing the Capacity of the machine after refill.
	WRM.open("./Files/MachineCapacity.txt");

	i = 0;
	while(WRM.is_open()){
		if(i == 9) break;
		WRM << i+1 << " " << brandNames[i] << " " << RMB[i] << endl;
		i++;
	}
	WRM.close();

	Sleep(2000);
	continueChoice();
}

//to change the string inputs to an integer.
int ManagerClass::ChangeStringToInt(string s){
	int total = 0;
	for(int i = 0, m = s.size(); i < m; i++){
		if(s[i] >= '0' && s[i] <= '9')
			total += (int)(s[i]-'0') * pow(10, m-i-1);
		else{
			cout << "\nInvalid Input" << endl;
			Sleep(2000);
			continueChoice();
		}
	}
	return total;
}
//Check the brand and return the brands value.
int ManagerClass::CheckBrandName(string brandName){

	for(int i = 0, n = brandName.size(); i < n; i++){
		if(brandName[i] >= 'A' && brandName[i] <= 'Z')
			brandName[i] += 32;
	}
	//Checking from the brand name.
	if(brandName == "costacoffee") return 1;
	else if(brandName == "starbucks") return 2;
	else if(brandName == "nescafe") return 3;
	else if(brandName == "fanta") return 4;
	else if(brandName == "mocha") return 5;
	else if(brandName == "cocacola") return 6;
	else if(brandName == "pepsi") return 7;
	else if(brandName == "americano") return 8;
	else if(brandName == "milo") return 9;
	else{
		cout << "\nInvalid brand Name." << endl;
		Sleep(2000);
		continueChoice();
	}
}
//Display more specific info about the sales or Exit the program.
void ManagerClass::DisplaySlaesHistory(){
	string s, choice;
	int n;

	system("cls");
	
	ifstream RPH;
	RPH.open("./Files/PurchaseHistory.txt");

	if(RPH.peek() == ifstream::traits_type::eof()){	//Checking if the file is empty or not.
		cout << "\nThe Salary History is empty." << endl;
		cout << "Unfortunately, No sales has been made till now." << endl;
		Sleep(2000);
	}
	else{
		while(RPH >> s){
			n = s.size();
			cout << s << " ";
			if(s[n-1] == ')') cout << endl;
			if(s[n-1] == '.') cout << endl << endl;
		}
		RPH.close();
	}
	cout << "\nPlease Choose One of the following: "  << endl;
	cout << "\n1- Clear The History" << endl;
	cout << "2- Continue" << endl;
	cout << "\nYour transaction: ";
	cin >> choice;

	if(choice == "1"){
		ofstream WPH;	//Write Purchase history
		WPH.open("./Files/PurchaseHistory.txt", ofstream::out);
		WPH.close();

		Sleep(2000);
		cout << "\nThe History is clear now" << endl;
		continueChoice();
	}
	else if(choice == "2"){
		Sleep(2000);
		DisplayTransactions();
	}
	else{
		cout << "\nInvalid Input" << endl;
		Sleep(2000);
		continueChoice();
	}
}
void ManagerClass::continueChoice(){
	string choice;

	cout << "\nDo you want to continue (Y/N): ";
	cin >> choice;
	if (choice == "Y" || choice == "y") DisplayTransactions();
	else if (choice == "N" || choice == "n"){
		endOFProgram();
	}
	else{
		cout << "\nInvalid Input" << endl;
		Sleep(2000);
		continueChoice();
	}
}
void ManagerClass::endOFProgram(){
	system("cls");
	cout << "\n\n\n\t\t\t\t   Thank you for your kindness sir." << endl;
	cout << "\n\t\t\t\t\t    Have a nice day." << endl;
	cout << "\t\t\t\t\t      See you soon." << endl;
	Sleep(100000);
}
