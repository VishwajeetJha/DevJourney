CREATE OR REPLACE PACKAGE BODY employee_management AS
  PROCEDURE promote_employee(p_employee_id IN NUMBER, p_old_job_id IN VARCHAR2, p_new_job_id IN VARCHAR2) IS
  BEGIN
    UPDATE employees_job SET job_id = p_new_job_id WHERE employee_id = p_employee_id AND job_id = p_old_job_id;
    INSERT INTO promotion_history(employee_id, old_job_id, new_job_id, promotion_day) VALUES (p_employee_id, p_old_job_id, p_new_job_id, CURRENT_TIMESTAMP);
    COMMIT;
  END promote_employee;
END employee_management;
/
