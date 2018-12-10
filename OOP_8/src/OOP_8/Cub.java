package OOP_8;

public class Cub implements GeometricBody{
    double side;

    public Cub (double side){ this.side = side; }

    @Override
    public double getVolume()
    {
        return side * side * side;
    }

    @Override
    public double getSurface(){
       return 6 * (side * side);
    }

    //print surface and volume of figure
    @Override
    public void print() {
        System.out.println( " The surface area of a cube : " + getSurface());
        System.out.println( " The volume of a cube : " + getVolume());
    }

}
