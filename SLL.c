#include "SLL.h"


Error_State_t CreateList(List_t **ListAddress)
{
	Error_State_t FunctionState = RET_OK;
	if(ListAddress != NULL)
	{
		List_t *ListPtr = (List_t*)malloc(sizeof(List_t));
		if(NULL != ListPtr)
		{
			ListPtr -> Head = NULL;
			ListPtr -> Size = 0;
			*ListAddress = ListPtr;
		}
		else
		{
			printf("The malloc() Failed to allocate the required size\n");
		}
	}
	else
	{
		FunctionState = RET_NULL_PTR;
	}
	return FunctionState;
}


 static Error_State_t List_Empty(List_t *List , List_State_t *ReturnValue)
{
	Error_State_t FunctionState = RET_OK;
	if(NULL!=List)
	{
		if(List->Size == 0)
		{
			*ReturnValue = LIST_EMPTY; 
		}
		else
		{
			*ReturnValue = LIST_NEMPTY;
		}
	}
	else
	{
		FunctionState = RET_NULL_PTR;
	}
	return FunctionState;
}

Error_State_t AddToFront(List_t *List,s32 Data)
{
	Error_State_t FunctionState = RET_OK;
	if(NULL != List)
	{
		Node_t *NodePtr = (Node_t*)malloc(sizeof(Node_t));
		if(NULL != NodePtr)
		{
			NodePtr -> Value = Data;
			NodePtr -> Next = List->Head;
			List->Head = NodePtr;
			List->Size++;
		}
		else
		{
			FunctionState = RET_NULL_PTR;
		}
	}
	else
	{
		FunctionState = RET_NULL_PTR;
	}
	return FunctionState;
}





Error_State_t RemoveFromFront(List_t *List, s32 *Ret_Data)
{
	Error_State_t FunctionState = RET_OK;
	List_State_t List_State = LIST_NEMPTY;
	Node_t *BufferPtr = NULL;
	if(NULL != List && NULL != Ret_Data)
	{
		List_Empty(List,&List_State);
		if(List_State == LIST_EMPTY)
		{
			printf("Sorry!! The List is EMPTY... \n");
		}
		else
		{
			*Ret_Data = List -> Head -> Value;
			BufferPtr = List-> Head;
			List -> Head = BufferPtr -> Next;
			free(BufferPtr);
			List -> Size--;
		}
	}
	else
	{
		FunctionState = RET_NULL_PTR;
	}
	return FunctionState;
}





Error_State_t AddToBack(List_t *List,s32 Data)
{
	Error_State_t FunctionState = RET_OK;
	Node_t *BufferPtr = NULL;
	if(NULL != List)
	{
		Node_t *NodePtr = (Node_t *)malloc(sizeof(Node_t));
		if(NodePtr != NULL)
		{
			NodePtr -> Value = Data;
			NodePtr -> Next	 = NULL;
			BufferPtr = List-> Head;
			if(BufferPtr==NULL)
			{
				List -> Head = NodePtr;
			}
			else
			{
				while(BufferPtr->Next != NULL)
				{
					BufferPtr = BufferPtr -> Next; 
				}
				BufferPtr -> Next = NodePtr;
			}
			List -> Size++;
			
		}
		else
		{
			FunctionState = RET_NULL_PTR;
		}
	}
	else
	{
		FunctionState = RET_NULL_PTR;
	}
	return FunctionState;
}





Error_State_t RemoveFromBack(List_t *List ,s32 *Ret_Data)
{
	Error_State_t FunctionState = RET_OK;
	List_State_t List_State = LIST_NEMPTY;
	Node_t *BufferPtr = NULL;
	if((NULL != List) && (NULL != Ret_Data))
	{
		List_Empty(List,&List_State);
		if(List_Empty == LIST_EMPTY)
		{
			printf("Sorry!! There is no data to Remove the List is EMPTY");
		}
		else
		{
			if(List->Head->Next == NULL)
			{
				*Ret_Data = List->Head->Value;
				free(List -> Head);
				List->Head = NULL;
			}
			else
			{
				BufferPtr = List->Head;
				while(BufferPtr->Next->Next != NULL)
				{
					BufferPtr = BufferPtr->Next;
				}
				*Ret_Data = BufferPtr->Next->Value;
				free(BufferPtr->Next);
				BufferPtr -> Next = NULL;
			}
			List->Size--;
		}
	}
	else
	{
		FunctionState = RET_NULL_PTR;
	}
	return FunctionState;
}



Error_State_t RemoveFromPosistion(List_t *List,s32 *Ret_Data,u8 Pos)
{
    Error_State_t FunctionState = RET_OK;
    List_State_t List_State = LIST_NEMPTY;
    Node_t *PreviousPos = NULL; //to store the address, previous the exact node which the user wants to remove
    Node_t *NextPos = NULL; //to store the address of the exact node which the user wants to remove
    //Node_t *BufferPtr = List->Head;
    if(NULL!=List&&NULL!=Ret_Data)
    {
        if(Pos > List->Size || Pos<1)
        {
            FunctionState = RET_NOK;
        }
        else
        {
            List_Empty(List,&List_State);
            if(List_State == LIST_EMPTY)
            {
                printf("Sorry!! The List is EMPTY\n");
            }
            else
            {
                //is the list have one node
                if(List->Head->Next == NULL)
                {
                    *Ret_Data = List -> Head -> Value;
                    free(List->Head);
                    List->Size--;
                }
                //if the user want to remove the 1st node in the list
                else if (Pos==1)
                {
                    if(RemoveFromFront(List,Ret_Data)!=RET_NULL_PTR){}
                    else
                    {
                        FunctionState = RET_NULL_PTR;
                    }
                }
                //if the user want to remove the last node in the list
                else if (Pos==List->Size)
                {
                    if(RemoveFromBack(List,Ret_Data)!=RET_NULL_PTR){}
                    else
                    {
                        FunctionState = RET_NULL_PTR;
                    }
                }
                //if the user want to remove certain node from the middle of the node
                else
                {
                    PreviousPos = List->Head;
                    for(int i = 1;i<Pos-1;i++)
                    {
                        PreviousPos = PreviousPos -> Next;
                    }
                    NextPos = PreviousPos->Next;
                    *Ret_Data = NextPos->Value;
                    PreviousPos->Next = NextPos->Next;
                    free(NextPos);
                    List->Size--;
                }
            }
        }

    }
    else
    {
        FunctionState = RET_NULL_PTR;
    }
    return FunctionState;
}




Error_State_t DisplayData(List_t *List)
{
    Error_State_t FunctionState = RET_OK;
    List_State_t List_State = LIST_NEMPTY;
    Node_t *BufferPtr = List->Head;
    if(NULL!=List)
    {
        List_Empty(List,&List_State);
        if(List_State == LIST_EMPTY)
        {
            printf("Sorry!! The list is EMPTY\n");
        }
        else
        {
            while(BufferPtr->Next != NULL)
            {
                printf("%d\n",BufferPtr->Value);
                BufferPtr = BufferPtr->Next;
            }
            printf("%d\n",BufferPtr->Value);
        }
    }
    else
    {
        FunctionState = RET_NULL_PTR;
    }
    return FunctionState;
}
