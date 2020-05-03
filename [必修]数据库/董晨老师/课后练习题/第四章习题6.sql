create table Student(
Sno char(10),
Sname char(10),
Sage int,
Ssex char(2),
Saddress char(20),
Sclass smallint);

select *
from Student;

insert into Student(Sno,Sname,Sage,Ssex,Saddress,Sclass)
values('20152178','任毅',21,'男','贵州省铜仁市',1);

create table Class(
Cno int,
Cname char(20),
Cteacher char(10),
Cmonitor char(10));

select *
from Class;

insert into Class(Cno,Cname,Cteacher,Cmonitor) values(1,'计算机一班','刘里','王海涛');

create login U1
with password='1234',
default_database=exercise4;

create user U1
for login U1;

create login U2
with password='5678',
default_database=exercise4;

create user U2
for login U2;

grant all privileges
on Student 
to U1,U2
with grant option;

grant all privileges
on Student 
to U1,U2
with grant option;

create login u2
with password='567',
default_database=exercise4;

create user u2
for login u2;

grant update(Saddress),select
on  Student 
to U2;

create login U3
with password='56',
default_database=exercise4;

create user U3
for login U3;

grant select
on Class
to U1,U3;

create role R1;

grant select,update
on Student
to R1;

grant R1
to U1
with grant option;   /*运行不了*/

exec sp_addrolemember 'R1','U1' 

