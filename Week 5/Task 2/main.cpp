#include <iostream>

using namespace std;

//Nodes and lists use public data members for convenience
//This may make some software engineers froth at the mouth

class Node
{
public:
  int value; //This could really be any type
  Node* next;
  Node* prev;
  Node(int val){
    cout << "Node constructor!" << endl;
    this->value=val;
    this->next=(Node*)0;
    this->prev=(Node*)0;
  }
  ~Node(){
    cout << "Node destructor" << endl;
    cout << "I had the value "<<this->value << endl;
  }
};
class List
{

public:
  Node* head;
  Node* tail;

  List(){
    cout << "List Constructor!" << endl;
    this->head=0;
    this->tail=0;
  }
  ~List(){
    cout << "List destructor!" << endl;
    cout << "Todo: properly delete nodes..." << endl;
  }
  void insert(Node* n, Node* x){
    //Not actually perfect: how do we prepend to an existing list?
    if (n!=0){
      x->next=n->next;
      n->next=x;
      x->prev=n;
      if (x->next!=0)
        x->next->prev=x;
    }
    if (this->head==0){
      this->head=x;
      this->tail=x;
      x->prev=0;
      x->next=0;
    }else if (this->tail=n){
      this->tail=x;
    }
  }
  void deleteNode(Node* x)
  {
        //if the node we want to delete is the head...
        if (this->head == x)
        {
            //Whatever comes next in the list is the tail and points to null
            this->head=x->next;
            this->head->prev = nullptr;
        }
        //if the node we want to delete is the head...
        else if (this->tail == x)
        {
            //Whatever comes before in the list is the tail and points to null
            this->tail=x->prev;
            this->tail->next = nullptr;
        }
        else
        {
            //The before node points to the next node after x and vice versa
            x->prev->next=x->next;
            x->next->prev=x->prev;
        }
        delete x;
  }

  void display(){
    Node* i=this->head;
    cout << "List: " ;
    while(i!=0){
      cout << i->value << ",";
      i=i->next;
    }
    cout << endl;
  }
};

int main(int argc, char *argv[])
{
  List* l=new List();
  l->insert(0,new Node(4));
  l->insert(l->head,new Node(6));
  //Changed this one to tail, the insert was causing problems
  l->insert(l->tail,new Node(8));
  //Put it an extra insert just to make sure it was working
  l->insert(l->tail,new Node(10));
  l->display();
  l->deleteNode(l->head->next);
  l->display();
  delete l;
  return 0;
}
