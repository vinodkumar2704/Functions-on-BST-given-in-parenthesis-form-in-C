//PARENTHESIS TO BINARY TREE AND PRINT THE COUSINS

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

struct node{
	struct node* left ;
	int key;
	//struct node* p;
	struct node* right;
	
};


struct stack{
	struct node* data;
	struct stack* next;
};

struct node* NewNode(int data){
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->key = data;
	node->left = NULL;
	node->right = NULL;
	return node;
	
}
struct node* input()
{
        char c;
        int d;
        scanf("%c",&c);
        scanf("%c",&c);
        if(scanf("%d",&d)==1)
        {
                struct node* t=NewNode(d);
                t->left = input();
                //if(t->left != NULL)t->left->p = t;
                t->right = input();
                //if(t->right != NULL)t->right->p = t;
     		scanf("%c",&c); 
        	scanf("%c",&c);
     		return t;
     	}
     	else{
     		scanf("%c",&c);
        	scanf("%c",&c);
     		return NULL;
        }
}
struct node* SEARCH(struct node* head,int k){
	if(head == NULL)return NULL;
	if(head->key == k)return head;
	if(head->key < k)return SEARCH(head->right,k);
	else return SEARCH(head->left,k);
}



struct node* PREDECESSOR(struct node* head,int k){
	struct node* temp = SEARCH(head,k);
	if(temp==NULL)return NULL;
	if(temp->left != NULL){
		temp = temp->left;
		while(temp->right != NULL){temp = temp->right;}
		return temp;
	}
	else if(temp->left == NULL){
		struct node* ptr = head;
		struct node* pre = NULL;
		while(ptr!=temp){
			if(ptr->key > k)ptr = ptr->left;
			else {pre = ptr;
			ptr = ptr->right;
			}
		}
		return pre;
	}
	else return NULL;
	
}
	
struct node* SUCCESSOR(struct node* head,int k){
	struct node* temp = SEARCH(head,k);
	if(temp == NULL)return NULL;
	if(temp->right!=NULL){
		temp = temp->right;
		
		while(temp->left != NULL)temp = temp->left;
		return temp;
	}
	else if(temp->right == NULL){
		struct node* ptr = head;
		struct node* suc = NULL;
		while(ptr!=temp){
			if(ptr->key < k)ptr = ptr->right;
			else{
				suc = ptr;
				ptr = ptr->left;
			}
		}
		return suc;
	}
	else return NULL;
	
}
void INORDER(struct node* head){
	if(head == NULL)return;
	INORDER(head->left);
	printf("%d ",head->key);
	INORDER(head->right);
}



struct stack* ADD(struct stack* s,struct node* root){
	struct stack* temp = (struct stack* )malloc(sizeof(struct stack));
	temp->data = root;
	temp->next = NULL;
	if(s == NULL){
	s= temp;
	return s;
	}
	temp->next=s;
	s=temp;
	return s;
	
}



int KLARGEST(struct node* head,int k){

	struct stack* s = NULL;
	
	while(1){
		while(head!= NULL){
			s = ADD(s,head);
			head = head->right;
			
		}
		if(s == NULL) break;
		head = s->data;
		s = s->next;
		if(--k == 0){
		if(head !=NULL)return head->key;
		else break;}
		head = head->left;
	
	}
	
	return -1;

}


	
int KSMALLEST(struct node* head,int k){
	
	struct stack* s = NULL;
	
	while(1){
		while(head != NULL){
			s = ADD(s,head);
			head= head->left;
		}
		if(s==NULL)break;
		head = s->data;
		s=s->next;
		if(--k == 0){
		if(head!= NULL)return head->key;
		else break;}
		head = head->right;
	
	}
	return -1;

}


void main(){
	
	struct node* head = input();
	char x;
	int k;
	while(1){
		scanf("%c",&x);
		if(x=='r'){
			scanf("%d",&k);
			struct node* pre = PREDECESSOR(head,k);
			if(pre == NULL)printf("-1\n");
			else printf("%d\n",pre->key);
		}
		if(x=='u'){
			scanf("%d",&k);
			struct node* suc = SUCCESSOR(head,k);
			if(suc == NULL)printf("-1\n");
			else printf("%d\n",suc->key);
		}
		if(x=='i'){INORDER(head);printf("\n");}
		if(x=='l'){
			scanf("%d",&k);
			int large = KLARGEST(head,k);
			printf("%d\n",large);
		}
		if(x=='s'){
			scanf("%d",&k);
			int small = KSMALLEST(head,k);
			printf("%d\n",small);
		}
		if(x=='e'){
		break;}
	}


}
