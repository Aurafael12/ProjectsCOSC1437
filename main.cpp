#include <iostream>
#include <string>
#include "Input_Validation_Extended.h"
#include <iomanip>

using namespace std;




class StudentType //Base Class *****
{
  private:
    static const int hoursPerCLass = 3;
    static const int monthsInOneSemester = 4;
    static const int semestersInAYear = 3;
    int hoursTheStudentTakes;
    int hoursInTheDegree;
    string schoolName;
    int fullTime = 12;
    int partTime = 9;
    int halfTime = 6;
 
    double costPerHour;
    double costPerClass;
    double costOfBoard;
    double costOfFood;
    double costOfBooks;
    double costOfTravel;

  public:
    StudentType()//Default Constructor ************
    {
      hoursTheStudentTakes = 0;
      hoursInTheDegree = 60;
      schoolName = "TCC";
      costPerClass = 59.00;
      costOfBooks = 100.00;
      costOfBoard = 400.00;
      costOfFood = 150.00;
      costOfTravel = 90.00;

    }
  //sets & gets STUDENT TYPE *******
  void setFullTime(int fT) { fullTime = fT; }//FullTime
  int getFullTime() const { return fullTime; }
  
  void setPartTime(int pT) { partTime = pT; }//PartTime
  int getPartTime() const { return partTime; }
  
  void setHalfTime(int hT) { halfTime = hT; }//HalfTime
  int getHalfTime() const { return halfTime; }
  
  void setCostOfBooks(double bC) { costOfBooks = bC; }//Cost Books
  double getCostOfBooks() const { return costOfBooks; }
  
  void setCostPerHour(double cH) { costPerHour = cH; }//Cost Per Hour
  double getCostPerHour() const { return costPerHour; }
  
  void setCostPerClass(double cC) { costPerClass = cC; }//Cost Per Class
  double getCostPerClass() const { return costPerClass; }
  
  void setCostOfBoard(double cB) { costOfBoard = cB; }//Cost of Board
  double getCostOfBoard() const { return costOfBoard; }
  
  void setCostOfFood(double cF) { costOfFood = cF; }//Cost of Food
  double getCostOfFood() const { return costOfFood; }
  
  void setCostOfTravel(double cT) { costOfTravel = cT; }//Cost of Travel
  double getCostOfTravel() const { return costOfTravel; }
  
  int hoursTaken = 0;
  
  //Paramaterized Constructor **********************
  StudentType(int hTST, int hID, string sN, double cPC, double bCPC, double rABC, double fCPM, double tCPM):
  hoursTheStudentTakes(hTST), hoursInTheDegree(hID), schoolName(sN), costPerClass(cPC), costOfBooks(bCPC), costOfBoard(rABC), costOfFood(fCPM), costOfTravel(tCPM) {}

  void setHoursAStudentTakes(int h) {hoursTheStudentTakes = h; }
  int getHoursAStudentTakes() const {return hoursTheStudentTakes; }
  
  void setSchoolName(string sN) {schoolName = sN; }
  string getSchoolName() const { return schoolName; }
  
  //**********************
  void showMenuVariables() 
  {
    cout << "   Cost per credit hour  $" << getCostPerClass() <<endl;
    cout << "   Book cost per class  $" << getCostOfBooks() << endl;
    cout << "   Room and Board cost per Month $" << getCostOfBoard() << endl;
    cout << "   Food cost Per Month  $" << getCostOfFood() << endl;
    cout << "   Travel Cost Per Month  $" << getCostOfTravel() << endl;
  } 
 /*void setMenuVariables()
 {
   
   double newBooks = 0.0, newBoard = 0.0, newFood= 0.0, newTravel = 0.0;
   cout << "would you like to change the Menu variables?" << endl;
   cout << "New price of books: " << endl;
   newBooks = validateDouble(newBooks);
   cout << "New cost of Board " << endl;
   newBoard = validateDouble(newBoard);
   cout << "New cost of Food " << endl;
   newFood = validateDouble(newFood);
   cout << "New cost of Travel " << endl;
   newTravel = validateDouble(newTravel);
   

   setCostOfBoard(newBoard);
   setCostOfTravel(newTravel);
   setCostOfBooks(newBooks);
   setCostOfFood(newFood);


 }*/
  
  void showConstants()
  {
    cout << "All calculations were made using the information below: " << endl;
    cout << "Full time hours taken: " << getFullTime() << endl;
    cout << "Part time hours taken: " << getPartTime() << endl;
    cout << "Half Time hours taken: " << getHalfTime() << endl;
    
  }
 
//Calculations **********

 double calculateTuition()//Tuition **
 { 
   return (hoursTheStudentTakes * costPerClass);
 }
 
 double calculateRoomAndBoard()//Room and Board **
 {
   return monthsInOneSemester * costOfBoard;
 }
 
 double calculateTravel()//Travel Costs **
 {
   return costOfTravel * monthsInOneSemester;
 }
 
 double calculateFood()//Food Cost **
 {
  return costOfFood * monthsInOneSemester;
 }
 
 double calculateBookCost()//Book Cost **
 {
  return costOfBooks * (hoursTheStudentTakes/hoursPerCLass);
 }
 double totalCostPerSemester()//Total for Semester (4mths) ****
 {
   return calculateTuition() + calculateRoomAndBoard() + calculateBookCost() + calculateFood() + calculateTravel();
 }
};//************************END BASE CLASS************************


class Cost : public StudentType //Derived Class *****************
{
 private: // c infront of variable = cost per class
  
