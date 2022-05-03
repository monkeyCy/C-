#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#define MAX 1000		//ͨѶ¼��������
using namespace std;

class Person{       //��ϵ����
    public:

        string m_id;
        string m_name;
        int m_sex;
        int m_age;
        string m_phone;
        string m_addr;
        string m_remark;
};


class addressBooks{
    public:
    Person pArray[MAX];	//��ϵ��������
	int m_size;			//��ǰͨѶ¼��Ա����

};

//��ʾ���ܲ˵�
void showMenu(){
	cout << "***************************" << endl;
	cout << "*****  1�������ϵ��  *****" << endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��������ϵ��  *****" << endl;
	cout << "*****  4��ɾ����ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6��������ϵ��  *****" << endl;
	cout << "*****  0���˳�ͨѶ¼  *****" << endl;
	cout << "***************************" << endl;

}
// д��
void writePerson(addressBooks *abs){
        ofstream outfile;      //����
        outfile.open("MyAddressBooks.txt");
        //д���ļ�
        for(int i = 0; i < abs->m_size; i++){
        outfile << "ѧ�ţ�" << abs->pArray[i].m_id << '\t';
		outfile << "������" << abs->pArray[i].m_name << '\t';
		outfile << "�Ա�" << (abs->pArray[i].m_sex == 1 ? "��" : "Ů") << '\t';
		outfile << "���䣺" << abs->pArray[i].m_age << '\t';
		outfile << "�绰��" << abs->pArray[i].m_phone << '\t';
		outfile << "סַ��" << abs->pArray[i].m_addr << '\t';
        outfile << "��ע��" << abs->pArray[i].m_remark << endl;
		}
	outfile.close();
}
//1.�����ϵ��
void addPerson(addressBooks *abs){
	if(abs->m_size == MAX){
		cout << "ͨѶ¼�������޷����" << endl;
		return;
	}
	string m_id;
        string m_name;
        int m_sex;
        int m_age;
        string m_phone;
        string m_addr;
        string m_remark;
	//ѧ��
	cout << "������ѧ�ţ�" << endl;
	cin >> abs->pArray[abs->m_size].m_id;
	//����
	cout << "������������" << endl;
	cin >> abs->pArray[abs->m_size].m_name;
	//�Ա�
	cout << "�������Ա�1��2Ů��" << endl;
	cin >> abs->pArray[abs->m_size].m_sex;
	//����
	cout << "����������" << endl;
	cin >> abs->pArray[abs->m_size].m_age;
	//��ϵ�绰
	cout << "��������ϵ�绰��" << endl;
	cin >> abs->pArray[abs->m_size].m_phone;
	//��ͥסַ
	cout << "�������ͥסַ��" << endl;
	cin >> abs->pArray[abs->m_size].m_addr;
	//��ע
	cout << "�����뱸ע��" << endl;
	cin >> abs->pArray[abs->m_size].m_remark;
	//ͨѶ¼��������
	abs->m_size++;

	cout << "��ӳɹ�" << endl;
	cout << "�����������" << endl;
	system("pause");	//�����������
	system("cls");		//�����������
}

