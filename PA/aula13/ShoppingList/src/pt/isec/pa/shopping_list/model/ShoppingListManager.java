package pt.isec.pa.shopping_list.model;

import pt.isec.pa.shopping_list.model.command.AddProductCommand;
import pt.isec.pa.shopping_list.model.command.CommandManager;
import pt.isec.pa.shopping_list.model.command.RemoveProductCommand;
import pt.isec.pa.shopping_list.model.data.Product;
import pt.isec.pa.shopping_list.model.data.ShoppingList;

public class ShoppingListManager {
    ShoppingList rc;
    CommandManager cm;
    public ShoppingListManager() {
        rc = new ShoppingList();
        cm = new CommandManager();
    }
    public boolean addProduct(String name, double qt) {
        return cm.invokeCommand(new AddProductCommand(rc, name, qt));
    }
    public boolean removeProduct( String name, double qt) {
        return cm.invokeCommand(new RemoveProductCommand(rc, name, qt));
    }

    public boolean undo() { return cm.undo(); }
    public boolean redo() { return cm.redo(); }

    @Override
    public String toString() {

        return rc.toString();
    }
}
