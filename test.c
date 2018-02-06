#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>


//定义数据 
struct information_strct
	{
       int number_ID;
       char name[32];
       char password[32];
       char title[32];
       char explanation_[1024];
    }information_account[1024]={0};
int total=0;    
//定义函数们 
void open(int i);
void make(int i);
void god();
void god_2();
void god_3();
void god_4();
void god_5();
int  find_(char a[],char b[]);
void log_in();
void account();
void add_account();
void del_account();
void change_account();
void look_account();
void open_account();
void save();
void change_password();
void look_for_account();
char* make_lock(char d[]);
char* open_lock(char d[]);
void read_in();
void read_to(); 

//主函数 
int main()
{	
    god();
    god_4(); 
    system("cls");
	system("color 02");
    log_in();
    int temp,b=1; 
    while(b==1)
		{   
			system("cls");        
			god();
            god_2();
			printf("\n\n             |---------------------------------------你想干什么-----------------------------------------|\n");
            printf("             |                                                                                          |\n");
			printf("             |                                                                                          |\n");
			printf("             |                                    （1）修改验证密码                                     |\n");
			printf("             |                                                                                          |\n");
			printf("             |                                                                                          |\n");
			printf("             |                                    （2）管理帐户                                         |\n");
			printf("             |                                                                                          |\n");
			printf("             |                                                                                          |\n");
			printf("             |                                    （3）退出                                             |\n");
			printf("             |                                                                                          |\n");
			printf("             |                                                                                          |\n");
			printf("             |------------------------------------------------------------------------------------------|\n");
			printf("\n------------------------->>>");
			scanf("%d",&temp);  
			system("cls");
			switch(temp)
			{
				  case 1:change_password();break;
				  case 2:account();break;
				  case 3:god_5(&b);break;
				  default:printf("输入错误请重新输入！"); 
			}
		}
return 0;		
}


//登录函数
 
void log_in()
	{
    FILE *f;
    f=fopen("D:\\c code\\lock","rb");
    if(f==NULL)change_password();
	f = fopen("D:\\c code\\lock", "rb");
	system("cls");
	printf("\n\n    ****************************欢迎使用个人账户管理系统**********************\n\n");
    god_2();
	printf("\n\n    ****************************作者：物联01班——周丰************************\n\n\n\n");
	printf("\n\n    **************************** 《《请按提示输入》》 ************************\n\n\n\n");
	printf("                               |----------------------|\n");
    printf("                               | 请输入管理员的密码： |\n");
	printf("                               |----------------------|\n");
	printf("                             -->>>");
    int i,n,m=1;
    char seal[255]={0},temp[255]={0};
    fread(&temp,sizeof(temp),1,f);
    fclose(f);
    strcpy(temp,open_lock(temp));
    while(m==1)
		{
			 	m=1;
	    		for(i=0;(seal[i]=getch())!='\r'&&(seal[i])>=47;i++)
				{
					printf("*");
				} 
			
			    int c[255],d[255];
			    n=strlen(temp);
			    for(i=0;i<n;i++)
			{
		    	srand(seal[i]);
		    	c[i]=rand()%100;
				srand(temp[i]);
				d[i]=rand()%100;
			}	
				for(i=0;i<n;i++)
				if(c[i]!=d[i])break;
				if(i!=n)
			{
				printf("\n ——————————密码错误，请重新输入:");
				printf("\n                     ----->>>");
				
				m=1;
			}	
				if(i==n)
			{
				printf("\n密码正确\n");
				printf("\n");
				
				m=0;
			}
	    }
    }
    
//改密函数    
void change_password()
	{
	FILE *f;
	f=fopen("D:\\c code\\lock","wb");
	char ch_password[255]={0};
	god_2();
	printf("\n");
	printf("                           |--------------------------|\n");
    printf("                           |输入一个你觉得安全的密码：|\n");
	printf("                           |--------------------------|\n");
	printf("\n                          -->>>");
	int i; 
	for(i=0;(ch_password[i]=getch())!='\r'&&(ch_password[i])>=47;i++)
	{
	printf("*");
	}
	strcpy(ch_password,make_lock(ch_password));
	fwrite(&ch_password,sizeof(ch_password),1,f);
	fclose(f);
	printf("修改成功");
	printf("\n");
    }
    

