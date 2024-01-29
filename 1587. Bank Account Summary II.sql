select name,sum(amount) as balance
from users natural join transactions
group by account
having sum(amount)>10000
