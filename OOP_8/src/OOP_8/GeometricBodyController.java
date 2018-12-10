package OOP_8;

public class GeometricBodyController {

    static GeometricBody getBiggestVolume(GeometricBody geometricBodies[]){

        GeometricBody biggestVolume = geometricBodies[0];

        for (GeometricBody body: geometricBodies){  //check all bodies of type GeometricBody that are inside of
                                                    //geometricBodies[] array
            if (body.getVolume() > biggestVolume.getVolume()){  //finds biggest volume
                biggestVolume = body;
            }
        }
        return biggestVolume;
    }

    static GeometricBody getBiggestArea(GeometricBody geometricBodies[]){

        GeometricBody biggestArea = geometricBodies[0];

        for (GeometricBody body: geometricBodies){  //the same principle of work as in previous function
            if (body.getSurface() > biggestArea.getSurface())
                biggestArea = body;
        }
        return biggestArea;
    }
}
