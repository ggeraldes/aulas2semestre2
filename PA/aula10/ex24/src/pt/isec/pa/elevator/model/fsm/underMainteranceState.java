package pt.isec.pa.elevator.model.fsm;

import pt.isec.pa.elevator.model.data.Elevator;


class underMainteranceState extends ElevatorStateAdapter {

    underMainteranceState(ElevatorContext context, Elevator elevator){
        super(elevator, context);
        elevator.enterMainterance();
    }

    @Override
    public boolean useSecurityKey(String key){
        if(!elevator.leaveMainterance(key))
            return false;
        switch (elevator.getCurrentFloor()){
            case 0 -> changeState(new GroundFloorState(context, elevator));
            case 1 -> changeState(new FirstFloorState(context, elevator));
            case 2 ->changeState(new SecondFloorState(context, elevator));
        }

        //changeState(EElevatorState.values()[elevator.getCurrentFloor()]);
        return true;
    }

    @Override
    public EElevatorState getState(){
        return EElevatorState.UNDER_MAINTERANCE;
    }

}

