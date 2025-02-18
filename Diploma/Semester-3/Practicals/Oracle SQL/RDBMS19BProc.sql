CREATE OR REPLACE PROCEDURE update_salary(
    p_employee_id IN NUMBER,
    p_new_salary IN NUMBER
) IS
    v_old_salary NUMBER;
BEGIN
    -- Get the current salary before the update
    SELECT salary INTO v_old_salary
    FROM empl
    WHERE employee_id = p_employee_id;

    -- Update the salary in the empl table
    UPDATE empl
    SET salary = p_new_salary
    WHERE employee_id = p_employee_id;

    -- Log the update in the salary_history table
    INSERT INTO salary_history (emp_id, old_salary, new_salary, update_time)
    VALUES (p_employee_id, v_old_salary, p_new_salary, CURRENT_TIMESTAMP);

    COMMIT;
END;
/
