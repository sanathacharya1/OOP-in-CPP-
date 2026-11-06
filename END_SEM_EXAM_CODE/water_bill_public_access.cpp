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
	public:
		int code;
		char category;
		double monthly_bill;
		WaterBill(){
			monthly_bill=0.0;
		}
		void insert(){			
			cout<<"enter category: ";
			cin>>category;
			if(category != 'C' && category != 'I'){
				cout<<"enter valid category ";
				exit (0);
			}
			cout<<"enter monthly Bill: ";
			cin>>monthly_bill;
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
int main(){
	WaterBill w[50];
	fstream file;
	int n,choice,coo,nxc=1;
	do{
		cout<<"\n1.Add Data";
		cout<<"\n2.Display Data";
		cout<<"\n3.Display Total Bill";
		cout<<"\n4.Exit";
		cout<<"\nEnter your choice: ";
		cin>>choice;
		if(choice ==1){
			cout<<"enter the number of operatoins: ";
			cin>>n;
			file.open("waterbill.txt",ios::out | ios::binary);
			for(int i=0;i<n;i++){
				w[i].code=nxc++;
				w[i].insert();
				w[i].discount();
			}			
			for(int j=0;j<n;j++){	
			file.write((char*)&w[j],sizeof(WaterBill));
		}
			cout<<"\nData inserted to file waterbill.txt\n";
			file.close();
		}
		else if(choice ==2){
			WaterBill w1;
			cout<<"Enter the code to search: ";
			cin>>coo;
			bool found=false;
			file.open("waterbill.txt",ios::in | ios::binary);
			int loc= (coo-1) * sizeof(WaterBill);
			file.seekg(loc,ios::beg);
			if(coo>0 && file.read((char*)&w1,sizeof(WaterBill))){
				if(w1.code==coo){
					found=true;			
			            w1.display();
			            if(w1.monthly_bill < 250)
			                cout<<"Very good\n";
			            else if(w1.monthly_bill  >=250 && w1.monthly_bill<= 750)
			                cout<<"Moderate bill\n";
			            else
			                cout<<"More bill\n";
				}
			}
			if(!found)
				cout<<"\nemployeenot found\n";
			file.close();
		}
		else if(choice ==3){
			WaterBill w2;
			file.open("waterbill.txt",ios::in | ios::binary);
			double totval=0;
			while(file.read((char*)&w2,sizeof(WaterBill))){
				totval = totval+w2.monthly_bill;
			}
			cout<<"\nTotal employee bills: "<<totval;
			file.close();
		}
		else if(choice ==4){
			cout<<"\nExiting\n";
			exit (0);
		}
		else{
			cout<<"\ninvalid choice";
		}
	}while(choice!=4);
}
