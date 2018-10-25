#include <string>
#include "studentRoll.h"
#include "iostream"
#include "sstream"

StudentRoll::StudentRoll() {
  head = tail = NULL;
}

void StudentRoll::insertAtTail(const Student &s) {
  	Node* n = new Node;
	n -> s = new Student(s);
	//Node* n = new Student(s);

	if (head == NULL) {
		head = n;
	}
	if (tail == NULL) {
		tail = n;
		n->next =NULL;
	}
	else {
	tail->next = n;// STUB
	n->next = NULL;
	tail = n;
	}

	
}

std::string StudentRoll::toString() const {
	std::ostringstream oss;
	oss << "[";
	Node *n = head;
	while (n) {
		oss << n->s->toString();
		if (n != tail) oss << ",";
		n = n->next;
	}
	oss << "]";
	delete n;
	return oss.str();
}

StudentRoll::StudentRoll(const StudentRoll &orig) {
  // STUB
	head = NULL;
	tail = NULL;

	
  for (Node* n = orig.head; n; n = n->next) {
	insertAtTail(*n->s);
  }	

}

StudentRoll::~StudentRoll() {
	Node* current = head;
	Node* n;
	while (current != 0) {
			n = current->next;
			delete current->s;
			delete current;
			current = n;
		
	}
  // STUB

}

StudentRoll & StudentRoll::operator =(const StudentRoll &right ) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up 
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this) 
    return (*this);

  // TODO... Here is where there is code missing that you need to 
  // fill in...
  for (Node* n= right.head; n!= NULL; n = n->next) {

	  insertAtTail(*n->s);
  }

  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 
  
 }





