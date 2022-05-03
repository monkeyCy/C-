#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <conio.h>
using namespace std;

//********书籍类，用于存放书籍基本信息********
class Book
{

private:
    char bnum[20];        //书号
    char bname[20];       //书名
	char bauthor[10];      //作者
	char rname[10];        //借阅人
	char bdays[10];        //借出日期
	char bchao[10];        //超期天数

public:
	Book()                //构造函数初始化信息
	{	strcpy(bnum,"");
		strcpy(bname,"");
		strcpy(bauthor,"");
		strcpy(rname,"");
		strcpy(bdays,"");
	    strcpy(bchao,"");

	}

      void set_bnum(char *no)     //设置书号
	  {strcpy(bnum,no);}          //把字符串no中的字符复制到字符串bnum中
      char *get_bnum()            //获得书号
	  {   return bnum;}           //返回值为bnum

      void set_bname(char *n)     //设置书名
	  {strcpy(bname,n);}
      char *get_bname()           //获得书名
	  {return bname;}

      void set_bauthor(char *a)   //设置作者
	  {strcpy(bauthor,a);}
      char *get_bauthor()        //获得作者姓名
	  {return bauthor;}


      void set_bdays(char *d)     //设置借出日期
	  {strcpy(bdays,d);}
      char *get_bdays()          //获得借出日期
	  {return bdays;}

	  void set_bchao(char *c)     //设置超出天数
	  {strcpy(bchao,c);}
      char *get_bchao()          //获得超出天数
	  {return bchao;}


      void set_rname(char *rn)    //设置借阅人
	  {strcpy(rname,rn);}
      char *get_rname()           //获得借阅人姓名
	  {return rname;}


	  void copy(Book m)           //Book类内的copy函数
	  {

		  strcpy(bnum,m.get_bnum());   //将获得书号函数里的返回值里的字符复制到bnum
		  strcpy(bname,m.get_bname());
		  strcpy(bauthor,m.get_bauthor());
		  strcpy(rname,m.get_rname());
		  strcpy(bdays,m.get_bdays());
		  strcpy(bchao,m.get_bchao());

    }
};




//**********书籍管理类,实现管理书籍功能**********
class BookManage
{



public:
    Book books[100];      //定义Book书籍类数组对象，最大容量100本
	int length;



    int add(Book book)    //添加图书资料/////////////
    {
		if(length>=100)
		{
            cout<<"对不起，储存已满，您无法继续添加！\n";
            return -1;
		}
        else
		{
            books[length].copy(book);  //调用书籍结构体copy函数
            length++;
            return (length-1);
		}
	}

	int  bnu_search(char *bnu)   //按书号查找书籍
    {
        for(int i=0;i<length;i++){                      //字符串比较，判断是否相等
            if(strcmp(books[i].get_bnum(),bnu)==0){
                 return i;
            }
        }

        return -1;
    }

	int bna_search(char *bna)   //按书名查找书籍
    {
        for(int i=0;i<length;i++)
        if(strcmp(books[i].get_bname(),bna)==0) //判断
        return i;
        return -1;
    }

	int  bau_search(char *bau)  //按作者查找书籍
    {
        for(int i=0;i<length;i++)
        if(strcmp(books[i].get_bauthor(),bau)==0)//判断
        return i;
         return -1;
    }

	int  rn_search(char *rn)  //按借阅人查找书籍
    {
        for(int i=0;i<length;i++)
        if(strcmp(books[i].get_rname(),rn)==0)//判断
        return i;
         return -1;
    }

	int  bd_search(char *bd)  //按借出日期查找书籍
    {
        for(int i=0;i<length;i++)
        if(strcmp(books[i].get_bdays(),bd)==0)//判断
		 return i;
         return -1;
    }

	int  bc_search(char *bc)  //按超期天数查找书籍
    {

        for(int i=0;i<length;i++)
		if(strcmp(books[i].get_bchao(),bc)==0)//判断
			return  i;
			return -1;
    }


	void revise(Book book,int i) //修改书籍函数
    {
		books[i].copy(book);
	}       //调用Book结构体copy函数

	void  deleteBook(int index)  //删除书籍资料函数
    {
        for(int i=index;i<length-1;i++)
		books[i].copy(books[i+1]);//用后面的地址将当前的地址覆盖
        length--;
    }

