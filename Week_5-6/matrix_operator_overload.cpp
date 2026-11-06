#include<bits/stdc++.h>
using namespace std;
class matrixx{
	int arr[10][10];
	int row,col;
	public:
		matrixx(){
		}
		matrixx(int r, int c){
			row=r;
			col=c;
		}
		void insert(){
			cout<<"enter the matrix: "<<"\n";
			for(int i=0;i<row;i++){
				for(int j=0;j<col;j++){
					cin>>arr[i][j];
				}
			}
		}
		void display(){
			cout<<"matrix are: \n";
			for(int i=0;i<row;i++){
				for(int j=0;j<col;j++){
					cout<<arr[i][j]<<" ";
				}
				cout<<endl;
			}
		}
		bool operator == (matrixx);
		matrixx operator + (matrixx);
		matrixx operator - (matrixx);
};
bool matrixx::operator ==(matrixx m){
	if(row==m.row && col==m.col)
		return true;
	return false;
}
matrixx matrixx::operator + (matrixx M){
	matrixx m1;
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			m1.arr[i][j] = arr[i][j]+M.arr[i][j];
		}
	}
	return m1;
}
matrixx matrixx::operator - (matrixx M){
	matrixx m1;
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			m1.arr[i][j] = arr[i][j]-M.arr[i][j];
		}
	}
	return m1;
}  

	
int main()
{
	matrixx m(2,2);
	matrixx m1=m;
	matrixx a,b;
	cout<<"1st array";
	m.insert();
	cout<<endl;
	m.display();
	cout<<endl;
	cout<<"2nd array";
	m1.insert();
	cout<<endl;
	m1.display();
	cout<<endl;
	if(m == m1){
		a = m + m1;
		cout<<"plus: "<<endl;
		a.display();
		b = m - m1;
		cout<<"minus "<<endl;
		b.display();
	}else{
		cout<<"cannot be added or subtraced";
	}	
}
