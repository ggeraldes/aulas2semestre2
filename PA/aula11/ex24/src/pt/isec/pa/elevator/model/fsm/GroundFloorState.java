package pt.isec.pa.elevator.model.fsm;

import pt.isec.pa.elevator.model.data.Elevator;

class GroundFloorState extends ElevatorStateAdapter {

        GroundFloorState(ElevatorContext context, Elevator elevator){
            super(elevator, context);
            elevator.setCurrentFloor(0);
        }

        @Override
        public boolean up(){
            double d = Math.random();
            if(d>0.9){
                changeState(new underMainteranceState(context, elevator));
                return true;
            }
                changeState(new FirstFloorState(context,elevator));
                return true;
        }

        @Override
        public EElevatorState getState(){
            return EElevatorState.GROUND_FLOOR;
        }

}
