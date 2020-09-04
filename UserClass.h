#include "./Libraries.h"
using namespace std;


//Definetions
#define COSTACOFEE_PRICE 7.5
#define STARBUCKS_PRICE 6.5
#define NESCAFE_PRICE 3.3
#define PEPSI_PRICE 2.6
#define FANTA_PRICE 2.3
#define MOCHA 2.1
#define COCACOLA_PRICE 3.5
#define AMERICANO_PRICE 6.0
#define MILO_PRICE 1.9

//Pre_defined Class
class CustomerClass{
	private:
		int NumOfPurcahes;
		double notes;
		double coins;
		double balance = 0.0;
		double totalPurchases;
		double totalDeposit = 0.0;
		int AS[9] = {0};	//for the recipt.
		string NOS[9];	//for the recipt.
	public:
		void DisplayTheOptions();
		void CalculateTheMoney(int, double);
		void GetTheUsersMoney();
		void GetUsersOrder();
		void checkTheAmount(int);
		void calculateThePrice(int, int);
		void checkTheBalance(double, int, int);
		void continueChoice();
		void endOFProgram();
		int ChangeStringToInt(string);
		void CheckTheCurrentBalance();
		int DisplayTheNotes();
		double DisplayTheCoins();
		void GetUsersOrderReady(int, int);
		void PrintingTheRecipt();
		void UpdateTheSalary();
		void PurchaseHistory();
};


void CustomerClass::GetUsersOrder(){
	string drinkNo, choice, piecesOfCan;
	int DN, POC;

	system("cls");
	cout << "\nPlease choose one of the following transactions" << endl;
	cout << "\n1- Get a Drink." << endl;
	cout << "2- Insert some money." << endl;
	cout << "3- Balance Enquiry." << endl;
	cout << "4- Exit." << endl;
	cout << "\nYour Transaction: ";

	cin >> choice;
	if(choice == "1"){
		DisplayTheOptions();

		cout << "\nPlease Choose Your Drink" << endl;
		cout << "Drink NO.: ";
		cin >> drinkNo;
		if(drinkNo != "1" && drinkNo != "2" && drinkNo != "3" && drinkNo != "4" && drinkNo != "5" && drinkNo != "6"
			&& drinkNo != "7" && drinkNo != "8" && drinkNo != "9"){
			cout << "\nInvalid Input" << endl;
			Sleep(2000);
			continueChoice();
		}

		DN = ChangeStringToInt(drinkNo);

		cout << "How many pieces: ";
		cin >> piecesOfCan;
		POC = ChangeStringToInt(piecesOfCan);

		checkTheAmount(POC);	//make sure that the amount does not exceed 20 peices.
		calculateThePrice(DN,POC);	//Calculate the price.

	}
	else if(choice == "2")
			GetTheUsersMoney();
	else if(choice == "3"){
		cout << fixed << setprecision(2);
		CheckTheCurrentBalance();
	}
	else if(choice == "4")
		endOFProgram();
	else{
		cout << "\nInvalid Input" << endl;
		Sleep(2000);
		continueChoice();
	}
}

//Display the current balance to the user.
void CustomerClass::CheckTheCurrentBalance(){
	system("cls");
	cout << "\n\n\n\t\t\tYour Current Balance is: RM" << balance << endl;
	Sleep(2000);
	continueChoice();
}
void CustomerClass::DisplayTheOptions(){
	system("cls");
	cout << "\n\n 1- CostaCoffee : 7.5\t" << "2- Starbucks: 6.5\t" << "3- Nescafe:3.3\t" << endl;
	cout << "\n 4- Fanta:2.3\t" << "5- Mocha: 2.1\t\t" << "6- CocaCola:3.5" << endl;
	cout << "\n 7- Pepsi: 2.6\t" << "8- Americano: 6.0\t" << "9- Milo: 1.9" << endl;
}

void CustomerClass::GetTheUsersMoney(){
	string choice, pieces;
	int tmp;
	double Coins = 0.0, Notes = 0.0;

	system("cls");
	cout << "\nPlease Choose the following" << endl;
	cout << "\n1- Notes." << endl;
	cout << "2- Coins." << endl;
	cout << "\nYour Transaction: ";

	cin >> choice;

	if(choice == "1"){
		Notes = DisplayTheNotes();

		cout << "How Many Notes: ";
		cin >> pieces;

		tmp = ChangeStringToInt(pieces);
		if(tmp > 10 || tmp < 0){		//Checking if the pices is more than 10 or not.
				cout << "\nYou Cannot insert more than 10 Notes per time." << endl;
				cout << "Invalid Input" << endl;
				Sleep(2000);
				continueChoice();
		}else{
			Notes *= (tmp *1.0);
			totalDeposit += Notes;
		}

		cout << "\nYour Balance has been Updated" << endl;
		Sleep(2000);
	}
	else if(choice == "2"){
		Coins = DisplayTheCoins();

		cout << "How many Coins: ";
		cin >> pieces;

		tmp = ChangeStringToInt(pieces);

		if(tmp > 10 || tmp < 0){		//Checking if the pices is more than 10 or not.
				cout << "\nYou Cannot insert more than 10 coins per time." << endl;
				cout << "Invalid Input" << endl;
				Sleep(2000);
				continueChoice();
		}else{
			Coins *= (tmp*1.0);
			totalDeposit += Coins;
		}

		cout << "\nYour Balance has been Updated." << endl;
		Sleep(2000);
	}
	else{
		cout << "\nInvalid Input" << endl;
		Sleep(2000);
		continueChoice();
	}

	CalculateTheMoney(Notes, Coins);
}

