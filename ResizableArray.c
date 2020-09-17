#include "ResizableArray.h"
#include "stdlib.h"
#include "stdio.h"




/**

  * @brief   	����
  * @Name	 	Array array_create(int init_size)
  * @param   	None
  * @retval  	None
  * @Author  	ZCJ
  * @Date 	 	2020/04/23 Create
  * @Version 	1.0 2020/04/23  
  * @Note  
  
  **/
void add(List* pList , int number)
{
	//add to linked-list
	Node *p  = (Node*)malloc(sizeof(Node)) ; 
	p->value = number ;
	p->next =  NULL; 
	
	//find the last 
	Node *last = pList->head ;
	if(last)
	{
		while( last->next )
		{
			last= last->next;		
		}
		last->next = p ;
	}
	else
	{
		pList->head = p ; 
	}
}

void print_list( List *pList)
{
	Node *p;
	for( p = list.head ; p ; p = p->next )
	{
		printf("%d\t" , p->value );
		
	}
	printf("\n");
}



int main(int argc, char * * argv)
{
	List list ;
	int number;
	list.head = list.tail = NULL ;
	do
	{
		scanf("%d" , &number ) ;
		if( number != -1 )
		{
			head = add(&list , number ) ;		
		}	
	}
	while (number != -1 ) ;

	Node *p;
	for( p = list.head ; p ; p = p->next )
	{
		printf("%d\t" , p->value );
		
	}
	printf("\n");


	scanf("%d" , &number);
	Node *p ; 
	int isFound = 0; 
	for( p = list.head ; p ; p = p->next )
	{
		if( p->value == number )
		{
			printf("zhaodaole\n");
			isFound = 1 ;
			break;
		}	
	}
	if( !isFound)
	{
		prinft("û���ҵ�\n");
	}

//any pointer at the left of -> must be checked  
	Node *q ;  
	for( q= NULL, p = list.head ; p ;q=p ,  p = p->next )
	{
		if( p->value == number )
		{
			if(q)
			{
				q->next = p->next ;			
			}
			else
			{
				list.head = p->next ;			
			}
			

			free(p);
			break;
		}	
	}

	for( p=head ; p ;p=q)
	{
		q = p->next ;
		free(p) ; 
	}
	
	return 0 ;
}


/**
 	�ɱ������ʹ��
  * @brief   	����һ������
  * @Name	 	Array array_create(int init_size)
  * @param   	None
  * @retval  	None
  * @Author  	ZCJ
  * @Date 	 	2020/04/23 Create
  * @Version 	1.0 2020/04/23  
  * @Note  
  **/
Array array_create(int init_size)
{
	Array a;
	a.size = init_size ;    
	a.array = (int*)malloc( sizeof(int)*a.size );    

	return a;
}

/**

  * @brief   	���տռ�
  * @Name	 	void array_free(Array *a)
  * @param   	None
  * @retval  	None
  * @Author  	ZCJ
  * @Date 	 	2020/04/23 Create
  * @Version 	1.0 2020/04/23  
  * @Note  
  
  **/
void array_free(Array *a)
{
	free( a->array );
	a->array = NULL;
	a->size  = 0 ;
}

/**

  * @brief   	Ŀǰ�ж��ٿռ������
  * @Name	 	int array_size(const Array *a)
  * @param   	None
  * @retval  	None
  * @Author  	ZCJ
  * @Date 	 	2020/04/23 Create
  * @Version 	1.0 2020/04/23  
  * @Note  
  
  **/
int array_size(const Array *a)
{
	return a->size ;
}

/**

  * @brief   	�������鵱��ĳ����Ԫ:���Զ�Ҳ����д������������ֵҲ��������ֵ��46 // ���������±�ĵ�ַ
  * @Name	 	int* array_at(Array *a ,int index)
  * @param   	None
  * @retval  	None
  * @Author  	ZCJ
  * @Date 	 	2020/04/23 Create
  * @Version 	1.0 2020/04/23  
  * @Note  
  
  **/
