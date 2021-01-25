#pragma once
#include "predefine.h"
struct GLNode
{
	int tag;
	union//union联合体，下面两部分只能取其一；要么取char;要么取结构体ptr,ptr包括两个指针hp,tp 
	{
		char afom;//原子结点的值
		struct
		{
			GLNode *hp;
			GLNode *tp;
		}ptr;
	};
};