	void show_bookhead() //显示输出列表,表头。
	{
		cout<<" **********************书****籍****信****息****列****表**********************\n\n";
       cout<<"书号";
       cout.width(15);
       cout<<"书名";
       cout.width(15);
       cout<<"作者";
       cout.width(15);
        cout<<"借阅人";
		cout.width(15);
        cout<<"借出日期";
		cout.width(15);
        cout<<"超期天数\n";
	}

	void sort_book(Book *book){    //排序按书号
        if(length <= 1){
            cout << "无需排序" << endl;
            return;
        }
        Book temp;
        int ret = 0;    //接收返回值
        for(int i = 0;i < length;i++){
            for(int j = 0; j < length - i - 1;j++ ){
                if(ret <=  strcmp(books[j].get_bnum() , books[j+1].get_bnum())){
                    temp = books[j+1];
                    books[j+1] =books[j];
                    books[j] = temp;
                }
            }
        }
	system("pause");	//按任意键继续
	system("cls");		//按完键后清屏

	}

	void show_book(int i)//显示书籍函数
    {
       cout<<books[i].get_bnum();
       cout.width(15);
       cout<<books[i].get_bname();
       cout.width(15);
       cout<<books[i].get_bauthor();
       cout.width(15);
       cout<<books[i].get_rname();
	   cout.width(15);
       cout<<books[i].get_bdays();
	   cout.width(15);
       cout<<books[i].get_bchao()<<"\n";
   }
    void writePerson(Book *book){  //写入到文件
        ofstream outfile;      //对象
        outfile.open("书籍信息.txt");
        //写入文件
        for(int i = 0; i <length ; i++){
        outfile << "书号：" << books[i].get_bnum() << '\t';
		outfile << "书名：" << books[i].get_bname() << '\t';
		outfile << "作者：" << books[i].get_bauthor() << '\t';
		outfile << "借阅人：" << books[i].get_rname() << '\t';
		outfile << "借出日期：" <<  books[i].get_bdays()<< '\t';
		outfile << "超期天数：" << books[i].get_bchao() << endl;
		}
	outfile.close();
}
	void readFile()      //读取书籍文件
	{

	struct books
	{

		 char numb[10];   //书号
		 char nameb[20];   //书名
		 char authorb[10]; //作者
		 char namer[10];        //借阅人
		 char daysb[10];        //借出日期
   		 char chaob[10];        //超期天数
	};

		Book book;       //书籍结构体对象book
		books form[100];
		FILE *fp;

		if (NULL==(fp=fopen("图书数据库.txt","r")))
		{
			printf("file not open!\n");
			exit(0);
		}

		fseek(fp,40,SEEK_SET); //跳开表头40字节
		for(int i=0;i<5;i++)
		{

			fscanf(fp, "%s", &form[i].numb);
			fscanf(fp, "%s", &form[i].nameb);
			fscanf(fp, "%s", &form[i].authorb);
			fscanf(fp, "%s", &form[i].namer);
			fscanf(fp, "%s", &form[i].daysb);
			fscanf(fp, "%s", &form[i].chaob);
			book.set_bnum(form[i].numb);
			book.set_bname(form[i].nameb);
			book.set_bauthor(form[i].authorb);
			book.set_rname(form[i].namer);
			book.set_bdays(form[i].daysb);
			book.set_bchao(form[i].chaob);
			BookManage::add(book);
			fflush(stdin);
		}

			fclose(fp);
		}
};




//**********菜单类,实现界面引导**********
class Menu
{

	BookManage bm;     //定义书籍管理类的对象bm

private:
	char choice;        //菜单序号选择
    int key;           //管理员密码

public:

	int check(int m)    //检查语句
{

	return  m;
}



	void header()      //首页欢迎界面
	{

		cout<<"\t   口口口口口口口口口口口口口口口口口口口口口口口口口口口口\n";
		cout<<"\t   口                                                    口\n";
		cout<<"\t   口                                                    口\n";
		cout<<"\t   口====================================================口\n";
		cout<<"\t   口        图   书   借   阅   管   理   系   统  1.0  口\n";
		cout<<"\t   口                                                    口\n";
		cout<<"\t   口口口口口口口口口口口口口口口口口口口口口口口口口口口口\n";
		_sleep(200);
	}


