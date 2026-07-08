// package PR9;

/* 

Use below command to run

run-loginfx.sh    # to compile and run LoginFormFX.java

*/

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.GridPane;
import javafx.stage.Stage;

public class LoginFormFX extends Application {
    public void start(Stage stage) {
        GridPane grid = new GridPane();

        Label userL = new Label("Username:");
        Label passL = new Label("Password:");
        TextField user = new TextField();
        PasswordField pass = new PasswordField();
        Button btn = new Button("Login");
        Label msg = new Label();

        grid.add(userL, 0, 0);
        grid.add(user, 1, 0);
        grid.add(passL, 0, 1);
        grid.add(pass, 1, 1);
        grid.add(btn, 1, 2);
        grid.add(msg, 1, 3);

        btn.setOnAction(e -> {
            if (user.getText().equals("admin") && pass.getText().equals("123"))
                msg.setText("Login Successful");
            else
                msg.setText("Invalid Credentials");
        });

        stage.setScene(new Scene(grid, 300, 200));
        stage.setTitle("Login Form");
        stage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}