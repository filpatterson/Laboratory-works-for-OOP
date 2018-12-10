package OOP_8;

public class Main {
    public static void main(String[] args) {

        //create new objects
        Cub cub = new Cub(5);
        Sphere sphere = new Sphere(8);
        Parallelepiped parallelepiped = new Parallelepiped(10,7,4);

        //push those objects to the array
        GeometricBody[] geometricBody = {cub, sphere, parallelepiped};

        //here we find figure with biggest area and volume
        System.out.println("Figure with biggest volume: " + GeometricBodyController.getBiggestVolume(geometricBody) +
                            "\t\t Volume of this figure is " +
                            GeometricBodyController.getBiggestVolume(geometricBody).getVolume());
        System.out.println("Figure with biggest area: " + GeometricBodyController.getBiggestArea(geometricBody) +
                            "\t\t Area of this figure is " +
                            GeometricBodyController.getBiggestArea(geometricBody).getSurface());

        //here we print all properties of figures considering predefined functions
        for (GeometricBody figure: geometricBody){
            figure.print();
        }
    }
}
