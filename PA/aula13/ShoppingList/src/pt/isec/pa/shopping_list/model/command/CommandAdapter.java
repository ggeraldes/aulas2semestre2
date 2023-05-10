package pt.isec.pa.shopping_list.model.command;

import pt.isec.pa.shopping_list.model.data.ShoppingList;

abstract class CommandAdapter implements ICommand {
    protected ShoppingList receiver;
    protected CommandAdapter(ShoppingList receiver) {
        this.receiver = receiver;
    }
}
