CREATE OR REPLACE PACKAGE employee_management AS
  PROCEDURE promote_employee(p_employee_id IN NUMBER, p_old_job_id IN VARCHAR2, p_new_job_id IN VARCHAR2);
END employee_management;
/
