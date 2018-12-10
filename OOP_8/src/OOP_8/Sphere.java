package OOP_8;

public class Sphere implements GeometricBody{
    double radius;

    public Sphere(double radius) {
        this.radius = radius;
    }

    @Override
    public double getSurface(){
        return 4 * Math.PI * radius * radius;
    }

    @Override
    public double getVolume(){
        return (4 * Math.PI * radius * radius * radius )/ 3;
    }

    @Override
    public void print(){
        System.out.println(" The surface area of a sphere : " + getSurface());
        System.out.println(" The volume of a sphere : " + getVolume());
    }

}
