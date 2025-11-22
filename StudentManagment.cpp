#include <iostream>
using namespace std;

class Person{
	public:
		string name;
		int age ;
		
		void personaldata(){
			cout<< "Enter your name please: ";
			cin>>name ;

			cout<<"Enter your Age Please: ";
			cin>>age ;
		}
};

class Marks{
	public:
		int math , science , computer ;

		void getmarks(){
			cout<<"Enter math marks: ";
			cin>>math;

			cout<<"Enter science marks: ";
			cin>>science;

			cout<<"Enter computer marks: ";
			cin>>computer;
		}
};

class Result : public Person, public Marks {
	public :
		int totalmarks ;
		float percentage ;

		void calculate(){
			totalmarks = math + science + computer ;
			percentage = totalmarks / 3.0;     // MISSING SEMICOLON FIXED
		}
		
		void showresult(){
			cout<<"\n----- Student Result -----\n";
			cout<<"Name: " << name << endl;
			cout<<"Age: " << age << endl;

			cout<<"Math Marks: " << math << endl;        // FIXED
			cout<<"Science Marks: " << science << endl;  // FIXED
			cout<<"Computer Marks: " << computer << endl; // FIXED

			cout<<"Total Marks: " << totalmarks << endl; 
			cout<<"Percentage: " << percentage << "%" << endl;
		}
};

int main(){
	Result r;
	r.personaldata();
	r.getmarks();
	r.calculate();
	r.showresult();
}