//功能函数 
void account()
	{
	    int a,b=1;
	    while(b==1)
			{
		    b=1;
		    system("cls");
		    god();
		    printf("\n\n\n");
		    printf("          *       |-----------------------------------------------------------------|\n");
		    printf("          *       |                           主面板                                |\n");	
		    printf("          *       |                                                                 |\n");			
			printf("          *       |-----------------------------------------------------------------|\n");
			printf("          *       |                                                                 |\n");			
			printf("          *       |                                                                 |\n");
			printf("          *       |         1.添加     2.删除      3.修改      4.查看               |\n");			
			printf("          *       |                                                                 |\n");
			printf("          *       |-----------------------------------------------------------------|\n");
			printf("          *       |                                                                 |\n");
		    printf("          *       |         5.查询     6.打开       7.保存/另存                     |\n");
		    printf("          *       |                                                                 |\n");
		    printf("          *       |-----------------------------------------------------------------|\n");
			printf("          *       |                                                                 |\n");		    
			printf("          *       |         8.格式化用户数据        9.返回上一级菜单                |\n");
			printf("          *       |                                                                 |\n");
			printf("          *       |-----------------------------------------------------------------|\n");
			printf("\n                        ----------------------->>>");
		    scanf("%d",&a);
		    system("cls");
		    switch(a) {
		              case 1:add_account();break;
		              case 2:del_account();break;
		              case 3:change_account();break;
		              case 4:look_account();break;
		              case 5:look_for_account();break;
		              case 6:open_account();break;
		              case 7:save();break;
		              case 8:total=0,read_to();break; 
		              case 9: b=0;break;
		              default:printf("输入错误请重新输入！"); 
              		  }
             }
   }
 //增加用户 
void add_account()
	{
	read_in();
	for(;total<1023;) 
	{   
		god_3();                     
		information_account[total].number_ID=total;
		 		printf("\n请输入标题：\n___--->>>");
		scanf("%s",&information_account[total].title);
		strcpy(information_account[total].title,make_lock(information_account[total].title));
				printf("\n请输入名字：\n___--->>>");
		scanf("%s",&information_account[total].name);
		strcpy(information_account[total].name,make_lock(information_account[total].name));
				printf("\n请输入密码：\n___--->>>");
		scanf("%s",&information_account[total].password);
		strcpy(information_account[total].password,make_lock(information_account[total].password));
				printf("\n请输入说明：\n___--->>>");
		scanf("%s",&information_account[total].explanation_);
		strcpy(information_account[total].explanation_,make_lock(information_account[total].explanation_));
                printf("\n请输入是否继续输入 1 》继续 ：\n___--->>>\n\n");
        total++;
        if(getch()!='1')break; 
		

    }
    
	read_to();
    }

//删除用户	
void del_account()
	{
	look_account();
	read_in();
	if(total<=0)
	{ 
	printf("\n没有可删除的数据");
	Sleep(2000);
	} 
	if(total>0)
	{ 
	int i;
    printf("\n现在你的管理系统里有%d个账户，请输入删除的ID号：",total);
    printf("\n_--->>>");
    scanf("%d",&i);
	
		
 
    for(;i<=total;i++)
    {
     information_account[i-1]=information_account[i];
    }
    --total;
    read_to();    
    god_4();
    printf("成功删除"); 
    }
	}





	
 //改变账户信息
 
 
 
 
 
 
 
  
