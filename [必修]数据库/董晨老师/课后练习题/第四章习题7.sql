create table Employee(
Eno int,
Ename char(10),
Eage int,
Ework char(10),
Esalary int,
Edep int);

insert into Employee values(1,'����',23,'����Ա','5000',1);
insert into Employee values(2,'����',30,'��Ŀ����','10000',2);

select *
from Employee;

create table Department(
Dno int,
Dname char(20),
Mname char(10),
Dadr  char(20),
Dnum  char(20));

insert into Department values(1,'��Ŀ��','����','����','13072293571');
insert into Department values(2,'����','����','�Ͽ�','18888888888');

select *
from Department;

create login Wang
with password='wang',
default_database=exercise4;

create user Wang
for login Wang;

grant select 
on Employee
to Wang;

grant select 
on Department
to Wang;

create login Li
with password='li',
default_database=exercise4;

create user Li
for login Li;

grant insert,delete
on Employee
to Li;

grant insert,delete
on Department
to Li;

grant select 
on Employee  
when user()=Ename to ALL;

4.
create login Liu
with password='liu',
default_database=exercise4;

create user Liu
for login Liu;

grant select,update(Esalary)
on Employee
to Liu;

5.
create login Zhang
with password='zhang',
default_database=exercise4;

create user Zhang
for login Zhang;

grant alter,select
on Employee
to Zhang;

grant alter,select
on Department
to Zhang;

6.
create login Zhou
with password='zhou',
default_database=exercise4;

create user Zhou
for login Zhou;

grant all privileges
on Employee
to Zhou
with grant option;

grant all privileges
on Department
to Zhou
with grant option;

7.
create login Yang
with password = 'yang',
default_database = exercise4

create user Yang 
for login Yang

create view Salary
as
select max(Esalary) as Max,min(Esalary) as Min,avg(Esalary) as Avg
from Employee,Department
where Employee.Eno = Department.Dno
group by Department.dno,Dname;

grant select on Salary to Yang

