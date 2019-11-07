#include "set.h"

/*****************************************************
* Implementation of the member functions             *
******************************************************/

//Default constructor
Set::Set ()
	: counter(0)
{
	//IMPLEMENT before HA session on week 15
	head = new Node(0, nullptr, nullptr);
	tail = new Node(0, nullptr, head);
	head->next = tail;
}


//Conversion constructor
Set::Set (int n)
	: counter(0)
{
    head = new Node(0, nullptr, nullptr);
	tail = new Node(0, nullptr, head);
	head->next = tail;
	insert(tail, n);
}


//Constructor to create a Set from a sorted array
Set::Set (int a[], int n) // a is sorted
	: counter(0)
{
	//IMPLEMENT before HA session on week 15
     head = new Node(0, nullptr, nullptr);
	 tail = new Node(0, nullptr, head);
	 head->next = tail;
	 for(int i = 0; i < n; ++i){
        insert(tail,a[i]);
	 }

}


Set::~Set()
{
	//IMPLEMENT before HA session on week 15
	Node *node = head;
	while(node){
        Node *temp = node;
        node = node->next;
        delete temp;
	}
    counter = 0;
}

void Set::insert(Node *p, int val)
{
    Node* newNode = new Node(val, p, p->prev);
    p->prev = p->prev->next = newNode;
    counter++;
}

//Copy constructor
Set::Set (const Set& source)
{
	//IMPLEMENT before HA session on week 15
    head = new Node(0, nullptr, nullptr);
	tail = new Node(0, nullptr, head);
	head->next = tail;
	Node *temp = source.head->next;

    while(temp != source.tail){
        insert(tail,temp->value);
        temp = temp->next;
    }

}


//Copy-and-swap assignment operator
//Note that call-by-value is used for source parameter
Set& Set::operator=(Set source)
{
	//IMPLEMENT before HA session on week 15
    swap(this->counter, source.counter);
	swap(this->head, source.head);
	swap(this->tail, source.tail);


	return *this;
}


//Test whether a set is empty
bool Set::_empty () const
{
	return (!counter);
}


//Test set membership
bool Set::is_member (int val) const
{
	//IMPLEMENT before HA session on week 15
    Node* temp = head;

	while (temp && temp->value != val) // medans värdet i en Node inte är lika med x
        {
            temp = temp->next; // gå till nästa node
        }
	if (!temp)
	{
		return false;
	}
	else
	{
		return true;
	}
}



//Return number of elements in the set
unsigned Set::cardinality() const
{
	return counter;
}


//Make the set empty
void Set::make_empty()
{
    delete this;
    head = new Node(0, nullptr, nullptr);
	tail = new Node(0, nullptr, head);
	head->next = tail;
	counter = 0;
	//IMPLEMENT before HA session on week 15
}

//Modify *this such that it becomes the union of *this with Set S
//Add to *this all elements in Set S (repeated elements are not allowed)
Set& Set::operator+=(const Set& S)
{
	//IMPLEMENT before HA session on week 15
    Node *temp = head->next;
    Node *Stemp = S.head->next;
    Node* newNode;
    while(temp != tail && Stemp != S.tail){
        if(temp->value > Stemp->value){
            newNode = new Node(Stemp->value, temp, temp->prev);
            temp->prev = temp->prev->next = newNode;
            Stemp = Stemp->next;

        }
        else if(temp->value < Stemp->value){
            temp = temp->next;
        }
        else {
            Stemp = Stemp->next;
        }

    }
    while(Stemp != S.tail){
        newNode = new Node(Stemp->value, temp, temp->prev);
        temp->prev = temp->prev->next = newNode;
        Stemp = Stemp->next;
    }

    return *this;
}


//Modify *this such that it becomes the intersection of *this with Set S
Set& Set::operator*=(const Set& S)
{

    Node *tempt = this->head->next;


    while(tempt != this->tail){
        if(!S.is_member(tempt->value)){
                       tempt->prev = tempt->prev->next = tempt->next;
                       this->counter--;
                    }
                tempt = tempt->next;

        }
    return *this;

}


//Modify *this such that it becomes the Set difference between Set *this and Set S
Set& Set::operator-=(const Set& S)
{
	//IMPLEMENT


    Node *tempt = this->head->next;

    while(tempt != this->tail){
        if(S.is_member(tempt->value)){
                       tempt->prev = tempt->prev->next = tempt->next;
                       this->counter--;
                    }
                tempt = tempt->next;
        }

 return *this;
}

//Return true, if the set is a subset of b, otherwise false
//a <= b iff every member of a is a member of b
bool Set::operator<=(const Set& b) const
{
    Node *tempt = this->head->next;

    while(tempt != this->tail){
     if(!b.is_member(tempt->value)){
        return false;
     }
        tempt = tempt->next;
    }
	return true;
}


//Return true, if the set is equal to set b
//a == b, iff a <= b and b <= a
bool Set::operator==(const Set& b) const
{
	if(*this <= b && b <= *this){
        return true;
	}

	return false; //remove this line
}


//Return true, if the set is different from set b
//a == b, iff a <= b and b <= a
bool Set::operator!=(const Set& b) const
{
	if(*this <= b && b <= *this){
        return false;
	}

	return true; //remove this line
}


//Return true, if the set is a strict subset of S, otherwise false
//a == b, iff a <= b but not b <= a
bool Set::operator<(const Set& b) const
{
	if((*this <= b) && !(b <= *this)){
        return true;
	}

	return false; //remove this line
}


// Overloaded operator<<
ostream& operator<<(ostream& os, const Set& b)
{
	if (b._empty())
		os << "Set is empty!" << endl;
	else
	{
		auto temp = b.head->next;

		os << "{ ";
		while (temp != b.tail)
		{
			os << temp->value << " ";
			temp = temp->next;
		}

		os << "}" << endl;
	}

	return os;
}


