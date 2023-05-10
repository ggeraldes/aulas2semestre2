package pt.isec.pa.elevator.model.fsm;

import pt.isec.pa.elevator.model.data.Elevator;

class SecondFloorState extends ElevatorStateAdapter {

    SecondFloorState(ElevatorContext context, Elevator elevator){
        super(elevator, context);
        elevator.setCurrentFloor(2);
    }
    @Override
    public boolean down(){
        changeState(new FirstFloorState(context,elevator));
        return true;
    }

    @Override
    public EElevatorState getState(){
        return EElevatorState.SECOND_FLOOR;
    }
}

