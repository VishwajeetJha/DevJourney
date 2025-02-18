CREATE OR REPLACE PACKAGE TrainBookingPackage AS
    -- Function to display train info based on the provided train number
    FUNCTION ShowTrainInfo(p_train_number NUMBER) RETURN VARCHAR2;

    -- Function to handle the booking process
    FUNCTION BookTicket(
        p_train_number NUMBER,
        p_user_id NUMBER,
        p_passenger_name VARCHAR2,
        p_age NUMBER,
        p_gender VARCHAR2
    ) RETURN VARCHAR2;

    -- Function to display available seats for a given train
    FUNCTION DisplayAvailableSeats(p_train_number NUMBER) RETURN NUMBER;
END TrainBookingPackage;
/

CREATE OR REPLACE PACKAGE BODY TrainBookingPackage AS
    -- Function to display train info based on the provided train number
    FUNCTION ShowTrainInfo(p_train_number NUMBER) RETURN VARCHAR2 IS
        v_info VARCHAR2(4000);
    BEGIN
        FOR train_info IN (SELECT * FROM Trains WHERE TrainID = p_train_number) LOOP
            v_info := 'Train ID: ' || train_info.TrainID || chr(10) ||
                      'Train Name: ' || train_info.TrainName || chr(10) ||
                      'Source Station: ' || train_info.SourceStation || chr(10) ||
                      'Destination Station: ' || train_info.DestinationStation || chr(10) ||
                      'Departure Time: ' || TO_CHAR(train_info.DepartureTime, 'DD-MON-YY HH24:MI PM') || chr(10) ||
                      'Arrival Time: ' || TO_CHAR(train_info.ArrivalTime, 'DD-MON-YY HH24:MI PM') || chr(10) ||
                      'Available Seats: ' || train_info.AvailableSeats;
        END LOOP;
        RETURN v_info;
    END ShowTrainInfo;

    -- Function to handle the booking process
    FUNCTION BookTicket(
        p_train_number NUMBER,
        p_user_id NUMBER,
        p_passenger_name VARCHAR2,
        p_age NUMBER,
        p_gender VARCHAR2
    ) RETURN VARCHAR2 IS
		p_ticket_id INT;
        v_booking_id NUMBER;
        v_seat_number NUMBER;
        v_result VARCHAR2(200);
    BEGIN
        -- Assuming you have a sequence for generating unique booking IDs named "bokid"
		SELECT bokid.NEXTVAL INTO v_booking_id FROM dual;
		SELECT bokid.NEXTVAL INTO p_ticket_id FROM dual;

        -- Assuming you have a sequence for generating unique seat numbers named "seat_seq"
        SELECT bokid.CURRVAL INTO v_seat_number FROM dual;

        -- Insert into TicketHistory table
        INSERT INTO Bookings
        VALUES (v_ticket_id, p_train_number, 1, SYSDATE, v_seat_number, 'Booked');
		
		INSERT INTO Tickets
		VALUES (v_ticket_id, v_ticket_id, p_passenger_name, p_age, p_gender, v_seat_number);

        -- Update AvailableSeats in Trains table
        UPDATE Trains
        SET AvailableSeats = AvailableSeats - 1
        WHERE TrainID = p_train_number;

        v_result := 'Ticket booked successfully! Your Booking ID is ' || v_booking_id ||
                     ', Seat Number is ' || v_seat_number;
        RETURN v_result || ',' || TO_CHAR(v_booking_id) || ',' || TO_CHAR(v_seat_number); -- Return result, booking ID, and seat number
    END BookTicket;

    -- Function to display available seats for a given train
    FUNCTION DisplayAvailableSeats(p_train_number NUMBER) RETURN NUMBER IS
        v_available_seats NUMBER;
    BEGIN
        SELECT AvailableSeats INTO v_available_seats
        FROM Trains
        WHERE TrainID = p_train_number;

        RETURN v_available_seats;
    END DisplayAvailableSeats;
END TrainBookingPackage;
/
