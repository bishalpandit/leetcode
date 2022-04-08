# Write your MySQL query statement below
SELECT d.name Department, e.name Employee, e.salary Salary
FROM Employee e
JOIN Department d
ON e.departmentId = d.id
WHERE 3 > (
    SELECT COUNT(DISTINCT Salary)
    FROM Employee
    WHERE Salary > e.Salary
    AND departmentId = d.id
);