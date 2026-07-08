#!/usr/bin/env bash
javac --module-path /opt/javafx/javafx-sdk-26/lib --add-modules javafx.controls MouseDragFX.java && java --module-path /opt/javafx/javafx-sdk-26/lib --add-modules javafx.controls --enable-native-access=javafx.graphics MouseDragFX
