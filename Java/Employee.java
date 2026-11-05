public class Employee{
    Employee(String name, String registrationNo, int salary, boolean isVerified){
        this.name = name;
        this.registrationNo = registrationNo;
        this.salary = salary;
        this.isVerified = isVerified;
    }
    String name;
    String registrationNo;
    double salary;
    boolean isVerified;
    void introduce(){
        System.out.print("I am: " + this.name + " RegNo: " + this.registrationNo + " and is verified is " + this.isVerified);
    }
}
