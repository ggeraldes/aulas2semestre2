package pt.isec.pa.ex28.ui;


import javafx.event.ActionEvent;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.input.KeyCode;
import javafx.scene.layout.*;
import javafx.scene.paint.Color;

public class RootPane extends BorderPane {

    Color background= Color.WHITE;
    int nrGreen,nrBlue, nrOther;
    Button btnGreen;
    Button btnBlue;
    TextField tfColor;
    Button btnCustomColor;
    Label lbStatus;

    public RootPane() {
        nrGreen=nrBlue=nrOther=0;
        createViews();
        registerHandler();
        update();
    }

    public void createViews(){

        btnBlue = new Button("Blue");
        btnBlue.setMinWidth(75);
        btnGreen = new Button("Green");
        btnGreen.setMinWidth(75);
        tfColor = new TextField();
        tfColor.setPromptText("Search...");
        tfColor.setPrefWidth(Integer.MAX_VALUE);
        tfColor.setMinWidth(200);
        btnCustomColor = new Button("Change");
        btnCustomColor.setMinWidth(75);


        //Organiza vista
        HBox hb = new HBox();
        hb.setPadding(new Insets(10));
        hb.setSpacing(10);
        hb.getChildren().addAll(btnGreen,btnBlue,tfColor, btnCustomColor);
        this.setTop(hb);
        this.setBottom(lbStatus);

        lbStatus=new Label();
        lbStatus.setPrefWidth(Integer.MAX_VALUE);
        lbStatus.setStyle("-fx-background-color:#c0c0c0; -fx-font-size: 16; -fx-font-family: 'Courier New'");
        lbStatus.setBorder(new Border(new BorderStroke(Color.DARKGRAY, BorderStrokeStyle.SOLID,
                CornerRadii.EMPTY, BorderWidths.DEFAULT)));
        lbStatus.setPadding(new Insets(10));
        this.setBottom(lbStatus);



    }
    public void registerHandler(){

        btnGreen.setOnAction((ActionEvent ev) -> {
           nrGreen++;
           background = Color.GREEN;
           update();
        });

        btnBlue.setOnAction(ev -> {
            nrBlue++;
            background = Color.BLUE;
            update();
        });

        btnCustomColor.setOnAction(ev -> {
            tfColor.setStyle("-fx-background-color: white");
            nrOther++;
            try {
                background = Color.valueOf(tfColor.getText());
            }catch (Exception e){
                background = Color.BLACK;
                tfColor.setStyle("-fx-background-color: red");
                tfColor.requestFocus();
            }
            update();
        });

        tfColor.setOnKeyPressed(keyEvent -> {

            tfColor.setStyle("-fx-background-color: white");

            if(keyEvent.getCode()== KeyCode.ENTER){
                btnCustomColor.fire();
            }
        });

    }
    public void update(){
        this.setBackground(new Background(new BackgroundFill(background, CornerRadii.EMPTY, Insets.EMPTY)));
        lbStatus.setText("Green: "+nrGreen+" \t Blue: "+nrBlue+" \t Other: "+nrOther);


    }

}