int* array_at(Array *a ,int index)
{	
	if( index >= a->size )
	{// // ����������±�������鳤�ȣ� ����������
		array_inflate( a, ( index/BLOCK_SIZE + 1 )* BLOCK_SIZE - a->size  ) ;	//array_inflate( a, index - a->size + 1 ) ;	
	}
	return &( a->array[index] ) ;
}

/**

  * @brief   	��������
  * @Name	 	void array_inflate(Array *a , int more_size)
  * @param   	None
  * @retval  	None
  * @Author  	ZCJ
  * @Date 	 	2020/04/23 Create
  * @Version 	1.0 2020/04/23  
  * @Note  
  
  **/
void array_inflate(Array *a , int more_size)
{
	int *p = (int*)malloc( sizeof(int)*( a->size + more_size )) ;
	int i;
	for( i=0 ; i<a->size ; i++ )
	{
		p[i] = a->array[i] ;	
	}
	/*  forѭ����memcpy����  memcpy(p , a->array , a->size);*/
	free(a->array);
	a->array = p ;
	a->size += more_size ;
}
/**

  * @brief   	��������д�붫��
  * @Name	 	void array_inflate(Array *a , int more_size)
  * @param   	None
  * @retval  	None
  * @Author  	ZCJ
  * @Date 	 	2020/04/23 Create
  * @Version 	1.0 2020/04/23  
  * @Note  
  
  **/
void array_set(Array *a , int index ,int value )
{
    a->array[index] = value ;
}
/*
int Array_test( )
{
	Array a = array_create(5);
	printf("array_size==%d\n" , array_size(&a)); //== 100
	*array_at(&a, 0) = 10 ;
//	array_set(&a, 0, 10);	
	printf("array_at==%d\n" , *array_at(&a, 0)); // == 10
	int cnt = 0;
	int number =0 ;
	
	while(cnt != 50 )
	{
//		scanf("%d" , &number);
		cnt++;
		if( cnt != 50 )
			*array_at(&a, cnt ) = cnt*2 ;
		printf("array_at%d==%d\n" ,cnt , *array_at(&a, cnt)); // == 10
	}

	array_free(&a);

	return 0 ;
}
}
*/
/*
 int main(int argc, char const *argv[])
73 {
74     Array a = array_create(100);
75     printf("%d\n", array_size(&a));
76     *array_at(&a, 0) = 10;
77     printf("%d\n", *array_at(&a, 0));
78     int number;
79     int cnt = 0;
80     while (number != -1){
81         scanf("%d", &number);
82         if (number != -1){
83             *array_at(&a, cnt) = number;
84             cnt ++;
85         }
86     }
87     array_free(&a);
88 
89     return 0;
90 }
*/

/*

int main()
{
	Array a;
	a=array_creat(3);
	//array_free(&a);
	*array_at(&a, 0) = 10;
	*array_at(&a, 1) = 20;
	*array_at(&a, 2) = 30;
	*array_at(&a, 3) = 40;
	*array_at(&a, 4) = 50;
	*array_at(&a, 5) = 60;
 
	//array_set(&a, 0, 10);
	//array_set(&a, 1, 20);
	//array_set(&a, 2, 30);
 
	//array_inflate(&a, 2);
 
	//array_set(&a, 3, 40);
	//array_set(&a, 4, 50);
	for (int i = 0; i < 4; i++)
	{
		printf("%d ", a.array[i]);
	}
	//printf("%d\n", array_size(&a));
	array_free(&a);
	//Array *pa= array_creat(NULL, 3);
	//pa = array_creat(&a, 3);
	//array_free(&a);
	//array_free(&a);
	system("pause");
	return 0;
}
��������������������������������
��Ȩ����������ΪCSDN������melody_jae����ԭ�����£���ѭCC 4.0 BY-SA��ȨЭ�飬ת���븽��ԭ�ĳ������Ӽ���������
ԭ�����ӣ�https://blog.csdn.net/melody_1016/article/details/81948809
*/