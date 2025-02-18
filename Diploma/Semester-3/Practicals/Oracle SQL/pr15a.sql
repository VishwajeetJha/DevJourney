set serveroutput on

declare
	name varchar2 (20);
	age number (3);
	mobno number (10);
	erno number (12);
	dob date;

begin
	name := '&name';
	age := &age;
	mobno := &mobno;
	erno := &erno;
	dob := &dob;
	dbms_output.put_line('Name: ' || name);
	dbms_output.put_line('Age: ' || age);
	dbms_output.put_line('Mobile Number: ' || mobno);
	dbms_output.put_line('Enrollment Number: ' || erno);
	dbms_output.put_line('Date of Birth: ' || dob);

end;
/