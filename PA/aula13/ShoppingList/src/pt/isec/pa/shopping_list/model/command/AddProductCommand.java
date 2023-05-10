package pt.isec.pa.shopping_list.model.command;

import pt.isec.pa.shopping_list.model.data.ShoppingList;

public class AddProductCommand extends CommandAdapter {

    private final String name;

    private final double qt;

    public AddProductCommand(ShoppingList receiver, String name, double qt){
        super(receiver);
        this.name=name;
        this.qt=qt;
    }

    @Override
    public boolean execute() {return receiver.addProduct(name,qt);}

    @Override
    public boolean undo() {return receiver.removeProduct(name,qt);}


}
