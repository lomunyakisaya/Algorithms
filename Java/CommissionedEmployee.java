public class CommissionedEmployee extends Employee{
    CommissionedEmployee(double sales, double rate){
        this.sales = sales;
        this.rate = rate;
    }
    double sales;
    double rate;
    void getPaid(int salary){
        return salary + rate * Sales;
    }
}