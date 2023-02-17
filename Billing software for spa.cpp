#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int customersNum=0;
struct Bills
{
    int day, month, year, billNum, total;
}BillDate; //use this variable to enter the date then print it in each bill
struct customer
{
	string name;
	long phone;
	int service [16];
	Bills bill;
};
struct employment
{
	string name ;
	int id;
}emp[5];
void menu () //print the menu
{
	cout<<"Haircuts\n";
	cout<<" 1- short hair (50)\n 2- long hair (75)\n 3- Edges (25)\n";
	cout<<"Color\n";
	cout<<" 4- Short hair (200)\n 5- Med hair (350)\n 6- long hair (600)\n";
	cout<<"Texture\n";
	cout<<" 7- Short hair (350)\n 8- Med hair (700)\n 9- long hair (1000)\n";
	cout<<"Nails\n";
	cout<<" 10- Spa pedicure (60)\n 11- Spa manicure(60)\n 12- Pedicure & Manicure (130)\n 13- Nail polish(20)\n";
	cout<<"Massage\n";
	cout<<" 14- Hot stone massage -50 m- (200)\n 15- Deep tissue massage -50 m- (200)\n 16- Swedish massage -50 m- (200)\n";
}
void addCustomer (customer cust[])//use this function to add customer's name and her phone number
{
	cout<<"Enter customer name: ";
	cin>>cust[customersNum].name;
	cout<<"Enter customer phone number: ";
	cin>>cust[customersNum].phone;
}
void deleteCustomer (customer cust[]) //use this function to delete all information about specific customer  by using bill number //
{
	int bill;
	bool check = false; //to check if the bill number exist or not
	cout<<"Enter bill number to delete: ";
	cin>>bill;
	for (int i=0 ; i<customersNum ; i++)
	{
		if (cust[i].bill.billNum == bill)
		{
			for (int j=i ; j<customersNum-1 ; j++)
			{
				cust[j] = cust[j+1];
			}
			cout<<"The customer deleted succesfully.";
			customersNum--;
			return;
		}
		else if (cust[i].bill.billNum != bill)
		   check = false;
	}
	if (check == false)
	   cout<<"This bill number not found.";
}
void searchCustomer (customer cust[]) //this function will search on specific customer by using  her bill number then print her name, phone and total bill //
{
	int bill;
	bool check = false;
	cout<<"Enter customer bill number to search: ";
	cin>>bill;
	for (int i=0 ; i<customersNum ; i++)
	{
		if (cust[i].bill.billNum == bill)
		{
			cout<<"Customer name: "<<cust[i].name<<endl;
			cout<<"Customer phone number: "<<cust[i].phone<<endl;
			cout<<"Customer total: "<<cust[i].bill.total<<endl;
			return;
		}
		else if (cust[i].bill.billNum =! bill)
		  check = false;
	}
	if (check == false)
	  cout<<"This bill number not found.";
}
void updateCustomer (customer cust[]) //will search on customer by using her bill number then update her phone number
{
	int bill;
	long phone;
	cout<<"Enter customer bill number to update her phone number: ";
	cin>>bill;
	cout<<"Enter the updating phone number: ";
	cin>>phone;
	for (int i=0 ; i<customersNum ; i++)
	{
		if (cust[i].bill.billNum == bill)
		{
			cust[i].phone = phone;
			return;
		}
	}
	cout<<"The customer's phone number updated successfully.";
}
void sortCustomer (customer cust[]) //will sort bills ascending by using bill number
{
    customer temp;
    bool ordered=false;
    if (customersNum<2)
        cout<<"Nothing to sort\n";
    for (int i=0 ; i<customersNum-1; i++)
    {
    	
    	for (int j=0 ; j<customersNum-1 ; j++)
    	{
           if (cust[i].bill.billNum > cust[i+1].bill.billNum)
           {
           	
             temp = cust[i];
             cust[i] = cust[i+1];
             cust[i+1] = temp;
           }
		}
    }
    cout<<"The customers sorting successfully.";
}
int calcBill (customer cust [],int services) //will calculate each customer's bill and return the total bill for each customer
{
	int total=0;
	for (int i=0 ; i<services ; i++)
	{
		switch (cust[customersNum].service[i])
		{
			case 1:
				total +=50;
				break;
			case 2:
				total +=75;
				break;
			case 3:
				total +=25;
				break;
			case 4:
				total +=200;
				break;
			case 5:
				total +=350;
				break;
			case 6:
				total +=600;
				break;
			case 7:
				total +=350;
				break;
			case 8:
				total +=700;
				break;
			case 9:
				total +=1000;
				break;
			case 10:
			case 11:
				total +=60;
				break;
			case 12:
				total +=130;
				break;
			case 13:
				total +=20;
				break;
			case 14:
			case 15:
			case 16:
				total +=200;
				break;
		}
	}
	return total;
}
/*this function will receive the number of services and the total income for today then it will print all
bills for all customers then compute the total income for today*/
void printBills (customer cust[], int services, int &income)
{
	int random;
	emp[0].id=763, emp[0].name="Maria", emp[1].id=925, emp[1].name="Kate", emp[2].id=146, emp[2].name="Nicole", emp[3].id=834, emp[3].name="Sophia", emp[4].id=429, emp[4].name="Trisha";
	for (int i=0 ; i<customersNum ; i++)
	{
		random=0+rand()%(4-0+1); //to choose different employment randomly for each customer
		srand (time (0));
		cout<<"Bill #"<<cust[i].bill.billNum<<endl;
		cout<<"Name: "<<cust[i].name<<endl;
		cout<<"Phone number: +966"<<cust[i].phone<<endl;
		cout<<"Employment: "<<emp[random].name<<" ("<<emp[random].id<<")"<<endl;
		cout<<"Date: "<<BillDate.day<<"/"<<BillDate.month<<"/"<<BillDate.year<<endl;
		cout<<"Services:\n";
		for (int j=0 ; j<services ; j++)
		{
			switch (cust[i].service[j])
			{
            case 1:
                cout<<"  -short hair cut 50 SR\n";
                break;
            case 2:
                cout<<"  -long hair cut 75 SR\n";
                break;
            case 3:
                cout<<"  -Edges cut 25 SR\n";
                break;
            case 4:
                cout<<"  -short hair color 200 SR\n";
                break;
            case 5:
                cout<<"  -med hair color 350 SR\n";
                break;
            case 6:
                cout<<"  -long hair color 600 SR\n";
                break;
            case 7:
                cout<<"  -short hair texture 350 SR\n";
                break;
            case 8:
                cout<<"  -med hair texture 700 SR\n";
                break;
            case 9:
                cout<<"  -long hair texture 1000 SR\n";
                break;
            case 10:
                cout<<"  -spa pedicure 60 SR\n";
                break;
            case 11:
                cout<<"  -spa manicure 60 SR\n";
                break;
            case 12:
                cout<<"  -pedicure & manicure 130 SR\n";
                break;
            case 13:
                cout<<"  -nail polish 20 SR\n";
                break;
            case 14:
                cout<<"  -hot stone massage 200 SR\n";
                break;
            case 15:
                cout<<"  -deep tissue massage 200 SR\n";
                break;
            case 16:
                cout<<"  -swedish massage 200 SR\n";
                break;
			}
		}
		cout<<"\n\tTotal cost: "<<cust[i].bill.total<<endl;
		income = income + cust[i].bill.total; //calculate the total income from all bills
	}
}
int main()
{
	cout<<"\t\t\t\t\t Welcome to Sun Shine Spa\n\n";
	int servCount, choice, totalIncome=0, billNumber;
	customer cust[100];
	Bills bill;
	menu ();
	cout<<"\nEnter today's date: (dd mm yy) ";
	cin>>BillDate.day>>BillDate.month>>BillDate.year;
	do
	{
	   cout<<"\nChoose number:\n 1.Add customer 2.Delete customer \n 3.search customer 4.Update customer\n 5.sorting customers 6.Print all bills\n any other number to exit\n";
	   cin>>choice;
	   if (choice == 1)
	   {
	   	 addCustomer (cust);
	   	 cout<<"How many services "<<cust[customersNum].name<<" need? ";
	   	 cin>>servCount;
	   	 for (int i=0 ; i<servCount ; i++)
	   	 {
	   	 	cout<<"Enter #"<<i+1<<" service: ";
	   	 	cin>>cust[customersNum].service[i];
		 }
		 cust[customersNum].bill.total = calcBill (cust, servCount);
		 cout<<cust[customersNum].name<<"'s total cost is: "<<cust[customersNum].bill.total<<endl;
		 srand (time(0));
		 billNumber = 100+rand()%(999-100+1); //choose random number consist of 3 digits for each bill
		 cust[customersNum].bill.billNum = billNumber;
		 for (int j=0 ; j<customersNum ; j++) //check if the random number found before then change it so it will be unique for each bill
         {
             if (billNumber == cust[j].bill.billNum)
             {
                billNumber = 100+rand()%(999-100+1);
		        cust[customersNum].bill.billNum = billNumber;
             }
         }
         cout<<cust[customersNum].name<<"'s bill number: "<<billNumber;
	   	 customersNum++;
	   }
	   else if (choice == 2)
	   	 deleteCustomer (cust);
	   else if (choice == 3)
	   	 searchCustomer (cust);
	   else if (choice == 4)
	   	 updateCustomer (cust);
	   else if (choice == 5)
	   	 sortCustomer (cust);
	   else if (choice == 6)
	   	 printBills (cust, servCount, totalIncome);
	   else //if the user choose any other number will print the total income for today then exit
       {
           cout<<"\n\n\t\tYour total income for today: "<<totalIncome<<endl;
           break;
       }
    }while (customersNum<=100);
}