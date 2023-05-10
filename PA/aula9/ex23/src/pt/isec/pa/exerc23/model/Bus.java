package pt.isec.pa.exerc23.model;

public class Bus extends Vehicle implements  IMaxLoad, IPassengers{

    protected int maxPass;
    protected int maxCarg;


    public Bus(String registrationPlate, int year, int maxPass, int maxCarg) {
        super(registrationPlate, year);
        this.maxPass=maxPass;
        this.maxCarg=maxCarg;
    }
    @Override
    public int getMaxPassengers() {
        return maxPass;
    }

    @Override
    public int getMaxWeight() {
        return maxCarg;
    }

    @Override
    public String toString(){return super.toString()+ ", MaxPass: "+maxPass+ ", MaxCarg: "+maxCarg+ "]";}
}
