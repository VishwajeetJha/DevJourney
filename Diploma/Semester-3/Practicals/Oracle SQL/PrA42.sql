set serveroutput ON

DECLARE
	negBal EXCEPTION;
	acBalNeg EXCEPTION;
	bal Account.balance%TYPE;
	acBal Account.balance%TYPE;
	an Account.ano%TYPE;
	
BEGIN
	an:=&an;
	bal:=&bal;
	IF bal < 0 THEN
		RAISE negBal;
	ELSIF acBal - bal < 0 THEN
		RAISE acBalNeg;
	ELSE
		update Account
			set balance = balance - bal
			where ano = an;
	END IF;

EXCEPTION
	WHEN negBal THEN
		dbms_output.put_line('Amount can NOT be negative!');

	WHEN acBalNeg THEN
		dbms_output.put_line('Insufficient Balance!');
END;
/