//2.��ʾ��ϵ��
void showPerson(addressBooks *abs){
	if(abs->m_size == 0){
		cout << "ͨѶ¼Ϊ��" << endl;
		return;
	}
	for(int i = 0; i < abs->m_size; i++){
        cout << "ѧ�ţ�" << abs->pArray[i].m_id << '\t';
		cout << "������" << abs->pArray[i].m_name << '\t';
		cout << "�Ա�" << (abs->pArray[i].m_sex == 1 ? "��" : "Ů") << '\t';
		cout << "���䣺" << abs->pArray[i].m_age << '\t';
		cout << "�绰��" << abs->pArray[i].m_phone << '\t';
		cout << "סַ��" << abs->pArray[i].m_addr << '\t';
        cout << "��ע��" << abs->pArray[i].m_remark << endl;

	}
	system("pause");	//�����������
	system("cls");		//�����������
}
//�ж�ͨѶ¼���Ƿ�����ϵ��,���򷵻��±꣬���򷵻�-1
int isExist(addressBooks *abs, string name){
	for(int i = 0; i < abs->m_size; i++){
		if(name == abs->pArray[i].m_name)
			return i;
	}
	return -1;
}
//3.������ϵ��
void findPerson(addressBooks *abs){
	cout << "������������ҵ���ϵ�˵�����" << endl;
	string name;
	cin >> name;
	int index = isExist(abs, name);
	if(index != -1){
		cout << "ѧ�ţ�" << abs->pArray[index].m_id << "\t";
		cout << "������" << abs->pArray[index].m_name << "\t";
		cout << "�Ա�" << abs->pArray[index].m_sex << "\t";
		cout << "���䣺" << abs->pArray[index].m_age << "\t";
		cout << "�绰��" << abs->pArray[index].m_phone << "\t";
		cout << "סַ��" << abs->pArray[index].m_addr << "\t";
		cout << "��ע��" << abs->pArray[index].m_remark << endl;
	}
	else
		cout << "���޴���" << endl;
	cout << "�����������" << endl;
	system("pause");	//�����������
	system("cls");		//�����������
}
//4.ɾ����ϵ��
void deletePerson(addressBooks *abs){
	cout << "����������ɾ������ϵ�˵�����" << endl;
	string name;
	cin >> name;
	int index = isExist(abs, name);
	if(index != -1){
		for(int i = index; i < abs->m_size; i++)
			abs->pArray[i] = abs->pArray[i+1];
		abs->m_size--;
		cout << "ɾ���ɹ�" << endl;
	}
	else
		cout << "���޴���" << endl;
	cout << "�����������" << endl;
	system("pause");	//�����������
	system("cls");		//�����������
}

//5.�޸���ϵ��
void revisePerson(addressBooks *abs){
	cout << "�����������޸ĵ���ϵ�˵�����" << endl;
	string name;
	cin >> name;
	int index = isExist(abs, name);
	if(index != -1){
		//ѧ��
		cout << "������ѧ�ţ�" << endl;
		cin >> abs->pArray[index].m_id;

		//����
		cout << "������������" << endl;
		cin >> abs->pArray[index].m_name;

		//�Ա�
		cout << "�������Ա�1��2Ů����" << endl;
		cin >> abs->pArray[index].m_sex;

		//����
		cout << "���������䣺" << endl;
		cin >> abs->pArray[index].m_age;

		//��ϵ�绰
		cout << "��������ϵ�绰��" << endl;
		cin >> abs->pArray[index].m_phone;

		//��ͥסַ
		cout << "�������ͥסַ��" << endl;
		cin >> abs->pArray[index].m_addr;

		//��ע
		cout << "�����뱸ע��" << endl;
		cin >> abs->pArray[index].m_remark;

		cout << "�޸ĳɹ�" << endl;
	}
	else
		cout << "���޴���" << endl;
	cout << "�����������" << endl;
	system("pause");	//�����������
	system("cls");		//�����������
}

//��ϵ�˰�ѧ������
void SortPerson(addressBooks *abs){
	if(abs->m_size <= 1){
		cout << "ͨѶ¼��������" << endl;
		return;
	}
	Person temp;
	for(int i = 0;i < abs->m_size;i++){
        for(int j = 0; j < abs->m_size - i - 1;j++ ){
            if(abs->pArray[j].m_id > abs->pArray[j+1].m_id){
                temp = abs->pArray[j+1];
                abs->pArray[j+1] =abs->pArray[j];
                abs->pArray[j] = temp;
            }
        }
	}
	system("pause");	//�����������
	system("cls");		//�����������
}
int main(){
	addressBooks abs;
	abs.m_size = 0;
	int select;
	while(true){
		showMenu();
		cin >> select;
		switch(select){
			case 1:
				addPerson(&abs);	//�����ϵ��
				break;
			case 2:
				showPerson(&abs);	//��ʾ��ϵ��
				break;
			case 3:
				findPerson(&abs);	//������ϵ��
				break;
			case 4:
				deletePerson(&abs);	//ɾ����ϵ��
				break;
			case 5:
				revisePerson(&abs);	//�޸���ϵ��
				break;
			case 6:
				SortPerson(&abs);	//������ϵ��
				showPerson(&abs);   //�������ʾ
				break;
			case 0:
				cout << "��ӭ�´�ʹ��" << endl;
				cout << "�����������" << endl;
				system("pause");	//�����������
				system("cls");		//�����������
				return 0;
			default :
				break;
		}
		writePerson(&abs);
	}

}
