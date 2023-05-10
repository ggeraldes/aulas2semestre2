package pt.isec.pa.elevator.model.fsm;

import pt.isec.pa.elevator.model.data.Elevator;

public enum EElevatorState {
    GROUND_FLOOR, FIRST_FLOOR, SECOND_FLOOR, UNDER_MAINTERANCE;

        //static IElevatorState createState(EElevatorState type, ElevatorContext context, Elevator elevator){}

    IElevatorState createState(ElevatorContext context, Elevator elevator){
            return switch (this){
                case GROUND_FLOOR -> new GroundFloorState(context, elevator);
                case FIRST_FLOOR -> new FirstFloorState(context, elevator);
                case SECOND_FLOOR -> new SecondFloorState(context, elevator);
                case UNDER_MAINTERANCE -> new underMainteranceState(context, elevator);
            };
    }

}