	void log_menu()      //主界面登录菜单
	{

		header();

		cout<<"\n\t\t\t< 请  选  择  是  否  进  入 >\n";
		cout<<"\n\t\t\t\t1: 进 入 系 统\n\n\t\t\t\t0: 退  出\n\t您的选择是： ";
		choice: cin>>choice;
		cin.ignore();    //清除内容
		int check(choice);    //检查语句

		switch(check-48)
		{
		case 1:
		    log_admin();   //登录，需密码验证
			break;

		case 0:
			exit(1);     //退出系统
			break;

		default:
			cout<<"\n\t您的操作有误，请重新选择(0→1):  ";
			fflush(stdin);
			goto choice;
		}
	}



	void admin_menu()   //管理菜单
	{
		system("cls");
		cout<<"\t   口口口口口口口口口口口口口口口口口口口口口口口口口口口口\n";
		cout<<"\t   口                                                    口\n";
		cout<<"\t   口****************系**统**管**理**界**面**************口\n";
		cout<<"\t   口                                                    口\n";
		cout<<"\t   口    1: 添加新的图书资料     2: 修改已有图书资料     口\n";
		cout<<"\t   口                                                    口\n";
		cout<<"\t   口    3: 删除已有图书资料     4: 查找已有图书资料     口\n";
		cout<<"\t   口                                                    口\n";
		cout<<"\t   口    5: 查看所有图书资料     6: 排序已有图书资料     口\n";
		cout<<"\t   口                                                    口\n";
		cout<<"\t   口    7: 写入指定位置TXT      8：返回系统登录界面     口\n";
		cout<<"\t   口                                                    口\n";
		cout<<"\t   口    0: 退出图书管理系统                             口\n";
		cout<<"\t   口                                                    口\n";
		cout<<"\t   口                                                    口\n";
		cout<<"\t   口口口口口口口口口口口口口口口口口口口口口口口口口口口口\n";
		cout<<"\n\t请选择您需要的服务序号： ";
		choice: cin>>choice;
		cin.ignore();
		int check(choice);    //检查语句

		switch(check-48)
			{
		    case 1:   //添加图书
			    addBook();
				bm.~BookManage();
			    break;

		    case 2:   //修改图书
				reviseBook();
				bm.~BookManage();
				break;

			case 3:   //删除图书
				delBook();
				bm.~BookManage();
				break;

			case 4:   //查找图书
				absearch_menu();
				break;

			case 5:   //查看全部图书
				{
				bm.show_bookhead();
				for(int j=0;j<bm.length;j++)
				{
				bm.show_book(j);
				}
				cout<<"\n\t显示完毕!";
				system("pause");
				admin_menu();
				break;
				}

			case 6:
				{
                bm.sort_book(bm.books);
                bm.show_bookhead();
                for(int j=0;j<bm.length;j++){
                    bm.show_book(j);
                    }
                    cout<<"\n\t显示完毕!";
                    system("pause");
                    admin_menu();
                    break;

				}

			case 7:
				{
                cout<<"讲程序保存在当前目录下，名为：书籍信息.txt"<<endl;
				bm.writePerson(bm.books);
				cout<<"请稍后...系统正在处理中..."<<endl;
				_sleep(1000);
				cout<<"生成成功！请前往程序所在目录查询。即将返回主菜单！"<<endl;
				_sleep(1000);
				admin_menu();
				}

			case 8:  //返回系统登录界面
				system("cls");
			    log_menu();

		    case 0:  //退出系统
			    exit(1);
				break;

		    default:
			    cout<<"\n\t您的操作有误，请重新选择(0→8):  ";
				fflush(stdin);
				goto choice;

			}
	}



