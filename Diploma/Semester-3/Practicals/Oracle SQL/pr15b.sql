set serveroutput on

declare
	pi constant number := 3.14 ;
	ans number (5,2) ;
	r number := 3;	
begin
	while (r != 8)
	loop
		ans := pi * r * r ;
		--dbms_output.put_line('Area of Circle with Radius: ' || r || ' = ' || ans);
		insert into areas values (r, ans);
		r := r+1;
	end loop;
end;
/