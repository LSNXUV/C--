


typedef struct Node{
	int id;//学号 
	char name[50];//姓名 
	char sex[10];//性别 
	int ma,en,et,pc;//数英体机 
	int sum;//总分 
	int avr;
	
	struct Node *next;//指针域 
}node;

//以下为函数声明

//读取文件 
int readFile(node *L);

//保存文件
int saveFile(node *L);

// 主菜单界面
void welcome();

//增加学生信息
//界面 
void printAddStuInfo(node *L);
//功能 
void insertStuInfo(node *L,node e);

//删除学生信息
//界面 
void printDeleteStuInfo(node *L);
//逻辑功能 
void deleteStuInfo(node *pr);

//修改学生信息
void printFixStuInfo(node *L);

//查询学生信息
void printSearchStuInfo(node *L);

//按学号进行查找 
node * searchStuInfoById(int id,node *L);
//按姓名进行查找 
node * searchStuInfoByName(char name[],node *L);

//输出学生信息
void printStuInfo(node *L);

//退出程序
void goodBye();