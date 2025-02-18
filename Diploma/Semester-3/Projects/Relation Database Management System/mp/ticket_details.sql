set serveroutput ON
host cls;

DECLARE
	TicketID number;
	tid TicketPaxInfo.tid%TYPE;
	paxname TicketPaxInfo.paxname%TYPE;
	tcid TicketPaxInfo.tcid%TYPE;
	sno TicketPaxInfo.seatno%TYPE;
	st TicketPaxInfo.st%TYPE;
	
	tname TrainsToFro.TrainName%TYPE;
	src TrainsToFro.Source%TYPE;
	dest TrainsToFro.Source%TYPE;
	depp TrainsToFro.Source%TYPE;
	
BEGIN
	TicketID := &TicketID;
	select tid, tcid, paxname, seatno, st into tid, tcid, paxname, sno, st from TicketPaxInfo where tcid = TicketID;
	select TrainName, Source, Destination, Departure into tname, src, dest, depp from TrainstoFro where TrainID=tid;
	--host cls;
	dbms_output.put_line('Train Number: '||tid);
	dbms_output.put_line('Train Name: '||tname);
	dbms_output.put_line('Ticket ID: '||tcid);
	dbms_output.put_line('Passenger Name: '||paxname);
	dbms_output.put_line('Seat Number: '||sno);
	dbms_output.put_line('Departure: '||depp);
	dbms_output.put_line('Source: '||src);
	dbms_output.put_line('Destination: '||dest);
	dbms_output.put_line('Status: '||st);
	
EXCEPTION
	WHEN NO_DATA_FOUND THEN
		dbms_output.put_line('Ticket ID not found!');
		
END;
/