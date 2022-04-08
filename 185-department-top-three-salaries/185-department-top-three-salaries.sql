# Write your MySQL query statement below
SELECT d.name Department, a.name Employee, a.salary Salary
FROM (
    select e.*, dense_rank() over (partition by departmentId order by Salary desc) as DRank 
    from employee e
) a
join department d
ON a.departmentId = d.id
WHERE DRank <= 3;