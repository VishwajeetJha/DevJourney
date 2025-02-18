CREATE OR REPLACE TRIGGER prevent_salary_change
BEFORE UPDATE OF salary ON hr.employees
FOR EACH ROW
DECLARE
  v_job_id employees.job_id%TYPE;
BEGIN
  SELECT job_id INTO v_job_id FROM hr.employees WHERE employee_id = :OLD.employee_id;
  IF v_job_id LIKE '%_PRES' THEN
    RAISE_APPLICATION_ERROR(-20001, 'Cannot change the salary of the President');
  END IF;
END;
/