	void absearch_menu()    //查找书籍菜单
    {
		system("cls");
        cout<<"\t\t\t※※※※※※※※※※※※※※※※口\n";
		cout<<"\t\t\t口                              口\n";
        cout<<"\t\t\t口****书**籍**查**找**界**面****口\n";
        cout<<"\t\t\t口                              口\n";
        cout<<"\t\t\t口       1: 按 编号查找         口\n";
        cout<<"\t\t\t口                              口\n";
        cout<<"\t\t\t口       2: 按 书名查找         口\n";
        cout<<"\t\t\t口                              口\n";
        cout<<"\t\t\t口       3: 按 作者查找         口\n";
		cout<<"\t\t\t口                              口\n";
        cout<<"\t\t\t口       4: 按 日期查找         口\n";
		cout<<"\t\t\t口                              口\n";
        cout<<"\t\t\t口       5: 按 超期查找         口\n";
        cout<<"\t\t\t口                              口\n";
        cout<<"\t\t\t口       6: 返 回 上 级         口\n";
        cout<<"\t\t\t口                              口\n";
        cout<<"\t\t\t口       0: 退 出 系 统         口\n";
		cout<<"\t\t\t口                              口\n";
        cout<<"\t\t\t口口口口口口口口口口口口口口口口口\n";

		char bsc;  //book search choice

		cout<<"\n\t请输入您需要的服务序号： ";
        cin>>bsc;
        cin.ignore();
 		int check(bsc);    //检查语句

		switch(check-48)
		{
          case 1:
               bnu_search();
			   break;

          case 2:
               bna_search();
			   break;

          case 3:
               bau_search();
			   break;

		  case 4:
               bd_search();
			   break;

		  case 5:
               bc_search();
			   break;

          case 6:
               admin_menu();
			   break;

          case 0:
                exit(1);

          default:
                cout<<"\n\t操作有误，请重新选择<0→6>";
				fflush(stdin);
				break;
		}
    }


	void log_admin()   //密码登陆 ///////////////////////////////////////////////////////
	{
		cout<<"\n\t请输入登陆密码:";
		int key;
		cin>>key;

		if( key==1234)
		{
			cout<<"\n\t登录成功!\n\n\t";
			system("pause");
			admin_menu();   //操作菜单
		}
		else
		{
		cout<<"\n\t登录失败!原因是密码错误!\n";
		cout<<"\n\t请选择 <1:返回上一级菜单  0:退出系统>     ";
		cin>>choice;
		cin.ignore();
		int check(choice);    //检查语句

		switch(check-48)
		{
		case 1:
			cout<<"\n\t请稍后，界面即将刷新...\n";
			_sleep(200);
			system("cls");
			log_menu();
			break;

		case 0:
			exit(1);
			break;

		default:
			cout<<"\n\t操作有误，请重新选择(0/1)";
		}
		}
	}

	void rn_search()   //按姓名查找函数
    {
        char rn[10];  //reader name
        cout<<"\n\t请输入您的姓名：";
        cin>>rn;
        int index=bm.rn_search(rn);

		if(index>=0)
		{
			bm.show_bookhead();
            bm.show_book(index);
        }
		else
        cout<<"\n\t对不起，系统无您的借阅记录!";
		cout<<"\n\t";
		system("pause");
		absearch_menu();
    }

	void bnu_search()   //按书号查找函数
    {
        char bnu[10];
        cout<<"\n\t请输入您要查找的书号：";
        cin>>bnu;
        int index=bm.bnu_search(bnu);

		if(index>=0)
		{
			bm.show_bookhead();
            bm.show_book(index);
        }
		else
        cout<<"\n\t对不起，系统无该书籍记录!";
		cout<<"\n\t";
		system("pause");
		absearch_menu();
    }

     void bna_search()   //按书名查找函数
    {
        cout<<"\n\t请输入您要查找的书名："<<endl;
        char bna[20];
        cin>>bna;
        int index=bm.bna_search(bna);

		if(index>=0)
		{
			bm.show_bookhead();
            bm.show_book(index);
        }
		else
        cout<<"\n\t对不起，系统无该书籍记录!";
		cout<<"\n\t";
		system("pause");
		absearch_menu();
    }

     void bau_search()   //按作者查找函数
    {
        cout<<"\n\t请输入您要查找的作者："<<endl;
        char bau[10];
		cin>>bau;
		int index=bm.bau_search(bau);

		if(index>=0)
		{
			bm.show_bookhead();
            bm.show_book(index);
		}
		else
        cout<<"\n\t对不起，系统无该书籍记录!";
		cout<<"\n\t";
		system("pause");
		absearch_menu();
    }

	 void bd_search()   //按借阅日期查找函数
    {
        char bd[10];
        cout<<"\n\t请输入您要查找的借出日期：";
        cin>>bd;
        int index=bm.bd_search(bd);

		if(index>=0)
		{
			bm.show_bookhead();
            bm.show_book(index);
        }
		else
        cout<<"\n\t对不起，系统无该借阅记录!";
		cout<<"\n\t";
		system("pause");
		absearch_menu();
    }

