package pt.isec.pa.four_in_a_row.model;

import pt.isec.pa.four_in_a_row.model.data.FourInARowData;
import pt.isec.pa.four_in_a_row.model.data.Maze;
import pt.isec.pa.four_in_a_row.model.data.Piece;
import pt.isec.pa.four_in_a_row.model.memento.CareTaker;

import java.io.*;


public class FourInARowManager {

    private static final String FILE = "files/game.dat";
    FourInARowData data;
    CareTaker careTaker;

    public FourInARowManager() {
        load();
        careTaker =new CareTaker(data);
    }
    /*public FourInARowManager(FourInARowData data) {

    this.data = data;
    }*/

    public void init() {
        data.init();
    }

    public Piece getCurrentPlayer() {
        return data.getCurrentPlayer();
    }

    public boolean play(int column) {
        careTaker.save();
        return data.play(column);
    }

    @Override
    public String toString() {
        return data.toString();
    }
    public boolean isFull() {
        return data.isFull();
    }

    public Piece checkWinner() {
        return data.checkWinner();
    }

    public char [][] getBoard() {
        return data.getBoard();
    }

    public int getHeight() {
        return data.getHeight();
    }

    public int getWidth() {
        return data.getWidth();
    }

    public void save() {
        File file=new File(FILE);
        try(FileOutputStream fos = new FileOutputStream(file);
            ObjectOutputStream oos = new ObjectOutputStream(fos)){
            oos.writeObject(data);
        }catch (IOException e){
            e.printStackTrace();
            ModelLog.getInstance().add("Error saving the game");
        }
    }
    public void load() {
        File file=new File(FILE);
        try(FileInputStream fis = new FileInputStream(file);
            ObjectInputStream ois= new ObjectInputStream(fis)){
            data = (FourInARowData) ois.readObject();
            try{
                file.delete();
            }catch (Exception e){}
        }catch (Exception e){
            ModelLog.getInstance().add("There is no saved game. a new game will be created");
            data = new FourInARowData();
        }
    }

    public void undo(){
        careTaker.undo();
    }

    public void redo(){
        careTaker.redo();
    }
}
