package pt.isec.pa.elevator.UI;

import pt.isec.pa.elevator.model.fsm.ElevatorContext;
import pt.isec.pa.utils.PAInput;

public class ElevatorUI {
    ElevatorContext fsm;

    boolean finish;

    public ElevatorUI(ElevatorContext fsm) {
        this.fsm = fsm;
    }

    public void groundFloorUI(){
        System.out.println("Ground Floor");
        if(1 == PAInput.chooseOption("ELevator", "up", "quit"))
            fsm.up();
        else
            finish= true;
    }

    public void firstFloorUI(){
        System.out.println("Ground Floor");
        if(1 == PAInput.chooseOption("ELevator", "up", "down", "quit"))
            fsm.up();
        else
            finish= true;
    }

    public void secondFloorUI(){
        System.out.println("Ground Floor");
        if(1 == PAInput.chooseOption("ELevator", "up", "quit"))
            fsm.up();
        else
            finish= true;
    }

    public void underMainteranceUI(){
        System.out.println(("Elevator curent floor: "+fsm.getCurrentFloor()));
        System.out.println(("**** Elevator under mainterance ****"));
        if(1== PAInput.chooseOption("Elevator", "User security key", "mainterance", "quit"))
            finish=true;
    }
    public void start() {
        while(!finish){
            switch (fsm.getState()){
                case GROUND_FLOOR -> groundFloorUI();
                case FIRST_FLOOR -> firstFloorUI();
                case SECOND_FLOOR -> secondFloorUI();
                case UNDER_MAINTERANCE -> underMainteranceUI();
            }
        }

        /*int op;
        do{
            System.out.println("Elevator current floor: "+fsm.getCurrentFloor() +
                    " (" + fsm.getState() + ")");
            op = PAInput.chooseOption("Elevaor", "up", "down", "quit");
            switch (op){
                case 1 -> fsm.up();
                case 2 -> fsm.down();
            }
        }while(op!=3);*/
    }


}
