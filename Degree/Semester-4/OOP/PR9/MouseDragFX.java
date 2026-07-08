// package PR9;

/* 

Use below command to run

run-mousedragfx.sh    # to compile and run MouseDragFX.java

*/

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.control.Button;
import javafx.scene.layout.Pane;
import javafx.stage.Stage;

public class MouseDragFX extends Application {
    public void start(Stage stage) {
        Label text = new Label("Drag Me");
        Label coords = new Label("(0,0)");
        Button quitButton = new Button("Quit");

        text.setLayoutX(100);
        text.setLayoutY(100);
        coords.setLayoutX(100);
        coords.setLayoutY(130);
        quitButton.setLayoutX(320);
        quitButton.setLayoutY(260);

        text.setOnMouseDragged(e -> {
            text.setLayoutX(e.getSceneX());
            text.setLayoutY(e.getSceneY());
            coords.setText("(" + (int)e.getSceneX() + "," + (int)e.getSceneY() + ")");
        });

        quitButton.setOnAction(e -> stage.close());

        Pane root = new Pane(text, coords, quitButton);
        stage.setScene(new Scene(root, 400, 300));
        stage.setTitle("Mouse Position");
        stage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}