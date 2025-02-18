SET SERVEROUTPUT ON
host cls;

DECLARE
   PassengerName TicketPaxInfo.paxname%TYPE;
   TicketID TicketPaxInfo.tcid%TYPE;
   BookingID Bookings.BookingID%TYPE;
   SeatNumber TicketPaxInfo.seatno%TYPE;
   Age TicketPaxInfo.Age%TYPE;
   Status TicketPaxInfo.st%TYPE;
   Gender TicketPaxInfo.Gender%TYPE;

   t_id TrainsToFro.TrainID%TYPE;
   trainid TrainsToFro.TrainID%TYPE;
   tname TrainsToFro.TrainName%TYPE;
   arr TrainsToFro.Arrival%TYPE;
   depp TrainsToFro.Departure%TYPE;
   src TrainsToFro.Source%TYPE;
   dest TrainsToFro.Destination%TYPE;
   avseats Trains.AvailableSeats%TYPE;

BEGIN
	t_id := &t_id;
	select * INTO tname, trainid, src, depp, dest, arr from TrainsToFro where TrainID = t_id;
	select AvailableSeats into avseats from Trains where TrainID = t_id;
	if avseats <= 0 THEN
		RAISE_APPLICATION_ERROR(-20001, 'Sorry! No seats are currently available in the train specified!');
	else
		PassengerName:='&PassengerName';
		SeatNumber := &SeatNumber;
		Age:=&Age;
		Status := 'Booked';
		Gender := '&Gender';
		
		insert into Bookings values(bokid.NEXTVAL, trainid, 1, SYSDATE, SeatNumber, Status);
		insert into Tickets values(bokid.CURRVAL, bokid.CURRVAL, PassengerName, Age, Gender, SeatNumber);
		
		UPDATE Trains
			SET AvailableSeats = AvailableSeats - 1
			where TrainID=t_id;
			
		COMMIT;
		
		dbms_output.put_line('Booked Ticket for Train:-');
		
		dbms_output.put_line('Train Number: ' || trainid);
		dbms_output.put_line('Train Name: ' || tname);
		dbms_output.put_line('Departure: ' || depp);
		dbms_output.put_line('Source: ' || src);
		dbms_output.put_line('Arrival: ' || arr);
		dbms_output.put_line('Destination: ' || dest);
		
		dbms_output.put_line('Booking Details:-');
		dbms_output.put_line('TrainID: '||trainid);
		dbms_output.put_line('Booking Date: '||SYSDATE);
		dbms_output.put_line('Passenger Name: '||PassengerName);
		dbms_output.put_line('Status: '||Status);
		dbms_output.put_line('Seat Number: '||SeatNumber);
		dbms_output.put_line('Age: '||Age);
		dbms_output.put_line('Gender: '||Gender);
	   
	end if;
EXCEPTION
		WHEN NO_DATA_FOUND THEN
			dbms_output.put_line('Train not found!');
		WHEN OTHERS THEN
			dbms_output.put_line('Unknown Error occured!');
END;
/