void change_account()
	{
	int q,i,n;
	char c[32]; 
	read_in();
	system("cls");
	printf("\n\n\n\n"); 
	printf("\n             >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   ");
	printf("\n            * 你希望按什么方式查找你的账户信息：      *");
	printf("\n            *  (1).标题    (2).id号     (3)模糊查找   *");
	printf("\n             >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   ");
	printf("\n\n");
	printf("\n --*********>>>>   ");
	scanf("%d",&n);
  if(n==1)
	{
	printf("\n现在你的管理系统里有%d个账户，请输入修改的账户标题号：",total);
    printf("\n_--->>>");
    scanf("%s",&c);
    for(i=0;i<total;)
    {
    open(i);
	if(strcmp(information_account[i].title,c)==0)
	{
		system("cls");	
		printf("\n 你选择了这个账户---》ID:%-4d账户标题:%-15s姓名:%-15s密码:%-15s说明:%-15s\n",i+1,information_account[i].title,information_account[i].name,information_account[i].password,information_account[i].explanation_);
	    printf("\n请输入修改的项目：(1)账户标题(2)姓名 (3)密码 (4)说明 (5)退出\n___------->>>",total);
		scanf("%d",&q);
		switch(q)
		{
		 	case 1: 
				{
				printf("\n请输入标题：\n___--->>>");
				scanf("%s",&information_account[i].title);				
				}
				break;
			case 2:
				{	
				printf("\n请输入名字：\n___--->>>");
				scanf("%s",&information_account[i].name);
				}
				break;
		 	case 3:
				{
				printf("\n请输入密码：\n___--->>>");
				scanf("%s",&information_account[i].password);
				}
				break;		
	 		case 4:
				{
				printf("\n请输入说明：\n___--->>>");
				scanf("%s",&information_account[i].explanation_);
				}		
	        	break;
	  		case 5:
	  		    break;
		 	default:
		 	
			 	{
			 	printf("输入有误");
	            Sleep(1500);	
			 	}
			 	
	
		} 
	    }
	    
		make(i);
		i++; 
	    }
	    read_to();	
		}
	if(n==2)
		{
		printf("\n现在你的管理系统里有%d个账户，请输入修改的ID号：",total);
	    scanf("%d",&i);
	    i--; 
	    open(i); 
		printf("\n ID:%-4d账户标题:%-15s姓名:%-15s密码:%-15s说明:%-15s\n",i+1,information_account[i].title,information_account[i].name,information_account[i].password,information_account[i].explanation_);
	    printf("\n请输入修改的项目：(0)账户标题(1)姓名 (2)密码 (3)说明 (4)退出\n___------->>>",total);
		scanf("%d",&q);
		i++;
		switch(q)
		{
			case 0: 
				{
				printf("\n请输入标题：\n___--->>>");
				scanf("%s",&information_account[i-1].title);
	
				
				}
				break;
			case(1):
				{
	
				printf("\n请输入名字：\n___--->>>");
				scanf("%s",&information_account[i-1].name);
				}
				break;
			case(2):
				{
				printf("\n请输入密码：\n___--->>>");
				scanf("%s",&information_account[i-1].password);
				
				}
				break;		
	 		case(3):
				{
				printf("\n请输入说明：\n___--->>>");
				scanf("%s",&information_account[i-1].explanation_);
				
				}		
	        	break;
	  		case(4):
	  		    break;
		 	default:
		 	{
			 	printf("输入有误");
			    Sleep(2000);	
		 	}
		 	
	 	
	    }
	    
		}
	if(n==3)
		{
	    printf("\n现在你的管理系统里有%d个账户，请输入修改的大概标题号：",total);
	    printf("\n_--->>>");
	    scanf("%s",c);
	    for(i=0;i<total;)
	    {
	    open(i);
		if(find_(information_account[i].title,c)==1)
		   {
				
			printf("\n ID:%-4d账户标题:%-15s姓名:%-15s密码:%-15s说明:%-15s\n",i+1,information_account[i].title,information_account[i].name,information_account[i].password,information_account[i].explanation_);
				 	
		
		    } 
   
		    
		make(i);
		i++; 
        }
        system("pause");
        read_to();			
		}
		else 
		printf("**************************|||\n错了");
    
	} 

//查看账户 
void look_account()
	{
	
	system("cls");
	int i;
	read_in();
	printf("\n********************下面是你的%d个账户信息*************************************************",total);
	for(i=0;i<total;)
	{
	 open(i);
	 printf("\n ID:%-4d账户标题:%-15s姓名:%-15s密码:%-15s说明:%-15s\n",i+1,information_account[i].title,information_account[i].name,information_account[i].password,information_account[i].explanation_);
	 i++; 
	}
	system("pause");
	 
	} 

