//待更新；文件操作 ver 2.0
struct Data{
 		string ID;
		string name;
		int password;
		double money;
		int flag;
};
//文件操作版 ver 2.0 
int main(int argc, char** argv) {	
	CLS;
	char ch;
	int t=0;
	cout<<"请选择："<<endl;
	cout<<"A.登录"<<endl<<"B.注册"<<endl<<"Q.退出"<<endl;
	ch=getch();
	switch(ch){
		case 'A':{
			ATM atm;
			PAUSE;
			break;
		}
		case 'B':{
			ATM atm(1);
			break;
		}
		case 'Q':{
			cout<<"谢谢使用，再见！";
			exit(1);
			break;
		}
		default:{
			
		}
	}
	return 0;
}
//文件操作函数：对文件的处理（原型声明）				
		void file_W_Data(int i, int len, int money);//将操作记录写入文件 	
		void file_R_information();//从文件中读取信息并写入结构体数组 
		void file_W_information();//从结构体数组更新文件信息 
		int file_R_number();//从文件中读取用户账户个数 
		void file_W_register();//向文件中添加新用户（交互式）
		int set_pw();
//构造函数：构造出模拟数据库Data，并将文件内容读入内存。 ver 2.0
		ATM(){
			n=file_R_number();
			users = new struct Data[n];
			file_R_information();		
		}
		ATM(int i){
			n=file_R_number();       // 获取成员数量 			
			users = new struct Data[n];  //在堆中动态创建数据空间 			
			file_R_information();    //将文件中数据读入内存			
			file_W_register();        //添加新成员
		}
void ATM::file_W_Data(int i, int len, int money){
	fstream fout("log.txt", ios::out|ios::app|ios::binary);			
	switch(i){
		case 1:
			fout<<users[len].name<<"取出了"<<money<<"元... \r\n";
			break; 
		case 2:
			fout<<users[len].name<<"存储了"<<money<<"元... \r\n";
			break; 
		case 3:
			fout<<users[len].name<<"转出了"<<money<<"元... \r\n";
			break; 
		case 4:
			fout<<users[len].name<<"查询了余额... \r\n";
			break; 		
		case 5:
			fout<<users[len].name<<"修改了密码... \r\n";
			break; 		
	}
	fout.close(); 
}
void ATM::file_R_information(){
	fstream fin("info.dat", ios::in|ios::out|ios::binary);

	if(!fin){
		cout<<"ERROR：系统故障！";
		exit(-1); 
	}

	for(int i = 0; i < n; i++){
		fin>>users[i].ID>>users[i].name>>users[i].password>>users[i].money>>users[i].flag;
	}
	
	fin.close();
}
void ATM::file_W_information(){
	fstream fout("info.dat", ios::out|ios::in|ios::binary);
			
	if(!fout){
		cout<<"ERROR：系统故障！";
		exit(-1); 
	}
			
	for(int i = 0; i < n; i++){
		fout<<users[i].ID<<" "<<users[i].name<<" "<<users[i].password<<" "<<users[i].money<<" "<<users[i].flag<<endl;
	}
			
	fout.close();		
}
int ATM::file_R_number(){
	char c;
	int line=0;
	fstream fin("info.dat",ios::in);
	if(!fin){
		return -1;
	}
	while(fin.get(c)){
		if(c=='\n'){
			line++;
		}
	}
	cout<<"line:"<<line;
	return line;
}
void ATM::file_W_register(){
	struct Data newUser;
	fstream fapp("info.dat", ios::app|ios::out|ios::binary);			
	if(!fapp){
		cout<<"ERROR：系统故障！";
		exit(-1); 
	}
	cout<<"ID：";
	cin>>newUser.ID;
	for(int i=0;i<n;i++){
		if(newUser.ID == users[i].ID){
			cout<<"ERROR：此用户已存在";
			exit(0);
		}
	}
	cout<<"姓名：";
	cin>>newUser.name;
	cout<<"密码：";
	newUser.password=this->set_pw();
	newUser.money = 0;
	newUser.flag = 1;
	fapp<<"\n"<<newUser.ID<<" "<<newUser.name<<" "<<newUser.password<<" "<<newUser.money<<" "<<newUser.flag;
	fapp.close();
	cout<<"注册成功";
	exit(0);	
}
int ATM::set_pw(){
	char password[100];
	int i=0;
	do{
		char ch;
		ch=getch();
	//判断部分：实现退格重新输出，密文显示与屏蔽回车键功能
		if(ch==8){ //退格键
			if(i!=0){	
			cout<<char(8)<<" "<<char(8);
			i--;//潜在BUG？i<0存在吗？ 
			}
		}	
		else if(ch=='\r'){//屏蔽回车键 
		}
		else{//密文显示 
			cout<<"*";
			password[i++]=ch;
		}
	//判断部分结束
	}while(i<6);
	//转换部分：转换char*为int 
	int temp=0;
	for(i=0;i<6;i++){
		temp=temp*10+(password[i]-'0');
	}
	//转换部分结束
	cout<<endl;
	system("pause");
	return temp;
}
