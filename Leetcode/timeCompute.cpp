#include<iostream>

using namespace std;

class Ttime{
public:
	Ttime(int hours, int minutes){
		this->_hours = hours;
		this->_minutes = minutes;
	}
	bool operator <(Ttime& time){
		return (this->_hours * 60 + this->_minutes) <(time._hours * 60 + time._minutes);
	};
	void addMinutes(int minutes){
		this->_hours += (this->_minutes + minutes)/60;
		this->_minutes = (this->_minutes + minutes) % 60;
	}
	friend ostream& operator<< (ostream &os, Ttime &st)
		    {
		        os << st._hours<<":"<<st._minutes;
		        return os;
		    }

	int _hours;
	int _minutes;
};
//int main(){
//	
//	int number = 0;
//	 Ttime begin(8, 0);
//	 Ttime end(11, 30);
//	do{
//		 cout <<number++<<"  "<< begin << "---";
//		 begin.addMinutes(25);
//		 cout << begin << endl;
//
//	} while (begin < end);
////	 number = 0;
//	 Ttime aBegin(2,30);
//	 Ttime bEnd(6,30);
//	 do{
//		 cout << number++ << "  " << aBegin << "---";
//		 aBegin.addMinutes(25);
//		 cout << aBegin << endl;
//	 }	 while (aBegin < bEnd);
//
//}