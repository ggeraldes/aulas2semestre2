package pt.isec.pa.exerc23.model;

import java.lang.invoke.VarHandle;
import java.util.*;

public class Fleet {

    private String name;
    private Set<Vehicle> setVehicles;

    public Fleet(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public boolean addVehicle(Vehicle vehicle){return setVehicles.add(vehicle);}
    public boolean removeVehicle(Vehicle vehicle){return setVehicles.remove(vehicle);}

    public boolean removeVehicles(String regPlate){
        //return setVehicles.removeIf(o -> o.registrationPlate.equals(regPlate));

       Vehicle dummyVehicle = new Vehicle(regPlate, 0);
       return removeVehicle(dummyVehicle);
    }

    @Override
    public String toString(){
        StringBuilder sb=new StringBuilder(String.format("Fleet: %s\n", name));
        sb.append("Vehicles: \n");
        if(setVehicles==null || setVehicles.size()==0)
            sb.append("No vehicles");
        else
            for(Vehicle v : setVehicles)
                sb.append(String.format("\t- %s\n", v.toString()));

        return sb.toString();
    }

    public String toStringSortByMaxOfPassengers(){
        StringBuilder sb=new StringBuilder(String.format("Fleet: %s\n", name));
        sb.append("Vehicles: \n");
        if(setVehicles==null || setVehicles.size()==0)
            sb.append("No vehicles");

        List<IPassengers> temp = new ArrayList<>();
        for(Vehicle v : setVehicles)
            if(v instanceof IPassengers vp)
                temp.add(vp);
        if(temp.size()==0)
            sb.append("No passenger vehicles");
        else{
            Collections.sort(temp, new NumberOfPassengersComparator());
            for(var v:temp)
                sb.append(String.format("\t - %s\n", v.toString()));
        }

    return sb.toString();

    }


}
