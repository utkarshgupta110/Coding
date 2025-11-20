public  class Main {     
    public static void main(String[] args) {
        // Create objects (instances) of Car
        Cars car1 = new Cars("Toyota", "Red", 120);
        Cars car2 = new Cars("Honda", "Blue", 150);

        // Access attributes and methods of objects
        car1.displayDetails();
        car1.drive();
        car2.displayDetails();
        car2.drive();
    }
} 
