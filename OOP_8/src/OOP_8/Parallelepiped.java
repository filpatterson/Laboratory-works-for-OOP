package OOP_8;

public class Parallelepiped implements GeometricBody{
    private double length;
    private double width;
    private double height;

    public Parallelepiped(double length, double width, double height) {
        this.length = length;
        this.width = width;
        this.height = height;
    }

    @Override
    public double getSurface(){ return 2 * length * width + 2 * length * height + 2 * width * height; }

    @Override
    public double getVolume(){ return length * width * height; }

    @Override
    public void print() {
        System.out.println( " The surface area of a rectangular parallelepiped : " + getSurface());
        System.out.println( " The volume of a rectangular parallelepiped : " + getVolume());
    }
}
