package pt.isec.pa.exerc23.model;

public class Cargo extends Vehicle implements  IMaxLoad{

    protected int maxCarg;
    public Cargo(String registrationPlate, int year, int maxCarg) {
        super(registrationPlate, year);
        this.maxCarg=maxCarg;
    }
    @Override
    public int getMaxWeight() {
        return maxCarg;
    }

    @Override
    public String toString(){return super.toString()+ ", MaxCarg: "+maxCarg+ "]";}
}
