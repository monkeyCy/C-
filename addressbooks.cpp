#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#define MAX 1000		//通讯录人数上限
using namespace std;

class Person{       //联系人类
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
    Person pArray[MAX];	//联系人类数组
	int m_size;			//当前通讯录人员个数

};

//显示功能菜单
void showMenu(){
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、查找联系人  *****" << endl;
	cout << "*****  4、删除联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、排序联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;

}
// 写入
void writePerson(addressBooks *abs){
        ofstream outfile;      //对象
        outfile.open("MyAddressBooks.txt");
        //写入文件
        for(int i = 0; i < abs->m_size; i++){
        outfile << "学号：" << abs->pArray[i].m_id << '\t';
		outfile << "姓名：" << abs->pArray[i].m_name << '\t';
		outfile << "性别：" << (abs->pArray[i].m_sex == 1 ? "男" : "女") << '\t';
		outfile << "年龄：" << abs->pArray[i].m_age << '\t';
		outfile << "电话：" << abs->pArray[i].m_phone << '\t';
		outfile << "住址：" << abs->pArray[i].m_addr << '\t';
        outfile << "备注：" << abs->pArray[i].m_remark << endl;
		}
	outfile.close();
}
//1.添加联系人
void addPerson(addressBooks *abs){
	if(abs->m_size == MAX){
		cout << "通讯录已满，无法添加" << endl;
		return;
	}
	string m_id;
        string m_name;
        int m_sex;
        int m_age;
        string m_phone;
        string m_addr;
        string m_remark;
	//学号
	cout << "请输入学号：" << endl;
	cin >> abs->pArray[abs->m_size].m_id;
	//姓名
	cout << "请输入姓名：" << endl;
	cin >> abs->pArray[abs->m_size].m_name;
	//性别
	cout << "请输入性别（1男2女）" << endl;
	cin >> abs->pArray[abs->m_size].m_sex;
	//年龄
	cout << "请输入年龄" << endl;
	cin >> abs->pArray[abs->m_size].m_age;
	//联系电话
	cout << "请输入联系电话：" << endl;
	cin >> abs->pArray[abs->m_size].m_phone;
	//家庭住址
	cout << "请输入家庭住址：" << endl;
	cin >> abs->pArray[abs->m_size].m_addr;
	//备注
	cout << "请输入备注：" << endl;
	cin >> abs->pArray[abs->m_size].m_remark;
	//通讯录人数增加
	abs->m_size++;

	cout << "添加成功" << endl;
	cout << "按任意键继续" << endl;
	system("pause");	//按任意键继续
	system("cls");		//按完键后清屏
}

//2.显示联系人
void showPerson(addressBooks *abs){
	if(abs->m_size == 0){
		cout << "通讯录为空" << endl;
		return;
	}
	for(int i = 0; i < abs->m_size; i++){
        cout << "学号：" << abs->pArray[i].m_id << '\t';
		cout << "姓名：" << abs->pArray[i].m_name << '\t';
		cout << "性别：" << (abs->pArray[i].m_sex == 1 ? "男" : "女") << '\t';
		cout << "年龄：" << abs->pArray[i].m_age << '\t';
		cout << "电话：" << abs->pArray[i].m_phone << '\t';
		cout << "住址：" << abs->pArray[i].m_addr << '\t';
        cout << "备注：" << abs->pArray[i].m_remark << endl;

	}
	system("pause");	//按任意键继续
	system("cls");		//按完键后清屏
}
//判断通讯录中是否有联系人,有则返回下标，无则返回-1
int isExist(addressBooks *abs, string name){
	for(int i = 0; i < abs->m_size; i++){
		if(name == abs->pArray[i].m_name)
			return i;
	}
	return -1;
}
//3.查找联系人
void findPerson(addressBooks *abs){
	cout << "请输入您想查找的联系人的姓名" << endl;
	string name;
	cin >> name;
	int index = isExist(abs, name);
	if(index != -1){
		cout << "学号：" << abs->pArray[index].m_id << "\t";
		cout << "姓名：" << abs->pArray[index].m_name << "\t";
		cout << "性别：" << abs->pArray[index].m_sex << "\t";
		cout << "年龄：" << abs->pArray[index].m_age << "\t";
		cout << "电话：" << abs->pArray[index].m_phone << "\t";
		cout << "住址：" << abs->pArray[index].m_addr << "\t";
		cout << "备注：" << abs->pArray[index].m_remark << endl;
	}
	else
		cout << "查无此人" << endl;
	cout << "按任意键继续" << endl;
	system("pause");	//按任意键继续
	system("cls");		//按完键后清屏
}
//4.删除联系人
void deletePerson(addressBooks *abs){
	cout << "请输入您想删除的联系人的姓名" << endl;
	string name;
	cin >> name;
	int index = isExist(abs, name);
	if(index != -1){
		for(int i = index; i < abs->m_size; i++)
			abs->pArray[i] = abs->pArray[i+1];
		abs->m_size--;
		cout << "删除成功" << endl;
	}
	else
		cout << "查无此人" << endl;
	cout << "按任意键继续" << endl;
	system("pause");	//按任意键继续
	system("cls");		//按完键后清屏
}

//5.修改联系人
void revisePerson(addressBooks *abs){
	cout << "请输入您想修改的联系人的姓名" << endl;
	string name;
	cin >> name;
	int index = isExist(abs, name);
	if(index != -1){
		//学号
		cout << "请输入学号：" << endl;
		cin >> abs->pArray[index].m_id;

		//姓名
		cout << "请输入姓名：" << endl;
		cin >> abs->pArray[index].m_name;

		//性别
		cout << "请输入性别（1男2女）：" << endl;
		cin >> abs->pArray[index].m_sex;

		//年龄
		cout << "请输入年龄：" << endl;
		cin >> abs->pArray[index].m_age;

		//联系电话
		cout << "请输入联系电话：" << endl;
		cin >> abs->pArray[index].m_phone;

		//家庭住址
		cout << "请输入家庭住址：" << endl;
		cin >> abs->pArray[index].m_addr;

		//备注
		cout << "请输入备注：" << endl;
		cin >> abs->pArray[index].m_remark;

		cout << "修改成功" << endl;
	}
	else
		cout << "查无此人" << endl;
	cout << "按任意键继续" << endl;
	system("pause");	//按任意键继续
	system("cls");		//按完键后清屏
}

//联系人按学号排序
void SortPerson(addressBooks *abs){
	if(abs->m_size <= 1){
		cout << "通讯录无需排序" << endl;
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
	system("pause");	//按任意键继续
	system("cls");		//按完键后清屏
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
				addPerson(&abs);	//添加联系人
				break;
			case 2:
				showPerson(&abs);	//显示联系人
				break;
			case 3:
				findPerson(&abs);	//查找联系人
				break;
			case 4:
				deletePerson(&abs);	//删除联系人
				break;
			case 5:
				revisePerson(&abs);	//修改联系人
				break;
			case 6:
				SortPerson(&abs);	//排序联系人
				showPerson(&abs);   //排序后显示
				break;
			case 0:
				cout << "欢迎下次使用" << endl;
				cout << "按任意键继续" << endl;
				system("pause");	//按任意键继续
				system("cls");		//按完键后清屏
				return 0;
			default :
				break;
		}
		writePerson(&abs);
	}

}
