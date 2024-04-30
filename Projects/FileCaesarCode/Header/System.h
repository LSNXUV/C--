
#include "package.h"


class System
{
    protected:
    //内容
    char content[1000];
    //密钥
    int key;

    public:

        void welcome();
        void menu();

        //写入文件
        void write();

        //查看当前文本字符串
        void view();

        //设置密钥
        void setkey();

        //加密系统
        void encrypt();
        //加密字符串
        char * encrypted(char content[1000]);
        //解密系统
        void decrypt();
        //解密字符串
        char * decrypted(char content[1000]);

        //保存到文件
        void SaveFile();

        //读取文件
        void ReadFile();

        //居中输出
        void Cprintf(string str);

        System();
        ~System();
};

System::System()
{
    //初始化
    ReadFile();

    //key默认为7
    key = 7;

}

System::~System()
{
   
    free(content);
    
    free(&key);
}
