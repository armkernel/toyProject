#include <iostream>

using namespace std;

class Cell {
  protected:
    int x, y;
    // 상호 참조 문제 
    //Table* table;

    string data;
  
  public:
    virtual string stringify();
    virtual int to_numeric();

  Cell(string data, int x, int y);
};

Cell::Cell(string data, int x, int y)
    : data(data), x(x), y(y){}

string Cell::stringify() { return data; }
int Cell::to_numeric() { return 0; }



class Table {
  protected:
    int max_row_size, max_col_size;

    Cell*** data_table;

  public:
    Table(int max_row_size, int max_col_size);

    ~Table();

    // 새로운 셀을 row 행 col 열에 등록함
    void reg_cell(Cell* c, int row, int col);

    // 해당 셀의 정수값을 반환 
    // 즉, 셀 이름을 입력하면 정수값 반환
    int to_numeric(const string& s);
    
    int to_numeric(int row, int col);
    
    // 해당 셀의 문자열을 반환
    string stringify(const string& s);
    string stringify(int row, int col);

    // 0으로 두는 이유? 
    // 순수 가상함수라는 뜻 
    // 순수 가상함수란 구현이 없는 가상함수르 말함
    virtual string print_table() = 0; 
};

Table::Table(int max_row_size, int max_col_size)
      :max_row_size(max_row_size), max_col_size(max_col_size){

    // 초기화 
    data_table = new Cell**[max_row_size];
    for (int i = 0; i < max_row_size; i++) {

      data_table[i] = new Cell*[max_col_size];
      for (int j = 0; j < max_col_size; j++) {
        data_table[i][j] = NULL;
      }
    }
}

Table::~Table() {
  for (int i = 0; i < max_row_size; i++) {
    for (int j = 0; j < max_col_size; j++) {
      // 데이터가 있으면, 지워라
      if (data_table[i][j]) delete data_table[i][j];
    }
  }

  // delete pointer array 
  for (int i = 0; i < max_row_size; i++) delete[] data_table[i];

  delete[] data_table;

  // 순차적으로 1차원 2차원 3차원순으로 지워야함
}

void Table::reg_cell(Cell* c, int row, int col) 
{
  if (! (row < max_row_size && col < max_col_size)) return; 
  // data_table[row][col]을 삭제하는 이유는 실제 가리키고 있는 포인터를 제거하기 위해서이다.
  if (data_table[row][col]) delete data_table[row][col];

  data_table[row][col] = c;
}

int Table::to_numeric(const string& s) {

}


int main()
{
  return 0;
};

















