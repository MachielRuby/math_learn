1、异或有关
void swap(int a,int b)
{
	a = a^b;
	b = a^b;
	a = b^a;
}

2、单链表翻转
while(!q)
{
	q = q->next;
}
q->next要保存到Node * p = q->next;然后进行其他操作总之。