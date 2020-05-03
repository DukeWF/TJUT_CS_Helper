create database Temp
create table Student
(
 Sno char(9) primary key,
 Sname char(20)unique,
 Ssex char(2),
 Sage smallint,
 Sdept char(20)
 );
 create table Course
(
 Cno char(4) primary key,
 Cname char(40) not null,
 Cpno char(4),
 Ccredit smallint,
 foreign key (cpno) references Course(Cno)
 );
 create table SC
 (
  Sno char(9),
  Cno char(4),
  Grade smallint,
  primary key (Sno,Cno), 
  foreign key (Sno)references Student(Sno),
  foreign key (Cno)references Course(Cno)
  );
 select * from student
 select * from Course
 select * from SC
 
 select *
 from student
 where Sdept in ('Cs','Is')
 order by Sdept,Sno;
 
 select Sage
 from student
 where Sage<=all
      (select Sage 
       from Student)
       ;
 
 select Cno,Cname,Ccredit
 from Course
 where Cpno is NULL;
 