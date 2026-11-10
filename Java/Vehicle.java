public class Vehicle {
    public int passengersMax;
    public int fuelCapacity;
    public int consumptionKmPerLtr;
    Vehicle(int passengersMax, int fuelCapacity, int consumptionKmPerLtr){
        this.passengersMax = passengersMax;
        this.fuelCapacity = fuelCapacity;
        this.consumptionKmPerLtr = consumptionKmPerLtr;
    }
    public double getRange(){
        return this.fuelCapacity/this.consumptionKmPerLtr;
    }
}
