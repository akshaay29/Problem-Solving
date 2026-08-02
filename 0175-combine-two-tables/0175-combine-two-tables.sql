# Write your MySQL query statement below
select p.firstname as firstName, p.lastname as lastname, a.city as city,a.state as state
from Person as p
left join Address as a
on p.personId = a.personId