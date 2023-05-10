package pt.isec.pa.exerc23.model;

import java.util.Objects;

public class Vehicle implements Comparable<Vehicle> {
    protected  String registrationPlate;
    protected int year;

    public Vehicle(String registrationPlate, int year) {
        this.registrationPlate = registrationPlate;
        this.year = year;
    }

    public String getRegistrationPlate() {
        return registrationPlate;
    }

    public int getYear() {
        return year;
    }

    @Override
    public String toString(){return registrationPlate + " [" + year + "]";}

    @Override
    public boolean equals(Object o) {
        if (this == o)
            return true;
        if (o == null || !(o instanceof Vehicle))
            return false;
        Vehicle vehicle = (Vehicle) o;
        if(registrationPlate==null || vehicle.registrationPlate==null)
            return false;
        return registrationPlate.equals(vehicle.registrationPlate);
    }

    @Override
    public int hashCode() {
        return Objects.hash(registrationPlate, year);
    }

    @Override
    public int compareTo(Vehicle o) {
        return this.year - o.year;
    }
}
