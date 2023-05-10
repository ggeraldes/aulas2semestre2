package pt.isec.jm.javafx.basic_example.ui;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.layout.HBox;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.stage.Stage;
import javafx.scene.control.Button; // IMPORTANTE

import javax.swing.*;

public class JavaFxMain extends Application {

    private String text;
    private Button b1,b2;
    private Label l;

    @Override
    public void start(Stage stage) throws Exception {

        //cria componentes
        b1= new Button("Start");
        b2= new Button("Stop");
        l= new Label();
        text="Hi";

        //alinhamentos
        l.setAlignment(Pos.CENTER);
        l.setMinWidth(150);
        l.setTextFill(Color.STEELBLUE);
        l.setFont(Font.font("courier new", FontWeight.BOLD, 40));

        //Organiza vista
        HBox hb = new HBox();
        hb.setSpacing(10);
        hb.setAlignment(Pos.CENTER);
        hb.getChildren().addAll(b1,b2,l);
        
        //Registar handlers
        b1.setOnAction((ActionEvent ev) -> {
            text="START";
            update();
        });

        b2.setOnAction(ev -> {
            text="STOP";
            update();
        });
        
        //Criar a cena com o componente de base (root)
        Scene scene = new Scene(hb, 400, 300);
        
        stage.setTitle("My basic JavaFx Application");
        stage.setScene(scene);
        stage.show();
        update();
    }

    public void update(){
        l.setText(text);
    }
}