void look_for_account()
	{
	int q,i,n;
	char c[32]; 
	read_in();
	system("cls");
	printf("\n\n\n\n"); 
	printf("\n             >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   ");
	printf("\n            * 你希望按什么方式查找你的账户信息：      *");
	printf("\n            *  (1).标题    (2).id号     (3)模糊查找   *");
	printf("\n             >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   ");
	printf("\n\n");
	printf("\n --*********>>>>   ");
	scanf("%d",&n);
    
	
	if(n==1)
	{
	printf("\n现在你的管理系统里有%d个账户，请输入查找的账户标题号：",total);
    printf("\n_--->>>");
    scanf("%s",&c);
    for(i=0;i<total;)
    {
    open(i);
	if(strcmp(information_account[i].title,c)==0)
	{
		system("cls");	
		printf("\n ID:%-4d账户标题:%-15s姓名:%-15s密码:%-15s说明:%-15s\n",i+1,information_account[i].title,information_account[i].name,information_account[i].password,information_account[i].explanation_);
		system("pause");
	}
	make(i);
	i++;
    }
    
	}
	
	if(n==2)
	{
		printf("\n现在你的管理系统里有%d个账户，请输入查找的ID号：",total);
		printf("\n_--->>>");
	    scanf("%d",&i);
	    i--; 
	    open(i); 
		printf("\n ID:%-4d账户标题:%-15s姓名:%-15s密码:%-15s说明:%-15s\n",i+1,information_account[i].title,information_account[i].name,information_account[i].password,information_account[i].explanation_);
		make(i);
		system("pause");
    }
	    
	
	if(n==3)
		{
	    printf("\n现在你的管理系统里有%d个账户，请输入查找的大概标题号：",total);
	    printf("\n_--->>>");
	    scanf("%s",c);
	    for(i=0;i<total;)
	    {
	    open(i);
		if(find_(information_account[i].title,c)==1||find_(information_account[i].name,c)==1||find_(information_account[i].explanation_,c)==1)
  		{		
			printf("\n ID:%-4d账户标题:%-15s姓名:%-15s密码:%-15s说明:%-15s\n",i+1,information_account[i].title,information_account[i].name,information_account[i].password,information_account[i].explanation_);
   		} 
   
		    
		make(i);
		i++; 
        }
        system("pause");
        			
		}
		else 
		printf("**************************|||\n错了");
    	}

 //打开账户   
void open_account()
	{
    look_account();
	}
//保存账户 
void save()
	{
	int w ;
	char path[40];	
      system("cls");
	  printf("\n请选择》》》\n\n\n\n\n");
     printf("                ._________________.\n"); 
     printf("                | _______________ | \n"); 
     printf("                | I  1>保存     I | \n"); 
     printf("                | I             I | \n"); 
     printf("                | I  2>另存     I | \n"); 
     printf("                | I             I | \n"); 
     printf("                | I_____________I | \n"); 
     printf("                !_________________! \n"); 
     printf("                   ._[_______]_. \n"); 
     printf("               .___|___________|___. \n");
     printf("               |::: ____           | \n");
     printf("               |    ~~~~ [CD-ROM]  | \n");
     printf("               !___________________! \n");
	 printf("_________________ >>>>");
	 scanf("%d",&w);
	 if(w==2)
	 {
	 	read_in();
		printf("\n请输入一个你希望保存的地址\n");
		printf("_________________ >>>>");
		scanf("%s",&path);
  		int i=0;
	   	FILE * fp;  
		fp=fopen(path,"wb");
 		fwrite(&total,sizeof(int),1,fp);
 		for(i=0;i<total;i++)
 		{
 		fwrite(&information_account[i],sizeof(information_account[i]),1,fp);
 		}
 		fclose(fp);
		w=1;     
	}
	printf("保存成功");
	god_4();   
	}
    
