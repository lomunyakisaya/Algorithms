public class CommissionedEmployee extends Employee{
    CommissionedEmployee(double sales, double rate){
        this.sales = sales;
        this.rate = rate;
    }
    double sales;
    double rate;
    double getPaid(int salary){
        return salary + (sales * rate);
    }
}