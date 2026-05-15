#include<iostream>
#include<string>
using namespace std;

struct Employee{
    string name;
    float attendance;
    float communication;
    float productivity;
    float teamwork;
    float innovation;
    float totalScore;
    string performance;
    string risk;
    string recommendation;
};
void evaluation(Employee &e){
    e.totalScore=(e.attendance/10.0)+e.innovation+e.teamwork+e.communication+e.productivity;

    if(e.totalScore>=50){
        e.performance="EXCELLENT";
        e.risk="LOW";
        e.recommendation="Eligible for promotion";
    }
    else if(e.totalScore>=40){
        e.performance = "GOOD";
        e.risk = "LOW";
        e.recommendation = "Maintain current performance";
    }
    else if(e.totalScore>=30){
        e.performance = "AVERAGE";
        e.risk = "MEDIUM";
        e.recommendation = "Needs training and monitoring";
    }
    else{
        e.performance = "POOR";
        e.risk = "HIGH";
        e.recommendation = "Immediate improvement required";
    }
}
void display(Employee &e){
    cout<<"Employee Evaluation Report"<<endl;

    cout<<"Name: "<<e.name<<endl;
    cout<<"Attendance: "<<e.attendance<<"%"<<endl;
    cout<<"Productivity: "<<e.productivity<<"/10"<<endl;
    cout << "Teamwork       : " << e.teamwork << "/10" << endl;
    cout << "Communication  : " << e.communication << "/10" << endl;
    cout << "Innovation     : " << e.innovation << "/10" << endl;

    cout << "\nTotal Score    : " << e.totalScore << "/50" << endl;
    cout << "Performance    : " << e.performance << endl;
    cout << "Risk Level     : " << e.risk << endl;
    cout << "Recommendation : " << e.recommendation << endl;
}
void showAlerts(Employee &e){
    if(e.attendance<60){
        cout<<"Low attendace detected"<<endl;
    }
    if(e.productivity<5){
        cout<<"Not prodcutive"<<endl;
    }
    if (e.teamwork < 5)
        cout << "Teamwork improvement needed\n";

    if (e.communication < 5)
        cout << "Communication training recommended\n";

    if (e.innovation < 5)
        cout << "Skill improvement needed\n";
}

int main(){
    char again;
    do{
        Employee emp;
        cout<<"Enter employee name"<<endl;
        cin>>emp.name;

        cout<<"Enter attendace of employee"<<endl;
        cin>>emp.attendance;

         cout << "Productivity Score (0-10): ";
        cin >> emp.productivity;

        cout << "Teamwork Score (0-10): ";
        cin >> emp.teamwork;

        cout << "Communication Score (0-10): ";
        cin >> emp.communication;

        cout << "Innovation Score (0-10): ";
        cin >> emp.innovation;

        evaluation(emp);
        display(emp);
        showAlerts(emp);
        cout<<"Evaluate another employee?(y/n)"<<endl;
        cin>>again;
    }while(again=='y' || again=='Y');
    cout<<"Exper System closed"<<endl;
    return 0;
}