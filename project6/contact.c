/*
 * Contact Management program-Project 6
 * 	Griffin Mack
 * 	Prof. Zhang
 *
 * Function Calls-addContact
 * 		  addInformation
 * 		  printContact
 * 		  count
 * 		  print
 * 		  addContactOrdered
 * 		  addInformationOrdered
 * 		  removeContact
 * 		  removeInformation
 */
#include "contact.h" 

//	   1. Make sure a contact by that name does not exist (print an error message and exit if it exists)
Contact* addContact(Contact *myContacts, char *contactName) {
	Contact *ptr=myContacts;
	while(ptr!=NULL) {
		if(strcmp(ptr->name,contactName)==0) {
			printf("NAME ALREADY EXISTS\n");
			return myContacts; //EXIT PROGRAM HERE
		}
		ptr=ptr->next;
	}
	Contact *newTerm = (Contact *) malloc(sizeof(Contact));
	newTerm->name=contactName;
	newTerm->information=NULL;
	newTerm->next = myContacts;
	return newTerm;
}


// adds a new piece of information to the specified contact
//   1. Make sure a contact by that name exists (so you can add information to it)
//   2. If the informational item already exists, update the information's value to the new value

void addInformation(Contact *myContacts, char *contactName, char *infoName, char *infoValue) {
	Contact *check=myContacts;
	Contact *ptr=myContacts;
	int flag=0;
	while(check!=NULL) {
	if(strcmp(check->name,contactName)!=0) check=check->next;
		else flag=1;
	if(flag==1) break; 
	}
	if(check==NULL) {
		printf("CONTACT DOES NOT EXIST");
		return;
	}
	while(strcmp(ptr->name,contactName)!=0) {
		ptr=ptr->next;
	}
	flag=0;
	Info *check2= ptr->information;
	Info *newcontactinfo=(Info*) malloc(sizeof(Info));
	while(check2!=NULL) {
		if(strcmp(check2->name,infoName)==0) {
			printf("Info name exists----updating...\n");
			check2->value=infoValue;
			return;
		}
		check2=check2->next;
	}
	newcontactinfo->name= infoName;
	newcontactinfo->value=infoValue;
	newcontactinfo->next=NULL;
	
	if(ptr->information==NULL){ 
		ptr->information=newcontactinfo;
		return;
	}
	for(Info *ptr2=ptr->information;ptr2!=NULL;ptr2=ptr2->next) {
		if(ptr2->next==NULL) {
			ptr2->next=newcontactinfo;
			return;
		}
	}	
	return;		
}


// prints all the information for a given contact
//	1. Make sure a contact with that name exists
//	2. Print the name of the contact
//	3. print all the informational items <name|value> associated with that contact
void printContact(Contact *myContacts, char *contactName) {
	Contact *ptr=myContacts;
	int flag=0;
	while(ptr!=NULL) {
	if(strcmp(ptr->name,contactName)!=0) ptr=ptr->next;
		else flag=1;
	if(flag==1) break; 
	}
	if(ptr==NULL) {
		printf("CONTACT DOES NOT EXIST");
		return;
	}
	printf("%s\n",ptr->name);
	Info *contact=ptr->information;
	while(contact!=NULL) {
			printf("	<%s|%s>\n",contact->name,contact->value);
			contact=contact->next;
		}
	
	
	
	return;}


// returns the size of a given contact list
//	Iterate through the contact list to count the number of contacts, return that count
int count(Contact *myContacts) {
	int count=0;
	Contact *ptr=myContacts;
	while(ptr!=NULL) {
		count++;
		ptr=ptr->next;}
	return count;
}


// prints all your contacts
//	For each contact
//	   a.  Print the name of the contact
//	   b.  Print all the <information name|information value> pairs in that contact
//	Note: this code can call other functions as needed
void print(Contact *myContacts) {
	Contact *ptr=myContacts;
	while(ptr!=NULL) {
	printf("%s\n",ptr->name);
	Info *contact=ptr->information;
	while(contact!=NULL) {
			printf("	<%s|%s>\n\n",contact->name,contact->value);
			contact=contact->next;
		}
	ptr=ptr->next;
}
}
// add a new contact (in alphabetical order)
//	1. Make sure a contact by that name does not exist 
//	2. Add a new contact with that name (add-in-order)
Contact *addContactOrdered(Contact *myContacts, char *contactName) {
	Contact *ptr=myContacts;
	while(ptr!=NULL) {
		if(strcmp(ptr->name,contactName)==0) {
			printf("NAME ALREADY EXISTS\n");
			return myContacts; //EXIT PROGRAM HERE
		}
		ptr=ptr->next;
	}
	Contact *newTerm = (Contact *) malloc(sizeof(Contact));
	newTerm->name=contactName;
	newTerm->information=NULL;
	newTerm->next = NULL;
	if(myContacts==NULL) {
		return newTerm;
	}
	if(strcmp(contactName,myContacts->name)<0) {
		newTerm->next=myContacts;
		return newTerm;
	}
	for(Contact *cur=myContacts;cur!=NULL;cur=cur->next) {
		//GOES HERE IF LARGER(a->c)
		if(cur->next==NULL) {
			cur->next=newTerm;
			return myContacts;
		}
		if(strcmp(contactName,cur->next->name)<0) {
			newTerm->next=cur->next;
			cur->next=newTerm;
			return myContacts;
		}
	}
	return NULL;
}