//display the notes avaliable and return the amount of money.
int CustomerClass::DisplayTheNotes(){
	int totalNotes = 0;
	string choice;
	system("cls");

	cout << "\n\nPlease Choose one of the following:" << endl;
	cout << "\n\n1- RM1\t   2- RM5\t 3- RM10" << endl;
	cout << "\n4- RM20\t   5- RM50\t 6- RM100" << endl;

	cout << "\nYour Transaction: ";
	cin >> choice;

	if(choice == "1") return 1;
	else if(choice == "2") return 5;
	else if(choice == "3") return 10;
	else if(choice == "4") return 20;
	else if(choice == "5") return 50;
	else if(choice == "6") return 100;
	else{
		cout << "\nInvalid Input" << endl;
		Sleep(2000);
		continueChoice();
	}
}

double CustomerClass::DisplayTheCoins(){
	double totalCoins = 0.0;
	string choice;
	system("cls");

	cout << "\n\nPlease Choose one of the following:" << endl;
	cout << "\n\n1- RM0.10\t 2- RM0.20\t 3- RM0.50" << endl;
	cout << "\n4- RM0.70\t 5- RM0.80\t 6- RM0.90" << endl;

	cout << "\nYour Transaction: ";
	cin >> choice;

	if(choice == "1") return 0.10;
	else if(choice == "2") return 0.20;
	else if(choice == "3") return 0.50;
	else if(choice == "4") return 0.70;
	else if(choice == "5") return 0.80;
	else if(choice == "6") return 0.90;
	else{
		cout << "\nInvalid Input" << endl;
		Sleep(2000);
		continueChoice();
	}
}

