#ifndef _ROLE_
#define _ROLE_
#include <string>
#include "cocos2d.h"
USING_NS_CC;
class Role : public Ref
{

public :
	Role(int id, std::string name);

	~Role();
	int role_id;
	std::string role_name;









};













#endif //_ROLE_
