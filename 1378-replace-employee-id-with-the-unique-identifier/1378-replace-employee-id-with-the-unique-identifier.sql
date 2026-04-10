# Write your MySQL query statement below
SELECT EmployeeUNI.unique_id , Employees.name
FROM EMPLOYEES
LEFT JOIN EmployeeUNI on Employees.id=EmployeeUNI.id;