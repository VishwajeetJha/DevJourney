# MCP - JavaFX Attendance Management System

This project has been fully migrated from Swing UI to JavaFX.

## What changed

- Full UI migration from Swing to JavaFX (`Application`, `Stage`, `Scene`, `Dialog`, `DatePicker`, etc.)
- Removed legacy Swing scratch file (`tempCodeRunnerFile.java`)
- Improved input validation for student creation
- Replaced append-based attendance writes with deterministic full-file save
- Added attendance de-duplication by `(date, studentId, subject)`
- Improved default sorting for stable outputs and CSV consistency
- Converted user-facing date display to `dd-MM-yyyy`

## Files

- `MCP.java`: Main JavaFX application and domain logic
- `students.csv`: Student master data
- `attendance_data.csv`: Attendance records

## Run (Linux)

You need JavaFX SDK available locally.

```bash
cd "/home/vish/Documents/Coding/DevJourney/Degree/Semester-4/OOP/Project"

# Example path; adjust to your JavaFX SDK location
export PATH_TO_FX="$HOME/javafx-sdk-21.0.6/lib"

javac --module-path "$PATH_TO_FX" --add-modules javafx.controls MCP.java
java --module-path "$PATH_TO_FX" --add-modules javafx.controls MCP
```

## Notes

- CSV format for stored date remains ISO (`yyyy-MM-dd`) for data safety.
- UI date display is `dd-MM-yyyy`.
- Launch the app from this folder so CSV files resolve correctly.
