package pt.isec.henrique.aula8ex19;

import pt.isec.henrique.aula8ex19.model.*;
import pt.isec.henrique.aula8ex19.ui.LibraryUI;

import java.util.List;

public class Main {

    public static void main(String[] args) {
        // Injeção da dependência é feita no construtor da classe LibraryUI
        new LibraryUI(new LibraryList("ISEC Library")).start();
        //new LibraryUI(new LibrarySet("ISEC Library")).start();
        //new LibraryUI(new LibraryMap("ISEC Library")).start();
    }
}
