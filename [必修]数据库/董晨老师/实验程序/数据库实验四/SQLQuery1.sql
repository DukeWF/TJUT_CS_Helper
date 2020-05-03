select * from Student;
select * from Student where Sage>=20;

1.
dbcc dropcleanbuffers
dbcc freeproccache

set statistics io on 
set statistics time on 
go 
select * from STU where Sage>=20;
go 
set statistics io off 
set statistics time off

2.
create unique index Stusno on Student(sno);
dbcc dropcleanbuffers
dbcc freeproccache

set statistics io on 
set statistics time on 
go 
select * from Student with(index(Stusno)) where Sage=21;
go 
set statistics io off 
set statistics time off

4.
dbcc dropcleanbuffers
dbcc freeproccache

set statistics io on 
set statistics time on 
go 
select * from Student  where Sage=21;
go 
set statistics io off 
set statistics time off

create table STU(
Sno char(10),
Sname char(10),
Ssex char(2),
Sage int,
Sdept char(10) );

select * from STU;
