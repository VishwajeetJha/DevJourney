-- emp_info_spec.sql
create or replace package emp_info
is
  procedure get_salary(emp_id in number);
  function get_job_id(emp_id in number) return varchar2;
end emp_info;
/
