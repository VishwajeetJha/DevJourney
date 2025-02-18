set serveroutput on

declare
	actno acct_mstr.acno%type;
	balc acct_mstr.bal%type;
	minbal constant number := 5000;

begin
	actno := '&actno';
	select bal into balc from acct_mstr where acno = actno;
	if balc <= minbal then
		dbms_output.put_line('Tum pe to hai hi 9.');
	else
		balc := balc - 100;
		update acct_mstr set bal = balc where acno = actno;
	end if;
end;
/