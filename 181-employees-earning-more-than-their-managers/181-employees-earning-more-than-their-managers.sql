# Write your MySQL query statement below
select employeee.name as Employee from 
Employee employeee join Employee manager on(employeee.managerId=manager.id)
where employeee.salary > manager.salary;