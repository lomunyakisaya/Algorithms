public class CommissionedEmployee extends Employee{
    int sales;
    int rate;
    CommissionedEmployee(String name, String registrationNo, int salary, boolean isVerified, int sales, int rate){
        super(name, registrationNo, salary, isVerified);
    }
    double getPaid(int salary, int rate){
        return salary + (sales * rate);
    }
}