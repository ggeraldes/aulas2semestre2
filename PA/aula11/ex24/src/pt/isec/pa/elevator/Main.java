package pt.isec.pa.elevator;

import pt.isec.pa.elevator.UI.ElevatorUI;
import pt.isec.pa.elevator.model.fsm.ElevatorContext;

public class Main {
    public static void main(String[] args) {
        ElevatorUI elevator = new ElevatorUI(new ElevatorContext());
        elevator.start();
    }
}