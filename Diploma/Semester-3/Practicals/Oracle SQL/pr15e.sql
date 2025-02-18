set serveroutput on

declare
	a number;
	b number;
	ans number;
	choice number;

begin
	a := &a;
	b := &b;
	dbms_output.put_line('1. Add');
	dbms_output.put_line('2. Subtract');
	dbms_output.put_line('3. Multiply');
	dbms_output.put_line('4. Divide');
	choice := &choice;

	if choice = 1 then
		goto add;
	elsif choice = 2 then
		goto sub;
	elsif choice = 3 then
		goto mul;
	elsif choice = 4 then
		goto div;
	else
		dbms_output.put_line('Invalid Choice!'); 
	end if;

	<<add>>
		ans := a+b;
		dbms_output.put_line('Addition of ' || a || '+' || b || ' = ' || ans);
		goto finish;
	<<sub>>
		ans := a-b;
		dbms_output.put_line('Subtraction of ' || a || '-' || b || ' = ' || ans);
		goto finish;
	<<mul>>
		ans := a*b;
		dbms_output.put_line('Multiplication of ' || a || '*' || b || ' = ' || ans);
		goto finish;
	<<div>>
		if b = 0 then
			dbms_output.put_line('Cannot Divide with 0');
			goto finish;
		else
			ans := a/b;
			dbms_output.put_line('Division of ' || a || '/' || b || ' = ' || ans);
			goto finish;
		end if;
	<<finish>>
		dbms_output.put_line('Operation Complete.');
end;
/