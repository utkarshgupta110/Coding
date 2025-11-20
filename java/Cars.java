// Define a class "Car"
class Cars {
    // Attributes of the class
    String brand;
    String color;
    int speed;

    // Constructor to initialize attributes
    Cars(String brand, String color, int speed) {
        this.brand = brand;
        this.color = color;
        this.speed = speed;
    }

    // Method to display car details
    void displayDetails() {
        System.out.println("Brand: " + brand);
        System.out.println("Color: " + color);
        System.out.println("Speed: " + speed + " km/h");
    }

    // Method to simulate driving
    void drive() {
        System.out.println(brand + " is driving at " + speed + " km/h.");
    }
}

