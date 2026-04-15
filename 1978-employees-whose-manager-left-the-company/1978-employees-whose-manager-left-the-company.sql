# Write your MySQL query statement below
SELECT e.employee_id
FROM Employees e
WHERE e.salary<30000 AND e.manager_id NOT IN (SELECT m.employee_id
                                                FROM employees m)
ORDER BY e.employee_id;