create table S(
SNO    char(9),
SNAME  char(9),
STATUS int,
CITY   char(9));

insert into S(SNO,SNAME,STATUS,CITY) values('S1','����',20,'���');
insert into S(SNO,SNAME,STATUS,CITY) values('S2','ʢ��',10,'����');
insert into S(SNO,SNAME,STATUS,CITY) values('S3','������',30,'����');
insert into S(SNO,SNAME,STATUS,CITY) values('S4','��̩ʢ',20,'���');
insert into S(SNO,SNAME,STATUS,CITY) values('S5','Ϊ��',30,'�Ϻ�');

select * 
from   S

create table P(
PNO   char(9),
PNAME char(9),
COLOR char(9),
WEIGHT int);

insert into P(PNO,PNAME,COLOR,WEIGHT) values('P1','��ĸ','��',12);
insert into P(PNO,PNAME,COLOR,WEIGHT) values('P2','��˨','��',17);
insert into P(PNO,PNAME,COLOR,WEIGHT) values('P3','��˿��','��',14);
insert into P(PNO,PNAME,COLOR,WEIGHT) values('P4','��˿��','��',14);
insert into P(PNO,PNAME,COLOR,WEIGHT) values('P5','͹��','��',40);
insert into P(PNO,PNAME,COLOR,WEIGHT) values('P6','����','��',30);

select *
from P;

create table J(
JNO   char(9),
JNAME char(9),
CITY  char(9));

insert into J(JNO,JNAME,CITY) values('J1','����','����');
insert into J(JNO,JNAME,CITY) values('J2','һ��','����');
insert into J(JNO,JNAME,CITY) values('J3','���ɳ�','���');
insert into J(JNO,JNAME,CITY) values('J4','������','���');
insert into J(JNO,JNAME,CITY) values('J5','������','��ɽ');
insert into J(JNO,JNAME,CITY) values('J6','���ߵ糧','����');
insert into J(JNO,JNAME,CITY) values('J7','�뵼�峧','�Ͼ�');

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

/*��1��*/
select distinct SNO
from SPJ
where JNO='J1';
/*��2��*/
select distinct SNO
from SPJ
where JNO='J1'and PNO='P1';
/*��3��*/
select SNO
from SPJ
where JNO='J1'and PNO in (select PNO
                           from  P
						   where COLOR='��');
/*��4��*/
select distinct JNO
from   SPJ
where SNO not in (select SNO
                   from  S
				   where CITY='���'
				   and PNO in (select PNO
				               from P
							   where COLOR='��') );
   
/*��5��*/
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
	            

/*�������*/

/*��1��*/
select SNAME,CITY
from S
/*��2��*/
select PNAME,COLOR,WEIGHT
from P
/*��3��*/
select JNO
from   SPJ
where  SNO='S1';
/*��4��*/
select PNAME,QTY
from P,SPJ
where JNO='J2'
and   SPJ.PNO=P.PNO;
/*��5��*/
select PNO
from   S,SPJ
where  S.CITY='�Ϻ�'
and    S.SNO=SPJ.SNO;
/*��6��*/
select JNAME
from   S,J,SPJ
where  S.CITY='�Ϻ�'
and    S.SNO=SPJ.SNO
and    J.JNO=SPJ.JNO;
/*��7��*/
select distinct JNO
from SPJ
where JNO not in (select distinct JNO
                   from  S,SPJ
				   where CITY='���'
				   and   S.SNO=SPJ.SNO);
/*��8��*/
update P
set COLOR='��'
where COLOR='��';

select *
from P;
/*��9��*/
update SPJ
set SNO='S3'
where SNO='S5'and JNO='J4'and PNO='P6';

select *
from SPJ;
/*��10��*/
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
/*��11��*/
insert into SPJ(SNO,PNO,JNO,QTY) values('S2','J6','P4',200);
select *
from SPJ;

/*�ھŴ���*/
/*������ͼ*/
create view V_SPJ(SNO,PNO,QTY)
as
select SNO,PNO,QTY
from SPJ
/*��1С��*/
select SNO,QTY
from V_SPJ;
/*��2С��*/
select *
from V_SPJ
where SNO='S1';



