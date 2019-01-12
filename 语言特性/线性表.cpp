using namespace std;  
  
const int maxSize = 100;//定义线性表最大长度为100  
  
template<typename T> class Sqlist  
//C++ 标准来说，template<typename T> 用于基础数据类型，typename 指类型名，T 可以取 char int double 等
//tempate<typename T> 的 T 也可以取类。
//typename另外一个作用为：使用嵌套依赖类型 
{  
public:  
    void InitList();//初始化一个空表  
    bool ListEmpty();//判断线性表是否为空  
    void ClearList();//将线性表清空  
    bool GetElem(int location, T &element);//返回线性表中第i个值  
    int LocateElem(T element);//线性表中查找与e相等的元素，返回第一个与e相等元素在线性表中的序号，否则，返回0  
    bool ListInsert(int location, T element);//在线性表中的第i个位置插入新元素  
    bool ListDelete(int location, T &element);//删除线性表中第i个位置的元素，并返回其值  
    int ListLength();//返回线性表的长度  
private:  
    T *data;//线性表中的数据  
	//*data不是指针，而data才是指针，*data是表示data指针所指向的值
	//T*data表示一个形式参数，然后就可以在函数体内使用data这个指针变量了，这里扮演的角色就是类型为T的一个数组的首地址
    int length;//线性表的当前长度  
};  
  
//开始实现各成员函数  
template<typename T> void Sqlist<T>::InitList()  
{  
    data = new T[maxSize];//初始化一个空表  
    length = 0;  
}  
  
template<typename T> bool Sqlist<T>::ListEmpty()  
{  
    if(length == 0)  
        return true;  
    return false;  
}  
  
template<typename T> void Sqlist<T>::ClearList()  
{  
    data = NULL;  
    length = 0;  
}  
  
template<typename T> bool Sqlist<T>::GetElem(int location, T &element)  
{  
    if (location > length)  
    {  
        return false;//越界了  
    }  
    element = *(data + location - 1);  
    return true;  
}  
  
template<typename T> int Sqlist<T>::LocateElem(T element)  
{  
    for (int i = 0; i < length; i++)  
    {  
        if(*(data+i) == element)  
            return i+1;  
    }  
    return 0;  
}  
  
template<typename T> bool Sqlist<T>::ListInsert(int location, T element)  
{  
    if (location > (length + 1))  
        return false;  
    for (int i = length; i >= location; i--)  
    {  
        *(data + i) = *(data + i - 1);  
    }  
    *(data+location-1) = element;  
    length+=1;  
    return true;  
}  
  
template<typename T> bool Sqlist<T>::ListDelete(int location, T &element)  
{  
    if (location > length)  
    {  
        return false;  
    }  
    element = *(data + location - 1);  
    for (int i = location - 1; i < (length - 1); i++)  
    {  
        *(data + i) = *(data + i + 1);  
    }  
    length -= 1;  
    return true;  
}  
  
template<typename T> int Sqlist<T>::ListLength()  
{  
    return length;  
}  
  
int main()  
{  
    //实例化一个类  
    Sqlist<int> mySql;  
    //生成空表  
    mySql.InitList();  
    //往表中插入数据  
    mySql.ListInsert(1,5);  
    mySql.ListInsert(2,8);  
    mySql.ListInsert(3,2);  
    mySql.ListInsert(4,6);  
    mySql.ListInsert(5,15);  
    mySql.ListInsert(2,9);  
    //输出表的长度和表中数据  
    cout<<"插值后，表的当前长度为："<<mySql.ListLength()<<endl;  
    for (int i = 0; i < mySql.ListLength(); i++)  
    {  
        int element(0);  
        mySql.GetElem(i+1, element);  
        cout<<"表中第"<<(i+1)<<"个元素为"<<element<<endl;  
    }  
    //删除表中某个数据  
    int deleteLocation(0);  
    cout<<"请输入要删除的元素的位置：";  
    cin>>deleteLocation;  
    int deleteElement(0);  
    mySql.ListDelete(deleteLocation, deleteElement);  
    cout<<"删除了表中第"<<deleteLocation<<"个元素，该元素为："<<deleteElement<<endl;  
    //输出删除后表中的数据  
    for (int i = 0; i < mySql.ListLength(); i++)  
    {  
        int element(0);  
        mySql.GetElem(i+1, element);  
        cout<<"删除后的表中第"<<(i+1)<<"个元素为"<<element<<endl;  
    }  
    //查找表中数据  
    int searchElement(0);  
    cout<<"请输入要查找的元素的值：";  
    cin>>searchElement;  
    int searchLocation = mySql.LocateElem(searchElement);  
    if (!searchLocation)  
    {  
        cout<<"当前表中无此元素"<<endl;  
    }  
    else  
        cout<<"所要查找的元素位于表中第"<<searchLocation<<"个位置"<<endl;  
    //清空表  
    mySql.ClearList();  
    //判断表是否为空  
    if (mySql.ListEmpty())  
    {  
        cout<<"当前表为空表！"<<endl;  
    }  
    else  
        cout<<"当前表非空！"<<endl;  
}  


//后缀自加运算优先级高于*(指针)