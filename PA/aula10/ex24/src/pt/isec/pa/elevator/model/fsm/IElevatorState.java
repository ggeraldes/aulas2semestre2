package pt.isec.pa.elevator.model.fsm;


public interface IElevatorState {
    boolean up();
    boolean down();
    boolean useSecurityKey(String key);
    EElevatorState getState();
}
