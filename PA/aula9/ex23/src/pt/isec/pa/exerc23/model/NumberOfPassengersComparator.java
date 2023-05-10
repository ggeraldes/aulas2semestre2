package pt.isec.pa.exerc23.model;

import java.util.Comparator;

public class NumberOfPassengersComparator implements Comparator<IPassengers> {

    @Override
    public int compare(IPassengers v1, IPassengers v2) {
        return v1.getMaxPassengers() - v2.getMaxPassengers();
    }
}