//读取到数组
void read_in()
{
   int i=0;
   FILE * fp;  
   fp=fopen("D:\\c code\\id","rb");
   if(fp==NULL)
   {
   fp=fopen("D:\\c code\\id","wb");
   fwrite(&i,sizeof(i),1,fp);
   }
   fread(&total,sizeof(int),1,fp);
   for(i=0;i<total;i++)
   {
     fread(&information_account[i],sizeof(information_account[i]),1,fp);
   }   
   fclose(fp);     
                        
                        
      
} 


//写入到文件
void read_to() 
{
   int i=0;
   FILE * fp;  
   fp=fopen("D:\\c code\\id","wb");
   fwrite(&total,sizeof(int),1,fp);
   for(i=0;i<total;i++)
   {
     fwrite(&information_account[i],sizeof(information_account[i]),1,fp);
   }
   fclose(fp);    
} 
  
 //加密与解密

char* make_lock(char d[])
{
	char x='a';
	int n,i;
	n=strlen(d);
	for(i=0;i<n;i++)d[i]=((d[i]<<4)&0xF0)+((d[i]>>4)&0x0F);   
	for(i=0;d[i]!='\0';i++)d[i]^=x;                           
	return d;
}
char* open_lock(char d[])
{
	char x='a';
	int i;
	for(i=0;d[i]!='\0';i++)d[i]^=x;
	for(i=0;d[i]!='\0';i++)d[i]=((d[i]<<4)&0xF0)+((d[i]>>4)&0x0F);
	return d;
}
//密数据
void open(int i)
{ 
strcpy(information_account[i].title,open_lock(information_account[i].title));
strcpy(information_account[i].name,open_lock(information_account[i].name));
strcpy(information_account[i].password,open_lock(information_account[i].password));
strcpy(information_account[i].explanation_,open_lock(information_account[i].explanation_));

}
void make(int i)
{ 
strcpy(information_account[i].title,make_lock(information_account[i].title));
strcpy(information_account[i].name,make_lock(information_account[i].name));
strcpy(information_account[i].password,make_lock(information_account[i].password));
strcpy(information_account[i].explanation_,make_lock(information_account[i].explanation_));

}

void god() 
{
system("color 06");    
printf("\n\n\n                                       |             \n");
      printf("                                   __\\--__|_            \n");
      printf("                   II=======OOOOO[/ ★02 ___|           \n");
      printf("                             _____\\______|/-----.       \n");
      printf("                           /____________________|       \n");
      printf("                            \\◎◎◎◎◎◎◎◎⊙/        \n");
      printf("                              ~~~~~~~~~~~~~~~~          \n");
      system("color 02");
}
void god_2() 
{
            system("color 03");    
        	printf("                          .----.                                .---.   \n");
        	printf("                         '---,  `.____________________________.'  _  `. \n");
        	printf("                              )   ____________________________   <_>  : \n");
        	printf("                         .---'  .'                            `.     .' \n");
        	printf("                          `----'                                `---'   \n");

}

void god_3()
{
     printf("                ._________________.\n"); 
     printf("                | _______________ | \n"); 
     printf("                | I             I | \n"); 
     printf("                | I             I | \n"); 
     printf("                | I             I | \n"); 
     printf("                | I             I | \n"); 
     printf("                | I_____________I | \n"); 
     printf("                !_________________! \n"); 
     printf("                   ._[_______]_. \n"); 
     printf("               .___|___________|___. \n");
     printf("               |::: ____           | \n");
     printf("               |    ~~~~ [CD-ROM]  | \n");
     printf("               !___________________! \n");
}

void god_4()
{ 
	printf("加载中......");
    int o;
    for(o=0;o<=100;o++)
    {
        Sleep(2);
        printf("\b\b\b%2d%%",o);
    }
    printf("完成");
} 

void god_5(int *p)
{
if(MessageBox(0,"确认要退出系统吗？","提示",MB_YESNO  )==IDYES)
{
printf("您选择退出，谢谢使用本系统\n");
printf("数据已全部保存在指定文件中");
*p=0;
}   	
}


int find_(char a[],char b[])
{

char *p=a,*q=b;
int flag=0;
for(;*(p+strlen(b)-1);p++)
{
for(q=b;*p==*q&&*q;p++,q++);
if(!*q)
{
flag=1;
break;
}
}
return flag;	
}
