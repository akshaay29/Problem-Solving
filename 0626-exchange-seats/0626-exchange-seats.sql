# Write your MySQL query statement below
select
    case 
        when s.id%2!=0 and id!=(select count(*) from seat) then s.id+1
        when s.id%2=0 then s.id-1
        else id
    end as id,
    student
from Seat s
order by id;