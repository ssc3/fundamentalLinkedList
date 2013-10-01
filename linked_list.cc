#include "stdio.h"
#include "stdlib.h"

class Node {
    public:
        int key;
        Node* next;

        Node() {};
        Node(int _key)
        {
            key = _key;
            next = NULL;
        }
        ~Node() {};
};

class List {
    public:
        List()
        {
            head = NULL;
            tail = NULL;
        }

        ~List();

        Node* CreateNode(int key)
        {
            Node* new_node = new Node(key);
            return new_node;
        }

        Node* GetHead()
        {
            if (head == NULL)
                return NULL;
            else
                return head;
        }

        bool CheckHead()
        {
            if (head == NULL)
            {
                printf ("No head\n");
                return false;
            }
            return true;
        }

        Node* GetTail()
        {
            if (tail == NULL)
                return NULL;
            else
                return tail;
        }

        bool CheckTail()
        {
            if (tail == NULL)
            {
                printf ("No Tail\n");
                return false;
            }
            return true;
        }

        // Inserts at the tail of list
        // by traversing the whole list
        void Insert(Node* temp_head, int key)
        {
            if (temp_head == NULL)
            {
                Node* temp_node = CreateNode(key);
                head = temp_node;
                tail = temp_node;
                return;
            }

            if (temp_head->next == NULL)
            {
                Node* temp_node = CreateNode(key);
                temp_head->next = temp_node;
                tail = temp_node;
                return;
            }
            Insert(temp_head->next, key);
        }

        // Insert directly at the tail of the list
        // using Tail pointer
        void FastInsert(int key)
        {
            if (!CheckTail())
                return;

            Node* new_node = new Node(key);
            tail->next = new_node;
        }



        // different from Insert
        // Insert inserts at tail
        // Push inserts at head
        void Push(int key)
        {

            if (!CheckHead())
                return;

            Node* new_node = new Node(key);
            new_node->next = head;
            head = new_node;
        }

        // Remove the head
        void Pop()
        {
            if (!CheckHead())
                return;

            Node* temp_node = head;
            head = head->next;
            delete temp_node;
        }

        void ChangeHead(Node* node, int key)
        {
            if (!CheckHead())
                return;

            if (node->key == key)
            {
                head = node;
                return;
            }

            ChangeHead(node->next, key);
        }

        Node* GetNth(int node_num)
        {
            if (!CheckHead())
                return NULL;

            if (node_num > num_nodes - 1)
            {
                printf("Can't find %dth node. Only %d nodes in list\n", node_num, num_nodes);
                return NULL;
            }

            Node* temp_node = head;
            for (int i = 0; i < node_num-1; i++)
            { 
                temp_node = temp_node->next;

            }
            return temp_node;
        }
            

        void PrintFullList()
        {
            if (!CheckHead())
                return;

            Node* temp_node = new Node();
            temp_node = head;

            while (temp_node != NULL)
            {
                if (temp_node->next != NULL)
                {
                    printf("key = %d, next = %d\n", temp_node->key, temp_node->next->key);
                
                    temp_node = temp_node->next;
                }
                else
                {
                    printf("key = %d\n", temp_node->key);
                    printf("*****\n");
                    temp_node = NULL;
                }

            }
        }

        void PrintLength()
        {
            if (!CheckHead())
                return;

            int count = 0;
            Node* temp_node = head;

            while (temp_node != NULL)
            {
                count++;
                if (temp_node->next != NULL)
                    temp_node = temp_node->next;

                else 
                    break;
            }
            num_nodes = count;
            printf("Length of list = %d\n", count);
        }

        void DeleteList()
        {
            if(!CheckHead())
                return;

            Node* temp_node = head;

            while (temp_node != NULL)
            {
                if (temp_node->next == NULL)
                {
                    delete temp_node;
                    head = NULL;
                    tail = NULL;
                    return;
                }

                Node* temp2 = temp_node->next;
                delete temp_node;
                temp_node = temp2;
            }
        }


    private:
        Node* head;
        Node* tail;
        int num_nodes;
};


int main(int argc, char* argv[])
{
    List* my_list = new List();

    printf("Argc = %d\n", argc);

    int key_array[10];

    while (argc > 1) {
        printf("Argv[%d] = %s\n", argc, argv[argc - 1]);

        //inserting nodes
        my_list->Insert(my_list->GetHead(), atoi(argv[argc - 1]));

        argc--;
    }

    my_list->PrintFullList();    

    my_list->ChangeHead(my_list->GetHead(), 2);
    my_list->PrintFullList();    

    my_list->Push(7);
    my_list->PrintFullList();    

    my_list->FastInsert(9);
    my_list->PrintFullList();    
    my_list->PrintLength();

    Node* local_node = my_list->GetNth(3);
    printf("Got %dth node. Key = %d\n", 3, local_node->key);
    printf("*****\n");

    my_list->Pop();
    my_list->PrintFullList();    

    my_list->DeleteList();
    my_list->PrintFullList();    







    return 0;
}

