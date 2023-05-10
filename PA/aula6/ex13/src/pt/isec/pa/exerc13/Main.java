package pt.isec.pa.exerc13;

import pt.isec.pa.exerc13.Model.ILibrary;
import pt.isec.pa.exerc13.Model.Library;
import pt.isec.pa.exerc13.ui.LibraryUI;

public class Main {
    public static void main(String[] args) {
        Library lib = new Library("DEIS-ISEC");
        LibraryUI libUi= new LibraryUI(lib);
        libUi.start();

    }
}