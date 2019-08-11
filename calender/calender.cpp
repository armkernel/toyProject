#include <iostream>

using namespace std;

const string day[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
const int end_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int end_mod_month[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
class Cal 
{
    public:
        void print( int year, int mon );
        void print( int year, int mon, int day );
    private:
        // class 안에 초기화된 변수 넣을 수 없다. 
        // 생성자를 이용해서 초기화 해야함
        int dow( int year, int mon );
};


void Cal::print( int year, int mon )
{
    cout << "\t\t" << year << " 년  " << mon << " 월 " << endl;

    for (int i = 0; i < 7; i++) cout << day[i] << "\t";
    cout << endl;

    int space = dow(year,mon);

    for (int i = 0; i < space; i++) cout << "   " << "\t";

    for (int i = 1; i <= end_month[mon - 1]; i++) {

        if (space%7 == 0) {
            cout << endl;
            space = 0;
        }

        space ++; 
        cout << " "<< i << " " << "\t";
    }

    //cout << "!!" << dow(year,mon) << endl;
    return;
}


int Cal::dow( int year, int mon ) 
{
    if ( mon < 3 ) year -= 1;
    int space = (year + year/4 - year/100 + year/400 + end_mod_month[mon-1])%7;

    return space + 1;
}


int main() 
{
   // 0년 1월 1일 기준 
   //

   // input 2019 8 9

   Cal c;
   int year, mon;
   cin >> year >> mon;
   c.print(year, mon);
}