// adds a new info to the specified contact (in alphabetical order)
//	1. Make sure a contact by that name exists (so you can add an info to it)
//	2. If the informational item already exists, update the item (replace its value with the new value)
//	3. Otherwise, add the new info to the contact (add-in-order)
void addInformationOrdered(Contact *myContacts, char *contactName, char *infoName, char *infoValue) {
	Contact *check=myContacts;
	Contact *ptr=myContacts;
	int flag=0;
	while(check!=NULL) {
	if(strcmp(check->name,contactName)!=0) check=check->next;
		else flag=1;
	if(flag==1) break; 
	}
	if(check==NULL) {
		printf("CONTACT DOES NOT EXIST");
		return;
	}
	while(strcmp(ptr->name,contactName)!=0) {
		ptr=ptr->next;
	}
	flag=0;
	Info *check2= ptr->information;
	Info *newcontactinfo=(Info*) malloc(sizeof(Info));
	while(check2!=NULL) {
		if(strcmp(check2->name,infoName)==0) {
			printf("Info name exists----updating...\n");
			check2->value=infoValue;
			return;
		}
		check2=check2->next;
	}
	newcontactinfo->name= infoName;
	newcontactinfo->value=infoValue;
	newcontactinfo->next=NULL;
	
	if(ptr->information==NULL){ 
		ptr->information=newcontactinfo;
		return;
	}
	if(strcmp(infoName,ptr->information->name)<0) {
		newcontactinfo->next=ptr->information;
		ptr->information=newcontactinfo;
		return;
	}
	for(Info *ptr2=ptr->information;ptr2!=NULL;ptr2=ptr2->next) {
		if(ptr2->next==NULL) {
			ptr2->next=newcontactinfo;
			return;
		}
		if(strcmp(infoName,ptr2->next->name)<0){
			newcontactinfo->next=ptr2->next;
			ptr2->next=newcontactinfo;
			return;
		}
	}	
	return;		
}


// remove information from a contact
//	1. Make sure a contact with that name exists
//	2. Make sure the informational item exists in that contact
//	3. Remove that piece of information from the contact
void removeInformation(Contact *myContacts, char *contactName, char *infoName) {
	Contact *check=myContacts;
	Contact *ptr=myContacts;
	int flag=0;
	while(check!=NULL) {
	if(strcmp(check->name,contactName)!=0) check=check->next;
		else flag=1;
	if(flag==1) break; 
	}
	if(check==NULL) {
		printf("CONTACT DOES NOT EXIST");
		return;
	}
	flag=0;
	while(strcmp(ptr->name,contactName)!=0) {
		ptr=ptr->next;
	}
Info *ptr2=ptr->information;
Info *check2=ptr->information;
	
	
	
	
	while(check2!=NULL) {
	if(strcmp(check2->name,infoName)!=0) check2=check2->next;
		else flag=1;
	if(flag==1) break; 
	}
	if(check2==NULL) {
		printf("INFO DOES NOT EXIST");
		return;
	}
	if(strcmp(infoName,ptr->information->name)==0) {
		Info *del=ptr2;
		ptr->information=ptr->information->next;
		free(del);
	}



	return;
}

// remove a contact (and all the informational items for that contact)
//	1. Make sure a contact with that name exists
//	2. Remove that contact 
Contact *removeContact(Contact *myContacts, char *contactName) {
	Contact *check=myContacts;
	int flag=0;
	while(check!=NULL) {
	if(strcmp(check->name,contactName)!=0) check=check->next;
		else flag=1;
	if(flag==1) break; 
	}
	if(check==NULL) {
		printf("CONTACT DOES NOT EXIST");
		return myContacts;
	}
	if(strcmp(myContacts->name,contactName)==0) {
		Contact *del=myContacts;
		myContacts=myContacts->next;
		free(del);
		return myContacts;
	}
	for(Contact *cur=myContacts;cur!=NULL;cur=cur->next) {
		if(strcmp(cur->next->name,contactName)==0) {
			Contact *del=cur->next;
			cur->next=cur->next->next;
			free(del);
			return myContacts;
		}
	}

	
	return NULL;
}