//Changing the inputs from the user to int to use them as numbers.
int CustomerClass::ChangeStringToInt(string s){
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

//Checking if the amount of cans exceed 20 pieces or not.
void CustomerClass::checkTheAmount(int piecesOfCan){
	if (piecesOfCan > 20 || piecesOfCan < 0){
		cout << "\nInvalid amount of Cans" << endl;
		cout << "Please refer to the instructions." << endl;
		Sleep(2000);
		continueChoice();
	}
}

//Claculating the prices of the choice and the amount of cans.
void CustomerClass::calculateThePrice(int drinkNo, int piecesOfCan){
	double price;
	switch(drinkNo){
		case 1:
			price = piecesOfCan * COSTACOFEE_PRICE;
			checkTheBalance(price, drinkNo, piecesOfCan);
			break;
		case 2:
			price = piecesOfCan * STARBUCKS_PRICE;
			checkTheBalance(price, drinkNo, piecesOfCan);
			break;
		case 3:
			price = piecesOfCan * NESCAFE_PRICE;
			checkTheBalance(price, drinkNo, piecesOfCan);
			break;
		case 4:
			price = piecesOfCan * FANTA_PRICE;
			checkTheBalance(price, drinkNo, piecesOfCan);
			break;
		case 5:
			price = piecesOfCan * MOCHA;
			checkTheBalance(price, drinkNo, piecesOfCan);
			break;
		case 6:
			price = piecesOfCan * COCACOLA_PRICE;
			checkTheBalance(price, drinkNo, piecesOfCan);
			break;
		case 7:
			price = piecesOfCan * PEPSI_PRICE;
			checkTheBalance(price, drinkNo, piecesOfCan);
			break;
		case 8:
			price = piecesOfCan * AMERICANO_PRICE;
			checkTheBalance(price, drinkNo, piecesOfCan);
			break;
		case 9:
			price = piecesOfCan * MILO_PRICE;
			checkTheBalance(price, drinkNo, piecesOfCan);
			break;
	}
}

//Checking whether the user has enough money or not.
void CustomerClass::checkTheBalance(double price, int drinkNo, int piecesOfCan){
	if (balance >= price){

		GetUsersOrderReady(drinkNo, piecesOfCan);

		totalPurchases += price;
		NumOfPurcahes++; //To know how many cans has been sold.
		balance -= price;
		cout << "\nYou total purchases costs RM" << totalPurchases << endl;
		cout << "Your new balance is: RM" << balance << endl;
		continueChoice();
        }
    else{
    	cout << "\nYou do not have enough balance" << endl;
    	cout << "Please Insert Some Money" << endl;
    	Sleep(2000);
    	continueChoice();
    }
}

//Reading things from the file and rewrite the file after doing it's mission.
void CustomerClass::GetUsersOrderReady(int drink, int amount){
	string drinkname;
	int compare;

	string Drinks[9] = {
		"CostaCoffee", "Starbucks","Nescafe","Fanta","Mocha","CocaCola","Pepsi","Americano","Milo"
	};
	int AFP[9] = {0};	//Amount after purchase.

	//Read the amount from the file.
	ifstream checkAmount;
	checkAmount.open("./Files/MachineCapacity.txt");

	int i = 0;
	while(checkAmount >> compare >> drinkname >> AFP[i]){

		if(compare == drink && AFP[i] >= amount){
			AFP[i] -= amount;
			AS[i] += amount;
			NOS[i] = Drinks[i];
		}
		else if(AFP[i] < amount && compare == drink && AFP[i] != 0){
			cout << "\nSorry, There are(is) only " << AFP[i] << " pieces in stock." << endl;
			continueChoice();
		}
		else if(compare == drink && AFP[i] == 0){
			cout << "\nSold Out!" << endl;
			continueChoice();
		}
		i++;
	}
	checkAmount.close();

	//Update the remain amount after purchasing.
	ofstream WriteFF;	//Write Final File.
	WriteFF.open("./Files/MachineCapacity.txt");

	i = 0;
	while(WriteFF.good()){
		if(i == 9)break;
		WriteFF << i+1 << " " << Drinks[i] << " " << AFP[i];
		WriteFF << endl;
		i++;
	}
	WriteFF.close();
}

void CustomerClass::PrintingTheRecipt(){
	ofstream recipt("./Files/Recipt.txt");

	system("cls");

	int i = 0;
	int j = 0;
	cout << "\n\n\n\t\t\tPlease Collect Your Recipt ^_^" << endl;
	if(recipt.is_open()){
		recipt << "\n\n\t\t\t Al-Sufi Vending Machine" << endl;
		recipt << "\t\t\t\t   Recipt" << endl;
	}
	while(recipt.is_open()){
		if(i == 9) break;
		if(AS[i] != 0){
			if(j == 0) recipt << "Purchases: " << endl;
			recipt << "\t" << j+1 << "- " << NOS[i] << ": " << AS[i] << " Piece(s)" << endl;
			j++;
		}
		i++;
	}
	if(recipt.is_open()){
		recipt << "\nYou did deposite: RM" << totalDeposit << "." << endl;
		recipt << "Your remainder Balance: RM" << balance << "." << endl;
		recipt << "\n\t\t\t  THANK YOU ^_^" << endl;
		recipt << "\t\t\t  See You Soon." << endl;
	}
	recipt.close();
	PurchaseHistory();
	UpdateTheSalary();
	Sleep(2000);
}
//if the user wants to insert some money.
void CustomerClass::CalculateTheMoney(int Notes, double Coins){
	balance += (Notes*1.0) + Coins;
	GetUsersOrder();
}

//Create a file which store every product that the user has bought.
void CustomerClass::PurchaseHistory(){
	ofstream WPH;	//write the purchase history.
	WPH.open("./Files/PurchaseHistory.txt", fstream::app);

	int j = 0, i = 0;
	while(WPH.good()){
		if(i == 9) break;
		if(AS[i] != 0){
			WPH << "- " << NOS[i] << ": " << AS[i] << " Piece(s)" << endl;
			j++;
		}
		i++;
	}
	WPH << "the Net Sales for this operation: RM" << totalDeposit-balance << "." << endl;
	WPH << endl;
	WPH.close();
}

//Make a file to update the salary which the manager can access to it easily
void CustomerClass::UpdateTheSalary(){
	int num;
	string name;
	string MN[4] = {
		"Zian", "Sami", "Leepu","Istiak"
	};	//Managersnames
	double salary[4] = {0.0};

	ifstream RS;	//readSalary()
	RS.open("./Files/Salary.txt");
	int i = 0;
	while(RS >> num >> name >> salary[i]) i++;
	RS.close();

	ofstream WNS;	//write new salary
	WNS.open("./Files/Salary.txt");

	i = 0;
	while(WNS.good()){
		if(i == 4) break;
		WNS << i+1 << " " << MN[i] << " " << salary[i] + (totalPurchases/3) << endl;
		i++;
	}
}

//Display after every transaction to check if the user want to do anything else of not.
void CustomerClass::continueChoice(){
	string choice;

	cout << "\nDo you want to continue (Y/N): ";
	cin >> choice;
	if (choice == "Y" || choice == "y") GetUsersOrder();
	else if (choice == "N" || choice == "n"){
		Sleep(2000);
		endOFProgram();
	}
	else{
		cout << "\nInvalid Input" << endl;
		Sleep(2000);
		continueChoice();
	}
}

//When the user want to exit the program those massages will be displayed
//and the program will finish immediately.
void CustomerClass::endOFProgram(){
	PrintingTheRecipt();
	system("cls");
	cout << "\n\n\n\t\t\t\tThank you for using Al-Sufi vending Machine" << endl;
	cout << "\n\t\t\t\t\t    Have a nice day." << endl;
	cout << "\t\t\t\t\t      See you soon." << endl;
	Sleep(100000);
}
