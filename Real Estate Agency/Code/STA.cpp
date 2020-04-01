#include <iostream>
#include <string.h>
#include <fstream>
#include <stdlib.h>

const int n=12;  // Number of locations 
const int n2=6;		// number of agents
using namespace std;


class Person
{
	public :
	
		string name;
		string email;
		string cellno;
	
	public :
		
		Person()
		{
			
		}	
		
		Person(string nam,string em,string num)
		{
			name = nam;
			email = em;
			cellno = num;
		}
		
		Person GetName()
		{
			cout << "Enter your name => " ;
			cin >> name ;
			
			return *this;
		}
		
		
		Person GetNum()
		{
			cout << "Enter your cellno => ";
			cin >> cellno ;
			
			return *this;
		}
		
		Person SetName(string n)
		{
			name = n;
			
			return *this;
		}
		
		
		Person SetEmail(string e)
		{
			email = e;
			
			return *this;
		}
		
		
		Person SetNum(string num)
		{
			cellno = num;
			
			return *this;
		}
		
};

class Location{ // abstract class
	
	protected :
		
		string area[n];		// Name of the area
		string status[n];		// avaliable or not avaliable
		string condition[n]; // A for good B for not soo good
		string category[n];
		
	public :	
	
		Location()
		{
			
		}
		
		virtual void ReadData()=0;
		
};

class ForRent : public Location{
	
	private :
		
		int i;
		int j;
		string rent[n-(n/2)];
		string max_occupants[n-(n/2)];
		
	public :
		
		ForRent()
		{
			i=0;
			j=9;
		}
		
		void ReadData()
		{
			string A,R,S,C,M;
			
			ifstream inData;
			
			inData.open("Locations.txt");
		
			while (inData >> A >> R >> S >> C >> M)
			{
				if (C == "Rent")
				{
					area[i] = A;
					rent[i] = R;
					status[i] = S;
					condition[i] = C;
					max_occupants[i] = M;	
				}
			
				++i;
			
			}
			
			inData.close();
		}
	
		void ShowLocations()
		{
			system("cls");
			cout << "Please select the area you want to deals in." << endl;
			cout << "S.No		" << "Category		" << "Status		" << "Condition		" << "Max Occupants		" << endl;
			while (j<i)
			{
				cout << j+1 << area[j] << rent[j] << status[j] << condition[j] << max_occupants[j] << endl;
				j++;
			}
		}
};

class ForSale : public Location
{
	private :
		
		int i;
		int j;
		string price[n-(n/2)];
		string tax[n-(n/2)];
	
	public :
		
		ForSale ()
		{
			i=0;
			j=0;
		}
		
		void ReadData()
		{
			string A,P,S,C,T;
			
			ifstream inData;
			
			inData.open("Location.txt");
			
			while (inData >> A >> P >> S >> C >> T)
			{
				if (C == "Sale")
				{
					area[i] = A;
					price[i] = P;
					status[i] = S;
					condition[i] = C;
					tax[i] = T;	
				}
			
				++i;
			
			}
			
			inData.close();
		}	
			void ShowLocations()
			{
				while (j<i)
				{
					cout << j+1 << area[j] << price[j] << status[j] << condition[j] << tax[j] << endl;
					j++;
				}				
			}
		 
};

class Agent : public Person // abstract class
{
	public :
		
		Client customer;
		string comission;
		string exp;
		static int count;
		string type;
		float fees;
	
	public :
		
		Agent()
		{
			++count;
		}
		
		Agent(string fee,string nam,string em,string num):Person(nam,em,num)
		{
			comission = fee;
			
			++count;
		}	
		
		Agent &SetComission(string com)
		{
			comission = com;
			
			return *this;
		}
		
		Agent &SetExperience(string exp)
		{
			this->exp = exp;
			
			return *this;
		}
		
		Agent &SetType(string typ)
		{
			type = typ;
			
			return *this;
		}
		
		void HiredAgents()
		{
			cout << "Total number of agents hired = " << count << endl;
		}		
		
		void Customer()
		{
			customer.EnterChoice();
		}
				
		virtual float CalculateFees(string )=0; // 		Polymorphism
	
};

int Agent :: count = 0;

class Alpha : public Agent
{
	private :
				
	public :
		
		float CalculateFees(string co)
		{
			char const *cost = co.c_str(); // string to char pointer
			int PropertyCost = atoi(cost); // char pointer to integer
			
			char const  *comm = comission.c_str();
			int com = atoi(comm);			
			
			float comision;
			comision = PropertyCost * com;
			
			return (comision);	
		}
		
		friend	ostream& operator << (ostream& os , Person &obj); // Operator Overloading
		
};

class Beta : public Agent
{
	private :
		
	public :

		float CalculateFees(string co)
		{
			char const *cost = co.c_str();
			int PropertyCost = atoi(cost);
			
			char const  *comm = comission.c_str();
			int com = atoi(comm);			
			
			float comision;
			comision = PropertyCost * com;
			
			return (comision);	
		}
		
		friend	ostream& operator << (ostream& os , Person &obj); // Operator Overloading
};

class Gamma : public Agent
{
	private :
		
