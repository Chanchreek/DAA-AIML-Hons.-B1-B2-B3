#include <stdio.h>
#include <stdlib.h>


struct node{
    float coefficient ;
    int exponent ;
    struct node* link ;
};


struct node* insert (struct node* head , int co , int ex){
    
    struct node* temp ;
    struct node* newP = malloc(sizeof(struct node));
    newP -> coefficient = co ;
    newP -> exponent = ex ;
    newP -> link = NULL ;

    if(head == NULL || ex > head -> exponent){
        newP -> link = head ;
        head = newP ;
    }
    else{
        temp = head ;
        while(temp -> link != NULL && temp -> link -> exponent > ex)
            temp = temp -> link ;
        newP -> link = temp -> link ;
        temp -> link = newP ;    
    }
    return head ;
}


struct node* create(struct node* head){
    int n  , i , expo ;
    float coeff ;
    printf("Enter the number of terms : ");
    scanf("%d",&n);

    for(i = 0 ; i < n ; i++){
        printf("Enter the coefficient of term %d : ", i+1 );
        scanf("%f",&coeff);

        printf("Enter the exponent of term %d : ", i+1);
        scanf("%d",&expo); 
        head = insert(head , coeff , expo);
    }
    return head ;

}

void print(struct node* head){
    if(head == NULL )
        printf("No polynomial !");
    else{
        struct node* temp = head ;
        while(temp!=NULL){
            printf("(%.1fx^%d)",temp->coefficient,temp->exponent);
            temp = temp -> link ;

            if(temp!=NULL)
                printf(" + ");
            else
                printf("\n");

        }
    }    
}

void polyadd(struct node* head1 , struct node* head2){
    struct node* ptr1 = head1 ;
    struct node* ptr2 = head2 ;
    struct node* head3 = NULL ;
    while(ptr1 != NULL && ptr2 != NULL){
        if(ptr1 -> exponent == ptr2 -> exponent){
            head3 = insert(head3 , ptr1->coefficient + ptr2->coefficient , ptr1 -> exponent + ptr2 -> exponent);
            ptr1 = ptr1 -> link ;
            ptr2 = ptr2 -> link ;
        }
        else if(ptr1->exponent > ptr2 ->exponent){
            head3 = insert(head3 , ptr1 -> coefficient , ptr1 -> exponent);
            ptr1 = ptr1 -> link ;
        }
        else if(ptr1 -> exponent < ptr2 -> exponent){
            head3 = insert(head3 , ptr2 -> coefficient , ptr2 -> exponent);
            ptr2 = ptr2 -> link ;
        }

    }
    while(ptr1 != NULL){
        head3 = insert(head3 , ptr1 -> coefficient , ptr1 -> exponent);
        ptr1 = ptr1 -> link ;
    }
    while(ptr2 != NULL){
        head3 = insert(head3 , ptr2 -> coefficient , ptr2 -> exponent);
        ptr2 = ptr2 -> link ;
    }
    printf("Added polynomial is : "); 
    
    struct node* ptr3 = head3 ;
    struct node* temp = NULL ;
    while(ptr3->link != NULL){
        if(ptr3 ->exponent == ptr3 -> link -> exponent){
            ptr3 -> coefficient = ptr3->coefficient + ptr3 -> link -> coefficient ;
            temp = ptr3 -> link ;
            ptr3 -> link = ptr3 -> link -> link ;
            free(temp); temp = NULL ;
        }
        else{
        ptr3 = ptr3 -> link ;
        }    
    }
    print(head3);
}


void polymult(struct node* head1 , struct node* head2){
    struct node* ptr1 = head1 ;
    struct node* ptr2 = head2 ;
    struct node* head3 = NULL ;

    if(head1 == NULL || head2 == NULL){
        printf("The polynomials are empty\n");
        return ;
    }

    else{
        while(ptr1 != NULL){
            while(ptr2 != NULL){
                head3 = insert(head3 , ptr1 ->coefficient * ptr2 ->coefficient , ptr1 -> exponent + ptr2 ->exponent);
                ptr2 = ptr2 -> link ;
            }
            ptr1 = ptr1 -> link ;
            ptr2 = head2 ;
        }
        printf("MULTIPLICATION OF THE TWO IS \n ");
        print(head3);
    }    
    
}
int main(){
    struct node* head1 = NULL ;
    struct node* head2 = NULL ;
    printf("Enter the first polynomial \n");
    head1 = create(head1);
    printf("Enter the second polynomial \n");
    head2 = create(head2);

    // polyadd(head1 , head2) ;
    polymult(head1 , head2);
    return 0 ;
}