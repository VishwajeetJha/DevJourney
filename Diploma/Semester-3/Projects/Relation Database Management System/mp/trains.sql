set serveroutput ON
host cls;

DECLARE
	--select TrainID, TrainName, Arrival, Source, Departure, Destination from TrainsToFro;
	cursor trainss is select * from Trains;
	tid Trains.TrainID%TYPE;
	tname Trains.TrainName%TYPE;
	arr Trains.ArrivalTime%TYPE;
	depp Trains.DepartureTime%TYPE;
	src Trains.SourceStation%TYPE;
	dest Trains.DestinationStation%TYPE;
	f Trains.Fare%TYPE;
	avseats Trains.AvailableSeats%TYPE;
	
BEGIN
	open trainss;
	dbms_output.put_line('Train Number	Name		SourceID	Departure		Destination	Fare	Available Seats');
	
	LOOP
		fetch trainss into tid, tname, src, dest, depp, arr, avseats, f, avseats;
		exit when trainss%notfound;
		--select TrainName, Arrival, Departure, Source, Destination into tname, arr, depp, src, dest from TrainsToFro where TrainID = tid;
		dbms_output.put_line(tid||'		'||tname||'	'||src||'		'||TO_CHAR(depp, 'DD-MM-YYYY HH:MI PM')||'	'||dest||'		'||f||'	'||avseats);
		--dbms_output.put_line('Train Name: '||tname);
		--dbms_output.put_line('Depature: '||depp);
		--dbms_output.put_line('Source: '||src);
		--dbms_output.put_line('Arrival: '||arr);
		--dbms_output.put_line('Destination: '||dest);
	END LOOP;
	close trainss;
	
END;
/