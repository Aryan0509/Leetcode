# select cust.name from customer cust join customer cu on(cust.referee_id <> cu.id)
# where cu.id=2;

select name from customer where referee_id <> 2 or referee_id is null;