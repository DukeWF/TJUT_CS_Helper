create table S(
SNO    char(9),
SNAME  char(9),
STATUS int,
CITY   char(9));

insert into S(SNO,SNAME,STATUS,CITY) values('S1','精益',20,'天津');
insert into S(SNO,SNAME,STATUS,CITY) values('S2','盛锡',10,'北京');
insert into S(SNO,SNAME,STATUS,CITY) values('S3','东方红',30,'北京');
insert into S(SNO,SNAME,STATUS,CITY) values('S4','丰泰盛',20,'天津');
insert into S(SNO,SNAME,STATUS,CITY) values('S5','为民',30,'上海');

select * 
from   S

create table P(
PNO   char(9),
PNAME char(9),
COLOR char(9),
WEIGHT int);

insert into P(PNO,PNAME,COLOR,WEIGHT) values('P1','螺母','红',12);
insert into P(PNO,PNAME,COLOR,WEIGHT) values('P2','螺栓','绿',17);
insert into P(PNO,PNAME,COLOR,WEIGHT) values('P3','螺丝刀','蓝',14);
insert into P(PNO,PNAME,COLOR,WEIGHT) values('P4','螺丝刀','红',14);
insert into P(PNO,PNAME,COLOR,WEIGHT) values('P5','凸轮','蓝',40);
insert into P(PNO,PNAME,COLOR,WEIGHT) values('P6','齿轮','红',30);

select *
from P;

create table J(
JNO   char(9),
JNAME char(9),
CITY  char(9));

insert into J(JNO,JNAME,CITY) values('J1','三建','北京');
insert into J(JNO,JNAME,CITY) values('J2','一汽','长春');
insert into J(JNO,JNAME,CITY) values('J3','弹簧厂','天津');
insert into J(JNO,JNAME,CITY) values('J4','超船厂','天津');
insert into J(JNO,JNAME,CITY) values('J5','机车厂','唐山');
insert into J(JNO,JNAME,CITY) values('J6','无线电厂','常州');
insert into J(JNO,JNAME,CITY) values('J7','半导体厂','南京');

select *
from J;

create table SPJ(
SNO   char(9),
PNO   char(9),
JNO   char(9),
QTY   int);

insert into SPJ(SNO,PNO,JNO,QTY) values('S1','P1','J1',200);
insert into SPJ(SNO,PNO,JNO,QTY) values('S1','P1','J3',100);
insert into SPJ(SNO,PNO,JNO,QTY) values('S1','P1','J4',700);
insert into SPJ(SNO,PNO,JNO,QTY) values('S1','P2','J2',100);
insert into SPJ(SNO,PNO,JNO,QTY) values('S2','P3','J1',400);
insert into SPJ(SNO,PNO,JNO,QTY) values('S2','P3','J2',200);
insert into SPJ(SNO,PNO,JNO,QTY) values('S2','P3','J4',500);
insert into SPJ(SNO,PNO,JNO,QTY) values('S2','P3','J5',400);
insert into SPJ(SNO,PNO,JNO,QTY) values('S2','P5','J1',400);
insert into SPJ(SNO,PNO,JNO,QTY) values('S2','P5','J2',100);
insert into SPJ(SNO,PNO,JNO,QTY) values('S3','P1','J1',200);
insert into SPJ(SNO,PNO,JNO,QTY) values('S3','P3','J1',200);
insert into SPJ(SNO,PNO,JNO,QTY) values('S4','P5','J1',100);
insert into SPJ(SNO,PNO,JNO,QTY) values('S4','P6','J3',300);
insert into SPJ(SNO,PNO,JNO,QTY) values('S4','P6','J4',200);
insert into SPJ(SNO,PNO,JNO,QTY) values('S5','P2','J4',100);
insert into SPJ(SNO,PNO,JNO,QTY) values('S5','P3','J1',200);
insert into SPJ(SNO,PNO,JNO,QTY) values('S5','P6','J2',200);
insert into SPJ(SNO,PNO,JNO,QTY) values('S5','P6','J4',500);

select * 
from  SPJ;

/*第1题*/
select distinct SNO
from SPJ
where JNO='J1';
/*第2题*/
select distinct SNO
from SPJ
where JNO='J1'and PNO='P1';
/*第3题*/
select SNO
from SPJ
where JNO='J1'and PNO in (select PNO
                           from  P
						   where COLOR='红');
/*第4题*/
select distinct JNO
from   SPJ
where SNO not in (select SNO
                   from  S
				   where CITY='天津'
				   and PNO in (select PNO
				               from P
							   where COLOR='红') );
   
/*第5题*/
select distinct JNO
from   SPJ SPJX
where  not exists (select *
                   from   SPJ SPJY
				   where  JNO in (select distinct JNO
				               from SPJ
							   where SNO='S1')
	and not exists (select *
	                from SPJ SPJZ
					where SPJZ.PNO=SPJY.PNO
					and   SPJZ.JNO=SPJX.JNO));
	            

/*第五大题*/

/*第1题*/
select SNAME,CITY
from S
/*第2题*/
select PNAME,COLOR,WEIGHT
from P
/*第3题*/
select JNO
from   SPJ
where  SNO='S1';
/*第4题*/
select PNAME,QTY
from P,SPJ
where JNO='J2'
and   SPJ.PNO=P.PNO;
/*第5题*/
select PNO
from   S,SPJ
where  S.CITY='上海'
and    S.SNO=SPJ.SNO;
/*第6题*/
select JNAME
from   S,J,SPJ
where  S.CITY='上海'
and    S.SNO=SPJ.SNO
and    J.JNO=SPJ.JNO;
/*第7题*/
select distinct JNO
from SPJ
where JNO not in (select distinct JNO
                   from  S,SPJ
				   where CITY='天津'
				   and   S.SNO=SPJ.SNO);
/*第8题*/
update P
set COLOR='蓝'
where COLOR='红';

select *
from P;
/*第9题*/
update SPJ
set SNO='S3'
where SNO='S5'and JNO='J4'and PNO='P6';

select *
from SPJ;
/*第10题*/
select *
from S;
delete 
from S
where SNO='S2';

delete
from SPJ
where SNO='S2';

select *
from SPJ;
/*第11题*/
insert into SPJ(SNO,PNO,JNO,QTY) values('S2','J6','P4',200);
select *
from SPJ;

/*第九大题*/
/*建立视图*/
create view V_SPJ(SNO,PNO,QTY)
as
select SNO,PNO,QTY
from SPJ
/*第1小题*/
select SNO,QTY
from V_SPJ;
/*第2小题*/
select *
from V_SPJ
where SNO='S1';



