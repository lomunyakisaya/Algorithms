public class Main {
    public static void main(String[] args){
        System.out.println("Hello Java");
        Birds B1 = new Birds("Secretary Bird", "N/A");
        B1.peking();
        Vehicle taxi = new Vehicle(7, 20, 10);
        double maxDistance=taxi.getRange();
        System.out.print("The max Safe Distance is: " + maxDistance);
    }
}