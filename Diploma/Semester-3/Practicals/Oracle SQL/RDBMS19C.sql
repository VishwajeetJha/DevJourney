SET SERVEROUTPUT ON
DECLARE
  v_employee_id NUMBER := &employee_id;
  v_old_job_id VARCHAR2(50);
  v_new_job_id VARCHAR2(50) := '&new_job_id';
BEGIN
  -- Retrieve the current job ID for the specified employee
  SELECT job_id INTO v_old_job_id
  FROM employees_job
  WHERE employee_id = v_employee_id;

  DBMS_OUTPUT.PUT_LINE('Input Parameters:');
  DBMS_OUTPUT.PUT_LINE('Employee ID: ' || v_employee_id);
  DBMS_OUTPUT.PUT_LINE('Old Job ID: ' || v_old_job_id);
  DBMS_OUTPUT.PUT_LINE('New Job ID: ' || v_new_job_id);

  -- Call the promote_employee procedure
  employee_management.promote_employee(
    p_employee_id => v_employee_id,
    p_old_job_id => v_old_job_id,
    p_new_job_id => v_new_job_id
  );
  
  DBMS_OUTPUT.PUT_LINE('Promotion successful');
END;
/
