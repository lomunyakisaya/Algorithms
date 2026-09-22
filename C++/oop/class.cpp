#include <iostream>
using namespace std;

class Student {
    public:
    Student(string studentname, string studentRegNo, string studentgender, string studentContact){
        name= studentname;
        regNo = studentRegNo;
        gender = studentgender;
        contact = studentContact;
    }
    //has
    string name;
    string regNo;
    string gender;
    string contact;
    //Does
    void introduce(){
        cout << "My name is "<< name <<" and my Registration Number is "<< regNo <<". I am a "<< gender <<". My contact is "<<contact<<endl;
    }
};
int main(){
    Student student1("Lomunyak", "ENE221-0215/2025", "Male", "0716967496");
    student1.introduce();
}