	 void bc_search()   //按超期天数查找函数
    {
        char bc[10];
        cout<<"\n\t请输入您要查找超期多久的书籍：";
        cin>>bc;
		int index=bm.bc_search(bc);

        if(index>=0)
		{
			bm.show_bookhead();
			bm.show_book(index);
		}
        else
            cout<<"\n\t对不起，系统无该书籍记录!";
		cout<<"\n\t";
		system("pause");
		absearch_menu();
    }

	void addBook()   //添加新的书籍信息函数
	{
	 char numb[10];   //书号
	 char nameb[20];   //书名
	 char authorb[10]; //作者
	 char namer[10];        //借阅人
	 char daysb[10];        //借出日期
   	 char chaob[10];        //超期天数
     Book book;       //书籍结构体对象book
	input1:cout<<"\n\t请输入新的书号:";
     cin>>numb;
     int index=bm.bnu_search(numb);

     if(index==-1)
	 {
		 cout<<"\n\t系统目前尚无该书记录，您可以继续操作!\n";
		 cout<<"\n\t请输入新书书名：";
         cin>>nameb;
         cout<<"\n\t请输入新书作者：";
         cin>>authorb;
		 cout<<"\n\t请输入借阅人：";
         cin>>namer;
		 cout<<"\n\t请输入借出日期：";
         cin>>daysb;
		 cout<<"\n\t请输入超期天数：";
         cin>>chaob;
         book.set_bnum(numb);
         book.set_bname(nameb);
         book.set_bauthor(authorb);
		 book.set_rname(namer);
		 book.set_bdays(daysb);
		 book.set_bchao(chaob);
         bm.add(book);
         cout<<"\n\t恭喜您!新书资料录入成功!";
     }

     else
	 {
		 cout<<"\n\t对不起，该书号纪录已存在!请重新输入!";
		 goto input1;
	 }

	 system("pause");
	 admin_menu();
	}

	void reviseBook()     //修改书籍函数
    {
        char numb[10];
        char nameb[20];
		char authorb[10];
		char namer[10];        //借阅人
		char daysb[10];        //借出日期
   		char chaob[10];        //超期天数
        Book book;

        int index=-1;
		input2: cout<<"\n\t请输入您要修改书籍的书号:";
        cin>>numb;
        index=bm.bnu_search(numb);
        if(index==-1)
        {
            cout<<"\n\t对不起，您输入的书号不存在，请重新输入!"<<endl;
			goto input2;
            return;
        }

            cout<<"\n\t请输入更改后的书名：";
            cin>>nameb;
            cout<<"\n\t请输入更改后的作者：";
            cin>>authorb;
			cout<<"\n\t请输入更改后的借阅人：";
            cin>>namer;
			cout<<"\n\t请输入更改后的借出日期：";
            cin>>chaob;
			cout<<"\n\t请输入更改后的超期时间：";
            cin>>authorb;

            book.set_bnum(numb);
            book.set_bname(nameb);
            book.set_bauthor(authorb);
			book.set_rname(namer);
			book.set_bdays(daysb);
			book.set_bchao(chaob);
            bm.revise(book,index);

            cout<<"\n\t恭喜您!书籍资料修改成功!";

		system("pause");
		admin_menu();
    }
	void delBook()    //删除书籍函数
    {
        char numb[10];

		cout<<"\n\t请输入您要删除书籍的书号：";
        cin>>numb;
        int index=bm.bnu_search(numb);         //  定义一个index 用来接收 对象bm的bnu_search函数的返回值
        if(index>=0)
        {
            cout<<"\n\t您确定要删除该书记录吗(y/n)    ";
            char y;
            cin>>y;
            if(y=='y'||y=='Y')
            {
                bm.deleteBook(index);
                cout<<"\n\t删除成功!";
            }
            else
                cout<<"\n\t删除取消!";
            }
        else
            cout<<"\n\t对不起，系统没有该图书记录!";
		system("pause");
		admin_menu();
    }
};



//********主函数********
int main()
{
	system("color f5");
	system("chcp 65001");
	Menu menu;  //定义菜单结构体对象menu
	cout<<"\t\t\t       当前日期：";system("DATE  [/T]");
	cout<<"\t\t\t       当前时间：   ";system("TIME  [/T]");
	cout<<"\n\t\t\t   ★ 欢 ";
	_sleep(200);
	cout<<"★ 迎 ";
	_sleep(200);
	cout<<"★ 进 ";
	_sleep(200);
	cout<<"★ 入 ★\n\n";

	menu.log_menu();
	return 0;
}
