set serveroutput ON
host cls;

DECLARE
	--select TrainID, TrainName, Arrival, Source, Departure, Destination from TrainsToFro;
	tid TrainsToFro.TrainID%TYPE;
	tname TrainsToFro.TrainName%TYPE;
	arr TrainsToFro.Arrival%TYPE;
	depp TrainsToFro.Departure%TYPE;
	src TrainsToFro.Source%TYPE;
	dest TrainsToFro.Destination%TYPE;
	f Trains.Fare%TYPE;
	avseats Trains.AvailableSeats%TYPE;
	tseats Trains.TotalSeats%TYPE;
	
BEGIN
	tid := &tid;
	select TrainName, Arrival, Departure, Source, Destination into tname, arr, depp, src, dest from TrainsToFro where TrainID = tid;
	select Fare, AvailableSeats, TotalSeats into f, avseats, tseats from Trains where TrainID = tid;
	--host cls;
	dbms_output.put_line('Train Number: '||tid);
	dbms_output.put_line('Train Name: '||tname);
	dbms_output.put_line('Fare: '||f||' RS');
	dbms_output.put_line('Avaiable Seats: '||avseats||'/'||tseats);
	dbms_output.put_line('Depature: '||depp);
	dbms_output.put_line('Source: '||src);
	dbms_output.put_line('Arrival: '||arr);
	dbms_output.put_line('Destination: '||dest);
	
EXCEPTION
	WHEN NO_DATA_FOUND THEN
		dbms_output.put_line('Train Number not found!');
		
END;
/