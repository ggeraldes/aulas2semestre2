package pt.isec.pa.elevator.model.fsm;


import pt.isec.pa.elevator.model.data.Elevator;

public interface IElevatorState {
    boolean up();
    boolean down();
    boolean useSecurityKey(String key);
    EElevatorState getState();

    IElevatorState createState(ElevatorContext context, Elevator elevator);
}
