package pt.isec.pa.shopping_list.model.command;

import pt.isec.pa.shopping_list.model.data.ShoppingList;

public class RemoveProductCommand extends CommandAdapter{
    private final String name;

    private final double qt;

    public RemoveProductCommand(ShoppingList receiver, String name, double qt){
        super(receiver);
        this.name=name;
        this.qt=qt;
    }

    @Override
    public boolean execute() {return receiver.removeProduct(name,qt);}

    @Override
    public boolean undo() {return receiver.addProduct(name,qt);}
}
