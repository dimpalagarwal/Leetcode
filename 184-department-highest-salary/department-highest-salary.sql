# Write your MySQL query statement below

select d.name as Department, e.name as Employee, e.salary from Employee as e join Department as d on d.id = e.departmentId where(departmentId, salary) in (select departmentId, max(salary) from Employee group by departmentId);