	public :
		
		
		float CalculateFees(string co)
		{
			char const *cost = co.c_str();
			int PropertyCost = atoi(cost);
			
			char const  *comm = comission.c_str();
			int com = atoi(comm);			
			
			float comision;
			comision = PropertyCost * com;
			
			return (comision);	
		}	
		
		friend	ostream& operator << (ostream& os , Person &obj); // Operator Overloading
		
};

ostream& operator << (ostream& os , Person &obj)
{
	os << "Name : " << obj.name << endl;
	os << "Email : " << obj.email;
	os << "Cell Number : " << obj.cellno;
}

class Client : public Person
{
	protected :
		
		string choice;

	public :
		
		Client()
		{
			
		}
		
		void EnterChoice()
		{
			cout << "Enter the name of the agent whom you want to deal : " << endl;
			cin >> choice;
		}
		
		
		
};

class Buyer : public Client
{
	private :
		
	public :
		
		Buyer()
		{	
			
		}
};

class Seller : public Client
{
	private :
		
	public :
		
		Seller()
		{
			
		}
};
class Admin
{
	private :
		
		ForRent rent;
		ForSale sale; 
		string id;
		string pass;
		Alpha employee1[2];
		Beta employee2[2];
		Gamma employee3[2];
		
	public :
		
		Admin():id("admin"),pass("admin")
		{
		}
		
		void Verification()
		{
			string i,p;
			
			while (1)
			{
				cout << "Enter ID : " ;
				cin >> i;
			
				cout << "Enter password : ";
				cin >> p;
			
				if (id == i && pass == p)
				{
					break;
				}
				else
				{
					cout << "User name or password is not correct.\nPlease Try Again" << endl;
				}
			}
			
			system("cls");
		}
		
		void ChangePass()
		{
			int flag=0;
			string password;
			int i=1;
			
			while (i<=3)
			{
				cout << "Enter current password : ";
				cin >> password;
			
				if (password == pass)
				{
					cout << "Enter new password : ";
					cin >> pass;
			
					flag = 1;			
			
					break;
			
				}
				else
				{
					cout << "Wrong password " << endl;
					cout << "Remaining tries : " << 3-i << endl;			
				}
				
				i++;
			}
			
			if (flag == 1)
			{
				cout << "Password Updated." << endl;
			}
			else
			{
				cout << "Try again later." << endl;
			}
		
			system("cls");
		}
		
		void HomePage()
		{
			cout << "Welcome" << endl;
		}
		
		void Read()
		{
			int a=0,b=0,g=0;
			string name;
			string email;
			string experience;
			string comission;
			string type;
			string num;
			
			ifstream inFile;
			
			inFile.open("Agents.txt");
			
			while (inFile >> name >> email >> num >> experience >> comission >> type)
			{
				if (type == "Alpha" && a<2)
				{
				
					employee1[a].name = name;
					employee1[a].email = email;
					employee1[a].cellno = num;
					employee1[a].exp = experience;
					employee1[a].comission = comission;
					employee1[a].type = type;
					++a;
				}
				
				if (type == "Beta" && b < 2)
				{
					employee2[b].name = name;
					employee2[b].email = email;
					employee2[b].cellno = num;
					employee2[b].exp = experience;
					employee2[b].comission = comission;
					employee2[b].type = type;
					++b;
				}
				
				if (type == "Gamma" && g < 2)
				{
					employee3[g].name = name;
					employee3[g].email = email;
					employee3[g].cellno = num;
					employee3[g].exp = experience;
					employee3[g].comission = comission;
					employee3[g].type = type;
					++g;
				}
				
			}
			
			inFile.close();
		}	
			void NumberOfAgentsHired()
			{			
				employee1[0].HiredAgents();
			}
		
		
		void DisplayAgents()
		{
			int i=0;
			
			cout << "S.NO " << "Name		" << "Email		" << "Contact.No  " << "Experience(Years)	" << "Comission		" << "Type" << endl; 
			int c=0;
			while (i<2)
			{
 				cout << ++c << " " << employee1[i].name << "	 " << employee1[i].email << " 	" << employee1[i].cellno << " 	" << employee1[i].exp << "		 " << employee1[i].comission << " 			" << employee1[i].type << endl;
				cout << ++c << " " << employee2[i].name << "	 " << employee2[i].email << " 	" << employee2[i].cellno << " 	" << employee2[i].exp << "		 " << employee2[i].comission << " 			" << employee2[i].type << endl;				
				cout << ++c << " " << employee3[i].name << "	 " << employee3[i].email << " 	" << employee3[i].cellno << "  	" << employee3[i].exp << "		 " << employee3[i].comission << " 			" << employee3[i].type << endl;			
				i++;
			}
		}
		
		void DisplayLocations()
		{
			rent.ReadData();
			rent.ShowLocations();
			sale.ReadData();
			sale.ShowLocations();
		}
};

int main()
{
	Admin obj;
//	obj.Verification();
	obj.Read();
	cout << "Press any key to view the list of agents." << endl;
	getchar();
	system("cls");
	obj.DisplayAgents();
	
	
}
