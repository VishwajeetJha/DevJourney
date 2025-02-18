set serveroutput ON

CREATE OR REPLACE TRIGGER salary_grade
AFTER UPDATE OF salary ON empl
FOR EACH ROW
DECLARE
	e_salary empl.salary%TYPE;
BEGIN
	SELECT salary INTO e_salary FROM empl WHERE employee_id = :NEW.employee_id;
	IF e_salary > 20000 THEN
		update empl
			set salary_grade = 'A'
			where employee_id = :NEW.employee_id;
			
	ELSIF	e_salary > 12000 THEN
		update empl
			set salary_grade = 'B'
			where employee_id = :NEW.employee_id;
			
	ELSIF	e_salary > 8000 THEN
		update empl
			set salary_grade = 'C'
			where employee_id = :NEW.employee_id;
			
	ELSIF	e_salary > 3000 THEN
		update empl
			set salary_grade = 'D'
			where employee_id = :NEW.employee_id;
		
    ELSIF	e_salary < 3000 THEN
		update empl
			set salary_grade = 'L'
			where employee_id = :NEW.employee_id;
	END IF;
END;
/
