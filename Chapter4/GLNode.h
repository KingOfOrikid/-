#pragma once
#include "predefine.h"
struct GLNode
{
	int tag;
	union//union�����壬����������ֻ��ȡ��һ��Ҫôȡchar;Ҫôȡ�ṹ��ptr,ptr��������ָ��hp,tp 
	{
		char afom;//ԭ�ӽ���ֵ
		struct
		{
			GLNode *hp;
			GLNode *tp;
		}ptr;
	};
};




