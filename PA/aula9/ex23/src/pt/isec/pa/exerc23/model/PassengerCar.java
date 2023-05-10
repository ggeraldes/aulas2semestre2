package pt.isec.pa.exerc23.model;

public class PassengerCar extends Vehicle implements IPassengers{

    protected int maxPass;
    public PassengerCar(String registrationPlate, int year, int maxPass) {
        super(registrationPlate, year);
        this.maxPass=maxPass;
    }

    @Override
    public int getMaxPassengers() {
        return maxPass;
    }

    @Override
    public String toString(){return super.toString()+ "MaxPass: "+maxPass+ "]";}
}
