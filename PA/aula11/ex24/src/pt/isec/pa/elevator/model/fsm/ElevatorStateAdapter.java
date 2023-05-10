package pt.isec.pa.elevator.model.fsm;
import pt.isec.pa.elevator.model.data.Elevator;

abstract class ElevatorStateAdapter implements IElevatorState {

    protected Elevator elevator;
    protected ElevatorContext context;

    public ElevatorStateAdapter(Elevator elevator, ElevatorContext context) {
        this.elevator = elevator;
        this.context = context;
    }

    protected void changeState(IElevatorState newState){
        context.changeState(newState.createState(context, elevator));
    };


    @Override
    public boolean up() {return false;}

    @Override
    public boolean down() {return false;}

    @Override
    public boolean useSecurityKey(String key){return false;}
}
