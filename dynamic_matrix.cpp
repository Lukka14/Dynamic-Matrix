#include <iostream>
#include <cmath>
// მატრიცის ტრანსფორმირება
// Luka Tskhomelidze
// მიზანი - ორიგინალი მატრიცის კოპირება და მისი ასლის ტრანსფორმირება
// ორიგინალის ცვლილების გარეშე.
// შედეგი - მხოლოდ ტრანსფორმირებული მატრიცის ეკრანზე გამოტანა.
using namespace std;
class Neo{
	private: 
		double **A;
		unsigned int n;
		unsigned int m;
	public:
		Neo(unsigned int n=1,unsigned int m=1){
			this->n=fabs(n);
			this->m=fabs(m);
			A=new double*[m];
			for(int i=0; i<m; i++)
				A[i]=new double[n];
		}
	friend istream& operator>>(istream& in,Neo& original);
	friend std::ostream& operator<<(std::ostream& out,Neo& original);
};
istream& operator>>(istream& in,Neo& original){
	for(int i=0; i<original.m;i++){
		for(int j=0; j<original.n;j++){
			cout<<"A["<<i<<"]["<<j<<"]="; 
			in>>original.A[i][j];
		}
	}
}
std::ostream& operator<<(std::ostream& out,Neo& original){
	// Neo copy=original;
	cout<<"transformed:\n";
	for(int i=0; i<original.n; i++){
		for(int j=0;j<original.m;j++){
			// cout<<copy.A[i][j]<<"="<<original.A[j][i]<<endl;
			// copy.A[i][j]=original.A[j][i];
			cout<<"A["<<i<<"]["<<j<<"]="<<original.A[j][i]<<endl;	
		}
	}
}
int main(int argc, char** argv){
	unsigned int n=0;
	unsigned int m=0;
	cout<<"m="; cin>>m;
	cout<<"n="; cin>>n;
	Neo matrix=Neo(m,n);
	cin>>matrix;
	cout<<matrix;
	return 0;
}