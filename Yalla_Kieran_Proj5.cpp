
/*
* Class: CMSC140 CRN
* Instructor: Prof. Koo
* Project<5>
* Description: Write a program that simulates a magic square using 3 one dimensional parallel arrays of integer type. 
* Due Date: 12/07/21
* I pledge that I have completed the programming assignment independently.
I have not copied the code from a student or any source.
I have not given my code to any student.
Print your Name here: Kieran Yalla
*/

#include<iostream>
using namespace std;

// Global constants
const int ROWS = 3;
const int COLS = 3;
const int MIN = 1;
const int MAX = 9;

// functions prototypes.
bool isMagicSquare(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkRange(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int min, int max);
bool checkUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkRowSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkColSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkDiagSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
void fillArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
void showArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);

// main() function or the driver function.
int main() {
  int row1[3], row2[3], row3[3], size = 3;
  char ch;
  do {
    fillArray(row1, row2, row3, size);

    if (isMagicSquare(row1, row2, row3, size))
      cout << "\nThis is a Lo Shu magic square." << endl;
    else
      cout << "\nThis is not a Lo Shu magic square." << endl;
    cout << "\nDo you want to try again?";
    cin >> ch;
  } while (ch == 'y' || ch == 'Y');
  cout << "Name: Kieran Yalla " << endl;
  cout << "Project #: 5 " << endl;
  cout << "Due Date: 12/07/21" << endl;
  return 0;
}


// isMagicSquare() function defination.
bool isMagicSquare(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size){
  if (checkRange(arrayRow1, arrayRow2, arrayRow3, size, MIN, MAX) and checkUnique(arrayRow1, arrayRow2, arrayRow3, size) and checkRowSum(arrayRow1, arrayRow2, arrayRow3, size) and checkColSum(arrayRow1, arrayRow2, arrayRow3, size) and checkDiagSum(arrayRow1, arrayRow2, arrayRow3, size))
    return true;
  return false;
}

// checkRange() function defination.
bool checkRange(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int min, int max){
  for (int i = 0; i < size; i++) {
    if (arrayRow1[i] < MIN or arrayRow1[i] > MAX)
      return false;
    if (arrayRow2[i] < MIN or arrayRow2[i] > MAX)
      return false;
    if (arrayRow3[i] < MIN or arrayRow3[i] > MAX)
      return false;
  }
  return true;
}

// checkUnique() function defination.
bool checkUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size){
  bool check[9] = {
    false
  };
  for (int i = 0; i < size; i++){
    if (check[arrayRow1[i] - 1])
      return false;
    check[arrayRow1[i] - 1] = true;
  }
  return true;
}

// checkRowSum() function defination.
bool checkRowSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size){
  int sum1 = 0, sum2 = 0, sum3 = 0;
  for (int i = 0; i < size; i++)
    sum1 += arrayRow1[i];
  for (int i = 0; i < size; i++)
    sum2 += arrayRow2[i];
  for (int i = 0; i < size; i++)
    sum3 += arrayRow3[i];
  return ((sum1 == sum2) and(sum2 == sum3));
}

// checkColSum() function defination.
bool checkColSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size){
  int sum[size] = {
    0
  };
  for (int i = 0; i < size; i++)
    sum[i] += arrayRow1[i] + arrayRow2[i] + arrayRow3[i];
  return ((sum[0] == sum[1]) and(sum[1] == sum[2]));
}

// checkDiagSum() function defination.
bool checkDiagSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size){
  int sum1 = arrayRow1[0] + arrayRow2[1] + arrayRow3[2];
  int sum2 = arrayRow1[2] + arrayRow2[1] + arrayRow3[0];
  return (sum1 == sum2);
}

// fillArray() function defination.
void fillArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size){
  for (int i = 0; i < size; i++) 
  {
    cout << "Enter the value for row 0 and " << "column " << i << " : ";
    cin >> arrayRow1[i];
  }
  for (int i = 0; i < size; i++) 
  {
    cout << "Enter the value for row 1 and " << "column " << i << " : ";
    cin >> arrayRow2[i];
  }
  for (int i = 0; i < size; i++) 
  {
    cout << "Enter the value for row 2 and " << "column " << i << " : ";
    cin >> arrayRow3[i];
  }

  // display input matrix
  for (int i = 0; i < size; i++)
    cout << arrayRow1[i] << "  ";
  cout << endl; 
  for (int i = 0; i < size; i++)
    cout << arrayRow2[i] << "  ";
  cout << endl; 
  for (int i = 0; i < size; i++)
    cout << arrayRow3[i] << "  ";
}

// showArray() function defination.
void showArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size){
  cout << "\nEntered Array: " << endl;
  for (int i = 0; i < size; i++)
    cout << arrayRow1[i] << " ";
  cout << endl;
  for (int i = 0; i < size; i++)
    cout << arrayRow1[i] << " ";
  cout << endl;
  for (int i = 0; i < size; i++)
    cout << arrayRow1[i] << " ";
  cout << endl;
}