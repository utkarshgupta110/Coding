public class Car {
    String carName;
    int carSpeed;

    // Constructor
    Car(String carName, int carSpeed) {
        this.carName = carName;
        this.carSpeed = carSpeed;
    }

    // Method to display car details
    void displayDetails() {
        System.out.println("Car name is " + carName);
        System.out.println("Car speed is " + carSpeed + " km/h.");
    }

    // Method to display custom car details
    void myCarDetails() {
        System.out.println("My car name is " + carName + " which is driving at " + carSpeed + " km/h.");
    }

    // Main method
    public static void main(String[] args) {
        Car car1 = new Car("BMW", 200);
        Car car2 = new Car("Audi", 190);
        car1.displayDetails();
        car1.myCarDetails();
        car2.displayDetails();
        car2.myCarDetails();
    }
}