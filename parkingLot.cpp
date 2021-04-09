#include <stdio.h>
//#include <conio.h>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

int timeSpent;
int itenCarDay=0;
float tenCarDay[10];
int pushCount = 0;
int Ticket_Number;
int pos;

struct Car
  {
    string Owner_Name;
    string Licence_Plate;
    string Car_Model;
    int Ticket_Number;
    float Check_In;
    float Check_Out;
    Car *next;
  };

  class list
  {
    private:
    Car *head, *tail;
    public:
    list()
    {
      head=NULL;
      tail=NULL;
    }

  void push()
    {
    Car *temp=new Car;
      if(pushCount>10){
        cout<<"Cannot have more than 10 cars at once!"<<endl;
    }
    else{
        string Owner_Name, Licence_Plate, Car_Model;
        float Check_In;
        cout<<"Input Owner_Name: "<<endl;
        cin>>Owner_Name;
        cout<<"Input Licence_Plate: "<<endl;
        cin>>Licence_Plate;
        cout<<"Input Car_Model: "<<endl;
        cin>>Car_Model;
        cout<<"Input Check_In: "<<endl;
        cout<<"Enter time in military format (00-24) and use decimals for minutes (0.5 = 30 minutes)"<<endl;
        cin>>Check_In;

        Ticket_Number++;
        cout<<"Ticket Number: "<<Ticket_Number<<endl;

        temp->Owner_Name=Owner_Name;
        temp->Licence_Plate=Licence_Plate;
        temp->Car_Model=Car_Model;
        temp->Ticket_Number=Ticket_Number;
        temp->Check_In=Check_In;
        if(head==NULL)
      {
        head=temp;
        tail=temp;
        temp=NULL;
      }
      else
      {
        tail->next=temp;
        tail=temp;
      }
    }
    pushCount++;
}

  void pop()
  {
    cout<<"Input ticket number"<<endl;
    cin>>pos;
    Car *current=new Car;
    Car *previous=new Car;
    current=head;
    if(head==NULL)
      {
        cout<<"Stack is empty!"<<endl;
      }
      else if(head->next==NULL)
      {
        charge(Ticket_Number);
        Car *temp=new Car;
        temp=head;
        head=head->next;
        cout<<"\nDeleting Node: "<<temp->Owner_Name<<"\t"<<temp->Licence_Plate<<"\n"<<endl;
        delete temp;
        pushCount--;
      }
      else
      {
        Car *temp=new Car;
        temp=head;
        if(temp!=NULL)
        {
            bool foundTicket = false;
            while(!foundTicket){
                for(int i = 0; i<pushCount; i++){
                    if(temp->Ticket_Number==pos){
                        charge(Ticket_Number);
                        Car *temp=new Car;
                        temp=head;
                        head=head->next;
                        cout<<"\nDeleting Node: "<<temp->Owner_Name<<"\t"<<temp->Licence_Plate<<"\n"<<endl;
                        delete temp;
                        foundTicket = true;
                        break;
                    }
                    else{
                        temp=temp->next;
                    }
                }
            }//end while
        }
    }
  }

  void charge(int Ticket_Number){
      float Check_Out;
      cout<<"Input Check_Out: "<<endl;
      cout<<"Enter time in military format (00-24) and use decimals for minutes (0.5 = 30 minutes)"<<endl;
      cin>>Check_Out;

      Car *temp=new Car;
      temp=head;
      bool foundTicket = false;
      while(!foundTicket){
            if(temp->Ticket_Number==pos){
                temp->Check_Out=Check_Out;
                foundTicket = true;
            }
            else{
                temp=temp->next;
            }
      }

      float pCharge;
      timeSpent = temp->Check_Out - temp->Check_In;
      if(timeSpent < 0.5){
          pCharge = 3;
      }
      else if(timeSpent > 0.5 && timeSpent < 1){
          pCharge = 5 ;
      }
      else if(timeSpent > 1 && timeSpent < 5){
          pCharge = 10;
      }
        else if(timeSpent >  5 && timeSpent < 12){
          pCharge = 15;
      }
      else{
        pCharge=20;
      }
      pCharge+=(0.15*pCharge);
      tenCarDay[Ticket_Number] = pCharge;
      cout<<"Charge after Tax: "<<pCharge<<endl;
      itenCarDay++;
      pCharge = 0;
  }

  void estimates(){
        float sumTenCarDay = 0;
        float monthlyIncome;
        float annualIncome;
        float annualOverhead;
        float netProfitY;
        float netProfitM;

        for(int i = 0; i<10; i++){
        sumTenCarDay = sumTenCarDay + tenCarDay[i];
        monthlyIncome = sumTenCarDay * 7 * 4; //7 days and 4 weeks
        annualIncome = sumTenCarDay * 365;
        annualOverhead = annualIncome*0.55;
        netProfitY = annualIncome*0.45;
        netProfitM = netProfitY/12;
      }
        cout<<"Ten Day Estimate: " <<sumTenCarDay<<endl;
        cout<<"Monthly Income: " <<monthlyIncome<<endl;
        cout<<"Annual Income: " <<annualIncome<<endl;
        cout<<"Annual Overhead: " <<annualOverhead<<endl;
        cout<<"Monthly Net Profit: " <<netProfitM<<endl;
        cout<<"Yearly Net Profit: " <<netProfitY<<endl;

  }

  void display()
  {
      cout<<"Displaying nodes: \n"<<endl;
      Car *temp=new Car;
      temp=head;
      cout<<"Owner_Name \t";
      cout<<"Licence_Plate \t";
      cout<<"Car_Model \t";
      cout<<"Ticket_Number \t";
      cout<<"Check_In \t";
      cout<<"Check_Out"<<endl;

    while(temp!=NULL)
    {
      cout<<temp->Owner_Name<<"\t \t";
      cout<<temp->Licence_Plate<<"\t \t";
      cout<<temp->Car_Model<<"\t \t";
      cout<<temp->Ticket_Number<<"\t \t";
      cout<<temp->Check_In<<"\t \t";
      cout<<temp->Check_Out<<endl;
      temp=temp->next;
    }
  }
};

  void menuChoice(list obj){
        int choice;
        do{
        cout<<"\nEnter 1 to push, \nEnter 2 to pop, \nEnter 3 to display all nodes, \nEnter 4 to display estimates, \nEnter 5 to exit"<<endl;
        cin>>choice;
        if(choice == 1){
            obj.push();
            choice = NULL;
        }
        else if(choice == 2){
            obj.pop();
        }
        else if(choice == 3){
            obj.display();
        }
        else if(choice == 4){
            obj.estimates();
        }
        else if(choice == 5){
            break;
        }
        else{
            cout<<"Invalid Input!"<<endl;
        }
    }while(choice != 5);
    //end do while
  }

  int main(){
    list obj;
    menuChoice(obj);
    return 0;
  }
