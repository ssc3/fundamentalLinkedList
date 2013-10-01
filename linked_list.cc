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
                    temp_node = NULL;
                }

            }
        }


    private:
        Node* head;
        Node* tail;
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








    return 0;
}

