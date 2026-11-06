/*
   Write a menu-driven program to create a class WaterBill with data members code(int), category(char) category must include only "C" and "I", monthly_bill(double).
	code must be auto incremented starting with 0 then increment by 1. category and monthly_bill must be inserted by the user.
	if category is "C" then 10% discount must be applied for the bill, zero discount for other category.
	
	1. add data: create object and insert category and bill code must be generated automatically.
		push the data into a file named "water_bill.txt" using the object of that class.
		
	2. display details: insert the user code to fetch the data of the bill, use "random access file" operation for
		retreiving the data from the file. and appropriate message must be shown:
		bill >750  "more bill"
		bill >=250  and bill <=750 "moderate bill"
		bill < 250 "less bill".
		
	3. display total: display the total bill amount of all the users inserted. calculate all the bill and display a total 
		sum value of all the bill.
		
*/






#include<bits/stdc++.h>
using namespace std;
class WaterBill{
	static int code1;
	int code;
	char category;
	double monthly_bill;
	public:
		WaterBill(){

			monthly_bill=0.0;
		}
		void insert(){
			code=code1;
			code1++;			
			cout<<"enter category: ";
			cin>>category;
			if(category != 'C' && category != 'I'){
				cout<<"enter valid category ";
				exit (0);
			}
			cout<<"enter monthly Bill: ";
			cin>>monthly_bill;
		}
		int get_code(){
			return code;
		}
		double get_bill(){
			return monthly_bill;
		}
		void discount(){
			if(category == 'C'){
				monthly_bill= monthly_bill - (monthly_bill * 0.10);
			}
		}
		void display(){
			cout<<"\ncode is: "<<code;
			cout<<"\ncategory is: "<<category;
			cout<<"\nMonthly electricity bill: "<<monthly_bill<<endl;
		}
};
int WaterBill::code1 = 1;

int main(){
	WaterBill w;
	fstream file;
	int n,choice;
	file.open("water_bill.txt",ios::out | ios::binary);
	file.close();
	do{
		cout<<"\n1. Add data:";
		cout<<"\n2. display user:";
		cout<<"\n3. Display Total bill of all user:";
		cout<<"\n4. Exit";
		cout<<"\nEnter your choice: ";
		cin>>choice;
		if(choice==1){
			w.insert();
			w.discount();
			w.display();
			file.open("water_bill.txt",ios::out | ios::app | ios::binary);
			file.write((char*)&w,sizeof(WaterBill));
			file.close();
		}
		else if(choice == 2){
			file.open("water_bill.txt", ios::in | ios::binary);			
		    bool found=false;
		    cout<<"\nEnter the code to search: ";
		    cin>>n;			
			int loc = (n-1) * sizeof(WaterBill);			
		    file.seekg(loc, ios::beg);			
			    if(n>0 && file.read((char*)&w,sizeof(WaterBill))){
			        if(w.get_code() == n){
			            found = true;			
			            w.display();
			            double bill = w.get_bill();
			            if(bill < 250)
			                cout<<"Very good\n";
			            else if(bill >=250 && bill<= 750)
			                cout<<"Moderate bill\n";
			            else
			                cout<<"More bill\n";
			       		}
			    	}
			    if(!found)
			        cout<<"Employee not found!\n";
			    file.close();
			}
		else if(choice==3){
			file.open("water_bill.txt",ios::in | ios::binary);
			double totalVal=0;
			while(file.read((char*)&w,sizeof(WaterBill))){
				double vall = w.get_bill();
				totalVal += vall;
			}
			cout<<"\nTotal value of Bill: "<<totalVal;
			file.close();
		}
		else if(choice == 4){
			cout<<"EXITING";
			exit (0);
		}
		else{
			cout<<"\ninvalid choice\n";
			
		}
	}while(choice!=4);
}
