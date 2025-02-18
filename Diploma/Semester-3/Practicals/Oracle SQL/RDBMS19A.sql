-- main_file.sql
set serveroutput on

-- Accept employee_id as input
accept employee_id_input number prompt 'Enter value for employee_id: ';

declare
  emp_id_input number := &employee_id_input;
begin
  -- Call the get_salary procedure
  emp_info.get_salary(emp_id_input);

  -- Call the get_job_id function
  declare
    job_id_value varchar2(50);
  begin
    job_id_value := emp_info.get_job_id(emp_id_input);
    dbms_output.put_line('Job ID returned: ' || job_id_value);
  end;
end;
/
