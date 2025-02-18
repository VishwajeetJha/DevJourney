SET SERVEROUTPUT ON
DECLARE 
    p_employee_id NUMBER;
    p_new_salary NUMBER;
BEGIN
    p_employee_id := &p_employee_id; 
    p_new_salary := &p_new_salary;
    update_salary(p_employee_id, p_new_salary);   
    DBMS_OUTPUT.PUT_LINE('Salary updated successfully for employee ID: ' || p_employee_id);
END;
/

