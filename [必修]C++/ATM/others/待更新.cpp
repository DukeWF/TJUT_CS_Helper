//�����£��ļ����� ver 2.0
struct Data{
 		string ID;
		string name;
		int password;
		double money;
		int flag;
};
//�ļ������� ver 2.0 
int main(int argc, char** argv) {	
	CLS;
	char ch;
	int t=0;
	cout<<"��ѡ��"<<endl;
	cout<<"A.��¼"<<endl<<"B.ע��"<<endl<<"Q.�˳�"<<endl;
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
			cout<<"ллʹ�ã��ټ���";
			exit(1);
			break;
		}
		default:{
			
		}
	}
	return 0;
}
//�ļ��������������ļ��Ĵ���ԭ��������				
		void file_W_Data(int i, int len, int money);//��������¼д���ļ� 	
		void file_R_information();//���ļ��ж�ȡ��Ϣ��д��ṹ������ 
		void file_W_information();//�ӽṹ����������ļ���Ϣ 
		int file_R_number();//���ļ��ж�ȡ�û��˻����� 
		void file_W_register();//���ļ���������û�������ʽ��
		int set_pw();
//���캯���������ģ�����ݿ�Data�������ļ����ݶ����ڴ档 ver 2.0
		ATM(){
			n=file_R_number();
			users = new struct Data[n];
			file_R_information();		
		}
		ATM(int i){
			n=file_R_number();       // ��ȡ��Ա���� 			
			users = new struct Data[n];  //�ڶ��ж�̬�������ݿռ� 			
			file_R_information();    //���ļ������ݶ����ڴ�			
			file_W_register();        //����³�Ա
		}
void ATM::file_W_Data(int i, int len, int money){
	fstream fout("log.txt", ios::out|ios::app|ios::binary);			
	switch(i){
		case 1:
			fout<<users[len].name<<"ȡ����"<<money<<"Ԫ... \r\n";
			break; 
		case 2:
			fout<<users[len].name<<"�洢��"<<money<<"Ԫ... \r\n";
			break; 
		case 3:
			fout<<users[len].name<<"ת����"<<money<<"Ԫ... \r\n";
			break; 
		case 4:
			fout<<users[len].name<<"��ѯ�����... \r\n";
			break; 		
		case 5:
			fout<<users[len].name<<"�޸�������... \r\n";
			break; 		
	}
	fout.close(); 
}
void ATM::file_R_information(){
	fstream fin("info.dat", ios::in|ios::out|ios::binary);

	if(!fin){
		cout<<"ERROR��ϵͳ���ϣ�";
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
		cout<<"ERROR��ϵͳ���ϣ�";
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
		cout<<"ERROR��ϵͳ���ϣ�";
		exit(-1); 
	}
	cout<<"ID��";
	cin>>newUser.ID;
	for(int i=0;i<n;i++){
		if(newUser.ID == users[i].ID){
			cout<<"ERROR�����û��Ѵ���";
			exit(0);
		}
	}
	cout<<"������";
	cin>>newUser.name;
	cout<<"���룺";
	newUser.password=this->set_pw();
	newUser.money = 0;
	newUser.flag = 1;
	fapp<<"\n"<<newUser.ID<<" "<<newUser.name<<" "<<newUser.password<<" "<<newUser.money<<" "<<newUser.flag;
	fapp.close();
	cout<<"ע��ɹ�";
	exit(0);	
}
int ATM::set_pw(){
	char password[100];
	int i=0;
	do{
		char ch;
		ch=getch();
	//�жϲ��֣�ʵ���˸����������������ʾ�����λس�������
		if(ch==8){ //�˸��
			if(i!=0){	
			cout<<char(8)<<" "<<char(8);
			i--;//Ǳ��BUG��i<0������ 
			}
		}	
		else if(ch=='\r'){//���λس��� 
		}
		else{//������ʾ 
			cout<<"*";
			password[i++]=ch;
		}
	//�жϲ��ֽ���
	}while(i<6);
	//ת�����֣�ת��char*Ϊint 
	int temp=0;
	for(i=0;i<6;i++){
		temp=temp*10+(password[i]-'0');
	}
	//ת�����ֽ���
	cout<<endl;
	system("pause");
	return temp;
}
