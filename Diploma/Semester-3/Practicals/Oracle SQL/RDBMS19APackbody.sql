-- emp_info_body.sql
create or replace package body emp_info
is
  procedure get_salary(emp_id in number)
  is 
    salary_val number(10,2);
  begin
    select salary into salary_val from hr.employees where employee_id = emp_id;
    dbms_output.put_line('Salary of ' || emp_id || ' is ' || salary_val);
  end;

  function get_job_id(emp_id in number) return varchar2
  is
    job_id_val varchar2(50);
  begin
    select job_id into job_id_val from hr.employees where employee_id = emp_id;
    return job_id_val;
  end;
end emp_info;
/
