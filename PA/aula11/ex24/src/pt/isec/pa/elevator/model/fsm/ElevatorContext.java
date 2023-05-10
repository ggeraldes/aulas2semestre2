package pt.isec.pa.elevator.model.fsm;

import pt.isec.pa.elevator.model.data.Elevator;

public class ElevatorContext {
    IElevatorState state;
    Elevator elevator;

    public ElevatorContext() {
        elevator= new Elevator(0, null);
        state = new GroundFloorState(this,elevator);
    }

    public EElevatorState getState() {
        return state.getState();
    }

    void changeState(IElevatorState newState){this.state= newState;}

    public boolean up() {return state.up();}
    public boolean down() {return state.down();}

    public boolean useSecurityKey(String key){
        return state.useSecurityKey(key);
    }
    //get data
    public int getCurrentFloor() {return elevator.getCurrentFloor();}

}
