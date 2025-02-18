set serveroutput ON

DECLARE
	a number;
	b number;
	c number;
	
BEGIN
	a:=&a;
	b:=&b;
	c:=&c;
	
	IF a > b THEN
		IF a > c THEN
			dbms_output.put_line(a||' is greatest!');
		ELSE
			dbms_output.put_line(c||' is greatest!');
		END IF;
	ELSE
		dbms_output.put_line(b||' is greatest!');
	END IF;
END;
/