 public:
 //setters
  /*StudentType fullTime;
  StudentType partTime;
  StudentType halfTime;*/

double menuOptions(double tuition)
{
 int c = 0;
 double hoursTaken = 0.0;

 cout << " What classificaiton of student are you considered" << endl;
 cout << "1. Full time " << endl;
 cout << "2. Part time " << endl;
 cout << "3. Half time " << endl;
 cout << "4. Change variables " << endl;

  if ( c == 1)
    {
     //cout << calculateTuition(st, classification, ratePerHour);
    }
  else if( c == 2)
    {
     //cout << calculateTuition(st, classification, ratePerHour);
    }
  else if(c == 3)
    {
     //cout << calculateTuition (st, classification, ratePerHour);
    }
  else if( c == 4)
    {
     //MenuVariables();
    }
      return tuition;
}

void changeMenu()//******************************
  {int newHours = 0;
  int newDegree= 0;
  string newSchoolName;
  double newBooks = 0.0;
  double newCostPCH = 0.0;
  double newRoomAndBoard = 0.0;
  double newFood = 0.0;
  double newTravel = 0.0;
    
    cout << "Please tell me how many hours in your degree" << endl;
    cin >> newHours;
    setHoursAStudentTakes(newHours);
    
    cout << "What is the name of your school " << endl;
    cin >> newSchoolName;
    setSchoolName(newSchoolName);
    
    cout << "What is the cost per credit hour? " << endl;
    cin >> newCostPCH;
    setCostPerHour(newCostPCH);
    
    cout << "What is the cost of books per class? " << endl;
    cin >> newBooks;
    setCostOfBooks(newBooks);
    
    cout << "What is the cost of Room and Board? " << endl;
    cin >> newRoomAndBoard;
    setCostOfBoard(newRoomAndBoard);
    
    cout << "What is the cost of food? " << endl;
    cin >> newFood;
    setCostOfFood(newFood);
    
    cout << "What is the cost of your travel? " << endl;
    cin >> newTravel;
    setCostOfTravel(newTravel);
  
  }
};


int main()//*************************************
{
  cout << fixed << setprecision(2) << endl;
  int hoursAFullTimeStudent = 12;
  int hoursAPartTimeStudent = 9;
  int hoursAHalfTimeStudent = 6;
  int classification;

  Cost C;
  StudentType fTTCC;
  StudentType pTTCC;
  StudentType hTTCC;
  
  C.showConstants();
  C.showMenuVariables();
 
  fTTCC.setHoursAStudentTakes(hoursAFullTimeStudent);
  pTTCC.setHoursAStudentTakes(hoursAPartTimeStudent);
  hTTCC.setHoursAStudentTakes(hoursAHalfTimeStudent);
  //cout << ft.calculateTuition(ft, 1, 59); // you can use the getter to get it
  //cout << pt.calculateTuition(pt, 2, 59 );
  //cout << ht.calculateTuition(ht, 3, 59);
  //showMenu();
  
 // C.changeMenu();

  /*StudentType ftCollege(hoursAFullTimeStudent, newHours, "TCU", 1565.00, 100.00, 1000.00, 150.00, 90.00);
  StudentType ptCollege(hoursAPartTimeStudent, newHours, "TCU", 1565.00, 100.00, 1000.00, 150.00, 90.00);
  StudentType htCollege(hoursAHalfTimeStudent, newHours, "TCU", 1565.00, 100.00, 1000.00, 150.00, 90.00);
  // pass semester objects by reference to display sumary results via function*/

  //calculate and display tuition for each object in teh program
  /*cout << fTTCC.calculateTuition() << endl;
  cout << pTTCC.calculateTuition() << endl;
  cout << hTTCC.calculateTuition() << endl;
  cout << ftCollege.calculateTuition() << endl;
  cout << ptCollege.calculateTuition() << endl;
  cout << htCollege.calculateTuition() << endl;*/
  cout << " " << endl;
  
  cout << fixed << setprecision(2) << endl;
  cout << "Tuition = $" << fTTCC.calculateTuition() << endl;
  cout << "Room and Board = $" << fTTCC.calculateRoomAndBoard() << endl;
  cout << "Travel = $" << fTTCC.calculateTravel() << endl;
  cout << "Food = $" << fTTCC.calculateFood() << endl;
  cout << "Books = $" << fTTCC.calculateBookCost() << endl;
  cout << "Total for the semester = $" << fTTCC.totalCostPerSemester() << endl;
  cout << " " << endl;
  cout << "Tuition = $" << pTTCC.calculateTuition() << endl;
  cout << "Room and Board = $" << pTTCC.calculateRoomAndBoard() << endl;
  cout << "Travel = $" << pTTCC.calculateTravel() << endl;
  cout << "Food = $" << pTTCC.calculateFood() << endl;
  cout << "Books = $" << pTTCC.calculateBookCost() << endl;
  cout << "Total for the semester = $" << pTTCC.totalCostPerSemester() << endl;
  cout << " " << endl;
  cout << "Tuition = $" << hTTCC.calculateTuition() << endl;
  cout << "Room and Board = $" << hTTCC.calculateRoomAndBoard() << endl;
  cout << "Travel = $" << hTTCC.calculateTravel() << endl;
  cout << "Food = $" << hTTCC.calculateFood() << endl;
  cout << "Books = $" << hTTCC.calculateBookCost() << endl;
  cout << "Total for the semester = $" << hTTCC.totalCostPerSemester() << endl;

  //calculate and display room and board costs for each object in the program.

  cout << "\n";
  C.changeMenu();
  
}