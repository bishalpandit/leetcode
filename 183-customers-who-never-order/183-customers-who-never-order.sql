# Write your MySQL query statement below
select name Customers
from customers c
left join orders o
on c.id = o.customerId
where o.customerId IS NULL;