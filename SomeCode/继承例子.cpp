class person 
{
	public:
	void eat();
	string name;
	int age;
};

class worker 
{
	public:
	void eat();
	void work();
	string name;
	int age;
	int salary;
};

class worker :public person
{
	public:
	void work();
	int salary;
};

//public 继承方式 public person 基类
//clas worker 派生类 