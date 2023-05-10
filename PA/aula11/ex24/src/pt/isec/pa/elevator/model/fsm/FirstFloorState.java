package pt.isec.pa.elevator.model.fsm;

import pt.isec.pa.elevator.model.data.Elevator;


    class FirstFloorState extends ElevatorStateAdapter {

        FirstFloorState(ElevatorContext context, Elevator elevator){
            super(elevator, context);
            elevator.setCurrentFloor(1);
        }

        @Override
        public boolean up(){
            changeState(new SecondFloorState(context,elevator));
            return true;
        }

        @Override
        public boolean down(){
            changeState(new GroundFloorState(context,elevator));
            return true;
        }

        @Override
        public EElevatorState getState(){
            return EElevatorState.FIRST_FLOOR;
        }

    }

