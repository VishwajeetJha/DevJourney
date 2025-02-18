set serveroutput ON
host cls;

DECLARE
	cursor ticks is select * from TicketPaxInfo;
	tid TicketPaxInfo.tid%TYPE;
	paxname TicketPaxInfo.paxname%TYPE;
	tcid TicketPaxInfo.tcid%TYPE;
	sno TicketPaxInfo.seatno%TYPE;
	age TicketPaxInfo.Age%TYPE;
	st TicketPaxInfo.st%TYPE;
	gender TicketPaxInfo.Gender%TYPE;
	
BEGIN
	open ticks;
	dbms_output.put_line('Train Number	TicketID	Passenger Name	Seat No.	Status	Age	Gender');

	LOOP
		fetch ticks into tid, tcid, paxname, sno, st, age, gender;
		exit when ticks%notfound;
		--select TrainName, Arrival, Departure, Source, Destination into tname, arr, depp, src, dest from TrainsToFro where TrainID = tid;
		dbms_output.put_line(tid||'		'||tcid||'		'||paxname||'	'||sno||'		'||st||'	'||age||'	'||gender);

	END LOOP;
	close ticks;
	
END;
/