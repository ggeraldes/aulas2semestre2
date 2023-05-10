package pt.isec.pa.elevator.model.data;

public class Elevator {

    private int currentFloor;
    private String securityKey=null;
    private boolean underMainterance = false;
    public Elevator(int currentFloor, String securityKey) {

        this.currentFloor = currentFloor;
        this.securityKey=securityKey;
        //ModelLog.getInstance().add("Elevator:Construct");
    }

    public int getCurrentFloor() {
        return currentFloor;
    }

    public boolean setCurrentFloor(int currentFloor) {

        if(underMainterance)
                return false;

        this.currentFloor = currentFloor;
        return true;
    }

    public String getSecurityKey() {
        return securityKey;
    }

    public boolean isUnderMainterance() {
        return underMainterance;
    }

    public boolean setSecurityKey(String oldSecurityKey, String newSecurityKey) {
        if(!securityKey.equals(oldSecurityKey))
            return false;

        this.securityKey = newSecurityKey;
        return true;
    }

    public boolean enterMainterance() {
        this.underMainterance=true;
        return true;
    }
    public boolean leaveMainterance(String securityKey){
        if(this.securityKey!=null && !this.securityKey.equals(securityKey))
            return false;
        this.underMainterance=false;
        return true;
    }

    @Override
    public String toString() {
        return "Elevator{" +
                "currentFloor=" + currentFloor + (underMainterance?"(under mainterance)":"")+
                '}';
    }
}
