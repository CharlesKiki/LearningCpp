#include<string>
#include<map>
#include<time.h>
/*这里包含需要定义额值*/
typedef struct Value_
{
	//键值 
	std::string key; 
	//这里用一个int的value代替 
	uint32_t value;
	//创建时间 
	uint64_t create_time;
}Value;

//定义缓存数据结构，缓存为全局对象：
typedef std::map<std::string,Value_> MyCache;
MyCache my_cache;


/*设置缓存时间, 设置为5分钟*/
uint64_t expire_time = 300;

//数据库查询方法
int QueryDB(const std::string& key, Value& value)
{
	return 0;
}

//
int SetValue(const Value& value_t, Value& value) 
{
	return 0;
}

//缓存的查询函数:
int QueryMyCache(const std::string& key, Value& value)
{
	if (key.empty()) return -1;
	//缓存迭代器
	auto cache_iter = my_cache.find(key);

	/*缓存里面存在值*/
	if (cache_iter != my_cache.end())	
	{
		const Value& value_t = cache_iter->second;
		/*判断缓存是否已过期*/
		if ((time(NULL) - value_t.create_time) < expire_time)
		{ 
			/*未过期则返回值*/
			SetValue(value_t, value); return 0;
		}
	}
	/*已过期或不存在缓存中,通过DB去查询需要的Value*/
	if (0 != QueryDB(key, value)) { /*DB查询失效*/ return -2; } /*设置时间，并放入存储*/
	value.create_time = time(NULL);
	my_cache[key] = value;
	return 0;
}

int main() 
{
	return 0;
}

