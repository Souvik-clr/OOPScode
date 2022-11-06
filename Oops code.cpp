#include <bits/stdc++.h>
using namespace std;

// the abstraction class is here
class AbstractionEmployee {
  //	AskForPromotion is a virtual class that can be overriten through the
  //class which takes AbstractionEmployee abstraction class
  virtual void AskForPromotion() = 0;
};

class Employee
    : AbstractionEmployee /*setting the Employee class with abstraction*/
{
  //	initializing the variable in the class

private
    : // making those variable privet we can encaptulate the variable inside
      // this class.no other method outside cann directly fetch this variables.
  // this part is Encaptulated now

  string Company;
  int Age;

protected:
  string Name; // this part is only visible to the child class(Devoloper) of
               // Employee class

public
    : // by writing public i can access this methods outside of that class also.
  //    through getName and setName function outsider class can access the
  //    privet encaptulated value of this class
  void setName(string name) { Name = name; }
  string getName() { return Name; }

  //    through getCompany and setCompany function outsider class can access the
  //    privet encaptulated value of this class
  void setCompany(string company) { Company = company; }
  string getCompany() { return Company; }

  //    through getAge and setAge function outsider class can access the privet
  //    encaptulated value of this class
  void setAge(int age) {
    //    	we can also set some conditions check in it.
    if (age > 18) {
      Age = age;
    }
  }
  int getAge() { return Age; }

  //	creating a function inside this class.
  void introduce() {
    cout << "Name -> " << Name << endl;
    cout << "Company -> " << Company << endl;
    cout << "Age -> " << Age << endl;
  }
  //      creating a constructor inside the employee class ,constructor name is
  //      same as this class name.
  Employee(string name, string company, int age) {
    //    	the constructor takes the value passed at main function and set
    //    those value in the variable inside this class
    Name = name;
    Company = company;
    Age = age;
  }

  //	making the abstraction virtual function inside Employee class
  void AskForPromotion() {
    if (Age > 30)
      cout << Name << " got promoted " << endl;
    else
      cout << " sorry! you are not promoted " << endl;
  }

  //	polymorphism part is here...
  //	making the polymorphism class inside the parent class
   virtual/*(for overrriting by the child class)*/ void Work() {
    cout << Name << " is doing some task in the " << Company << endl;
  }  //try it without virtual parameter to get the usage if last two lines of code in main function
  
};
// inheritance part is here
// devoloper is a child class of employee class.so devoloper class can also
// inherite all the properties that already have to the Employee class(parent
// class)

class Devoloper /*(child)*/ : public /*(for getting the abstructed functions)*/
                              Employee /*(parent)*/ {

public:
  // this charecteristics is only applicable for this class also the inherite
  // properties from Employee class
  string FevProgLanguage;
  Devoloper(string name, string company, int age, string fevProgLanguage)  //constructor
      : Employee(name, company, age) // passing the inherited properties value
                                     // to the parent class(Employee)
  {
    // Devoloper constructor gets the value from main and pass the inherited
    // properties to the parent class and rest of the child's new properties are
    // set to local class variable( FevProgLanguage ).
    FevProgLanguage = fevProgLanguage;
  }

  // descripting function
  void FixBug() {
    cout << getName() /*from parent class*/ << " fixed bugs using "
         << FevProgLanguage /*from child  class*/ << endl;
    // we can also inherite directly from the parent's class by setting the
    // variable of parent class to protected.
    cout << Name /*from parent class*/
         << " fixed bugs using protected access modifier"
         << FevProgLanguage /*from child  class*/ << endl;
  }

  //    creating the child from of polymorphic function of parent class
  void Work() {
    // i can use the Work function specially anothor from of parent's from here.
    cout << getName() << " is doing code in " << FevProgLanguage << " always "
         << endl;
  }
};

// Teacher inherited class is here
class Teacher : public Employee {
public:
  string Subject;
  Teacher(string name, string company, int age, string subject)   //constructor
      : Employee(name, company, age) {
    Subject = subject;
  }
  void Prepration() {
    cout << getName() << " is preparing for " << Subject << " in the age of "
         << getAge() << endl;
  }

  //	creating anothor child from of polymorphic function of parent class
  void Work() {
    // i can use the Work function specially anothor from of parent's from here.
    cout << getName() << " is reading a book of " << Subject << endl;
  }
};

int main() {
  //	fetching the Employee class

  //     Employee employee1;
  //     employee1.Name="souvik";
  //     employee1.Company="i don't know";
  //     employee1.Age=22;
  //     employee1.introduce();
  //
  //     cout<<"----------------"<<endl;
  //
  //     Employee employee2;
  //     employee2.Name="sou";
  //     employee2.Company="hell";
  //     employee2.Age=32;
  //     employee2.introduce();

  // fetching the Employee class through Employee constructor

  Employee employee1 = Employee("souvik", "i don't know", 22); //obeject of employee class
  employee1.introduce();

  Employee employee2 = Employee("sou", "hell", 32);
  employee2.introduce();
  cout << "--------------------------------------------------------------------"<< endl;

  // setting and fetching the Encaptulated data of Employee class

  employee1.setAge(15);
  employee1.setName("john");

  // we can also overwrite the private value of Employee class through Encaptulation like that .
  cout << employee1.getName() << " is " << employee1.getAge() << " years old"
       << endl;

  // fetching the abstracted component through Employee class
  cout << "--------------------------------------------------------------------"<< endl;
  employee1.AskForPromotion();
  employee2.AskForPromotion();

  // setting and calling the inherited child class properties
  cout << "--------------------------------------------------------------------"
          "---"
       << endl;
  Devoloper d = Devoloper("raj roy", "amazone", 40, "c++");   //object of developer class
  d.FixBug();
  d.AskForPromotion(); // if i want to access the abstracted part through
                       // inherited class then in default that is privet in
                       // Employee class coz of inheritane of Employee class.
  // if we want to access the parent class's inherited function then make the
  // parent class public then only we can access the abstracted part of parent
  // class.

  Teacher t1 = Teacher("rajbir", "GfG", 32, "history");   //object of teacher class
  t1.Prepration();
  t1.AskForPromotion();

  cout << "--------------------------------------------------------------------"
          "---"
       << endl;
//   The most common use of polymorphism is when a parent class reference is used to prefer child class object
  // fetching the different polymorphism from of different child class
  d.Work();
  t1.Work();
  // fetching the different polymorphism from of different child class using
  // parent class's pointer
  Employee *e1 = &d;
  Employee *e2 = &t1; // pointing to the child class from parent class
  // fetching the child class's function using parent class pointer.
  // but this is not working , now it only showing the default Work function
  // which is inside the parent class.
  // so we have to make the parent class's Work function to be virtual so that
  // it can be overriten by the child class.

  e1->Work();
  e2->Work();
}
//if a constructor is created by user default constructor will be demolished automatically
