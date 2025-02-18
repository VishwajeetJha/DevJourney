set serveroutput ON

CREATE OR REPLACE TRIGGER employees_last_update
BEFORE INSERT OR UPDATE ON employees
FOR EACH ROW
BEGIN
   :NEW.last_update := SYSDATE;
END;
/